#include "repo.h"

void    check_init(void)
{
    string   names[6] = {"git_url", "user", "default_commit_message", "colors", "default_perms", NULL};

    for (int i = 0; names[i] != NULL; i++) {
        if (fkey(names[i]) == NULL)
            error(TRUE, "Error : missing the \'%s\' key\n", names[i]);
    }
    for (int i = 0; names[i] != NULL; i++) {
        if (strlen(fkey(names[i])) == 0)
            error(TRUE, "Error : missing the \'%s\' value\n", names[i]);
    }
    
}

void    repo_init(int ac, array av)
{
    ac = ac;
    av = av;
}
