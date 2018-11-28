#include "repo.h"

void    repo_make(int ac, array av)
{
    if (ac < 3)
        error(TRUE, "TOO_FEW_ARGUMENTS\n");
    repo_create(ac, av);
    repo_set_perms(ac, av);
    repo_clone(ac, av);
}
