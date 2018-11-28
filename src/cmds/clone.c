 #include "repo.h"

void    repo_clone(int ac, array av)
{
    string  str = NULL;
    
    if (ac < 3)
        error(TRUE, "TOO_FEW_ARGUMENTS\n");
    str = fill_string(6, "git clone ", fkey("git_url"), ":/", fkey("user"), "/", av[2]);
    system(str);
    free(str);
}
