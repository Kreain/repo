#include "repo.h"

void    repo_set_perms(int ac, array av)
{
    string  cmd;
    
    if (ac < 3)
        error(TRUE, "TOO_FEW_ARGUMENTS\n");
    if (ac == 3)
        cmd = fill_string(4, "blih repository setacl ", av[2], " ", fkey("default_perms"));
    else if (ac == 4)
        cmd = fill_string(4, "blih repository setacl ", av[2], " ", av[3]);
    else if (ac == 5)
          cmd = fill_string(6, "blih repository setacl ", av[2], " ", av[3], " ", av[4]);
    system(cmd);
    free(cmd);
}

void    repo_get_perms(int ac, array av)
{
    string  cmd;
    
    if (ac < 3)
        error(TRUE, "TOO_FEW_ARGUMENTS\n");
    cmd = fill_string(2, "blih repository getacl ", av[2]);
    system(cmd);
    free(cmd);
}
