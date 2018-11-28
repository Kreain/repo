#include "repo.h"

bool    check_dirs(string repo)
{
    DIR         *dir;
    dirent_t    *dirent;

    dir = opendir(".");
    if (dir == NULL) {
        perror("");
        exit (STOP_FAILURE);
    }
    dirent = readdir(dir);
    while ((dirent = readdir(dir)) != NULL) {
        if (strcmp(repo, dirent->d_name) == 0)
            return (TRUE);
    }
    closedir(dir);
    return (FALSE);
}

void    display_perms(string repo)
{
    string  perms;
    bool    perms_exist = TRUE;
    FILE    *file;
    size_t  len = 0;
    string  line = NULL;

    perms = fill_string(2, "blih repository getacl ", repo);
    file = popen(perms, "r");
    while (getline(&line, &len, file) != -1) {
        if (strstr(line, "No ACLs") != NULL)
            perms_exist = FALSE;
    }
    free(line);
    pclose(file);
    printf("permissions:\n");
    if (perms_exist == TRUE)
        system(perms);
    else
        printf("%sNo permissions\n%s", c_red, c_normal);
    printf("\n");
    free(perms);
}

void    list_or_cat(string path)
{
    stat_t  statFile;
    string  cat;
    string  tree;

    if (lstat(path, &statFile) < 0)
        error(TRUE, "ERROR READING FILE/DIR");
    if ((statFile.st_mode & S_IFMT) == S_IFDIR) {
        tree = fill_string(2, "tree ", path);
        system(tree);
        free(tree);
    } else {
      cat = fill_string(2, "cat ", path);
      system(cat);
      free(cat);
    }
}

void    display_cat_file(array av)
{
    string  cmd;
    FILE    *file;
    size_t  len = 0;
    string  line = NULL;
    string  clone = NULL;
    string  delete;
    int     ret;
    bool    dir_exist = FALSE;

    if ((dir_exist = check_dirs(av[2])) == FALSE)
        clone = fill_string(6, "git clone --quiet ", fkey("git_url"), ":/", fkey("user"), "/", av[2]);
    delete = fill_string(2, "rm -rf ", av[2]);
    cmd = fill_string(4, "find ", av[2], " -not -path \'*/\\.*\' -iname ", av[3]);
    if (dir_exist == FALSE)
        system(clone);
    file = popen(cmd, "r");
    ret = getline(&line, &len, file);
    if (ret != -1) {
        line[strlen(line) - 1] = '\0';
        printf("Found file : %s\n\n", line);
        list_or_cat(line);
    } else
        printf("\'%s\' : No such file in \'%s\' directory\n", av[3], av[2]);
    pclose(file);
    free(line);
    if (dir_exist == FALSE)
        system(delete);
    if (dir_exist == FALSE) {
        free(clone);
        free(delete);
    }
}

void    repo_info(int ac, array av)
{
    string  clone = NULL;
    string  tree;
    string  delete;
    bool    dir_exist = FALSE;

    if (ac < 3)
        error(TRUE, "TOO_FEW_ARGUMENTS\n");
    if (ac == 3) {
        display_perms(av[2]);
        if ((dir_exist = check_dirs(av[2])) == FALSE)
            clone = fill_string(6, "git clone --quiet ", fkey("git_url"), ":/", fkey("user"), "/", av[2]);
        tree = fill_string(2, "tree ", av[2]);
        delete = fill_string(2, "rm -rf ", av[2]);
        if (dir_exist == FALSE)
            system(clone);
        system(tree);
        if (dir_exist == FALSE)
            system(delete);
        if (dir_exist == FALSE) {
            free(clone);
            free(delete);
        }
        free(tree);
    }
    if (ac > 3) {
        display_cat_file(av);
    }
}
