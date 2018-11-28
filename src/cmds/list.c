#include "repo.h"

void    free_list(array repos)
{
    for (int i = 0; repos[i] != NULL; i++)
        free(repos[i]);
    free(repos);
}

void    str_switch(array s1, array s2)
{
    string  temp;

    temp = *s1;
    *s1 = *s2;
    *s2 = temp;
}

int     is_smaller(string s1, string s2)
{
    int size1 = strlen(s1);
    int size2 = strlen(s2);
    int small = (size1 <= size2) ? size1 : size2;

    for (int i = 0; i != small; i++) {
        if (s1[i] < s2[i])
            return (1);
        if (s1[i] > s2[i])
            return (0);
    }
    return (0);
}

void    sort_alpha(array repos, int size)
{
    int min;

    for (int i = 0; i != size - 2; i++) {
        min = i;
        for (int j = i + 1; j != size - 1; j++) {
            if (is_smaller(repos[j], repos[min]))
                min = j;
        }
        if (min != i)
            str_switch(&repos[i], &repos[min]);
    }
}

void    repo_list_dir(string repo)
{
    FILE    *file;
    size_t  len = 0;
    string  line = NULL;
    array   repos = malloc(sizeof(string) * 1);
    int     i = 0;
    int     size = 1;

    repos[0] = NULL;
    file = popen("blih repository list", "r");
    while (getline(&line, &len, file) != -1) {
        if (line[0] != '\n') {
            line[strlen(line) - 1] = '\0';
            repos = realloc(repos, sizeof(string) * (size + 1));
            repos[i] = malloc(sizeof(char) * (strlen(line) + 1));
            repos[i][0] = '\0';
            repos[i] = strcat(repos[i], line);
            repos[i][strlen(line)] = '\0';
            repos[size] = NULL;
            i++;
            size++;
        }
    }
    pclose(file);
    sort_alpha(repos, size);
    if (repo != NULL)
        find_item(repos, repo);
    else {
        for (int i = 0; repos[i] != NULL; i++)
            printf("%s\n", repos[i]);
    }
    free_list(repos);
}

void    repo_list(int ac, array av)
{

    if (ac == 2)
        repo_list_dir(NULL);
    else
        repo_list_dir(av[2]);
}
