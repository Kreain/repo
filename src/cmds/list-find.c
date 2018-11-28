#include "repo.h"

void    find_item_alone(array repos, string repo)
{
    for (int i = 0; repos[i] != NULL; i++) {
        if (strcmp(repos[i], repo) == 0) {
            printf("%s\n", repos[i]);
            free_list(repos);
            free_keys();
            exit(STOP_SUCCESS);
        }
    }
    free_list(repos);
    error(TRUE, "Unable to find repository '%s'\n", repo);
}

void    find_item_multi(array repos, string repo)
{
    bool    found = FALSE;
    
    repo[strlen(repo) - 1] = '\0';
    for (int i = 0; repos[i] != NULL; i++) {
        if (strstr(repos[i], repo) != NULL && strstr(repos[i], repo) == &repos[i][0]) {
            printf("%s\n", repos[i]);
            found = TRUE;
        }
    }
    free_list(repos);
    if (found == FALSE)
        error(TRUE, "Unable to find a repository containing '%s'", repo);
}

void    find_item(array repos, string repo)
{
    if (strchar(repo, '!') == TRUE)
        find_item_multi(repos, repo);
    else
        find_item_alone(repos, repo);
}
