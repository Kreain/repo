#include "repo.h"

void    repo_delete(int ac, array av)
{
    string  str = NULL;

    if (ac < 3)
        error(TRUE, "TOO_FEW_ARGUMENTS\n");
    str = fill_string(2, "blih repository delete ", av[2]);
    system(str);
    free(str);
}
