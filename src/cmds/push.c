#include "repo.h"

array   get_files(int ac, array av)
{
    int     size = 0;
    array   files;
    
    for (int i = 2; i < ac; i++)
        size++;
    files = malloc(sizeof(string) * (size + 1));
    for (int i = 2; i != size + 2; i++) {
        files[i - 2] = malloc(sizeof(char) * (strlen(av[i]) + 1));
        files[i - 2] = strcpy(files[i - 2], av[i]);
    }
    files[size] = NULL;
    return (files);
}

string  ask_commit(void)
{
    string  message = malloc(sizeof(char) * MSG_SIZE);
    int     size;

    printf("Enter commit message:\n");
    fgets(message, MSG_SIZE, stdin);
    size = strlen(message);
    message[size - 1] = '\0';
    return (message);
}

void    repo_push(int ac, array av)
{
    string  str = NULL;
    string  add = "git add";
    string  push = "git push";
    string  message;
    array   files = NULL;

    if (ac == 2) {
        add = fill_string(3, add, " ", "--all");
        message = ask_commit();
        str = fill_string(3, "git commit -m '", message, "'");
    }
    if (ac > 2) {
        files = get_files(ac, av);
        for (int i = 0; files[i] != NULL; i++)
            add = fill_string(3, add, " ", files[i]);
        message = ask_commit();
        str = fill_string(3, "git commit -m '", message, "'");
    }
    system(add);
    system(str);
    system(push);
    free(message);
    free(add);
    free(str);
}

//repo push [commit message]

//git add --all
//git commit -m "message"
//git push
