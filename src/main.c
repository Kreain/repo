#include "repo.h"

int	find_function(string str)
{
    string  list[12] = {"create", "clone", "push", "--help", "delete", "remove", "list", "make", "setp", "getp", "info", "init"};
    
    for (int i = 0; i != 12; i++) {
        if (strcmp(str, list[i]) == 0) {
            return (i);
        }
    }
    return (-1);
}

void	init_functions(void (*func[12])())
{
    func[0] = &repo_create;
    func[1] = &repo_clone;
    func[2] = &repo_push;
    func[3] = &help;
    func[4] = &repo_delete;
    func[5] = &repo_delete;
    func[6] = &repo_list;
    func[7] = &repo_make;
    func[8] = &repo_set_perms;
    func[9] = &repo_get_perms;
    func[10] = &repo_info;
    func[11] = &repo_init;
}

void    free_keys(void)
{
    for (int i = 0; keys[i] != NULL; i++) {
        free(keys[i]->key);
        free(keys[i]->value);
        free(keys[i]);
    }
    free(keys);
}

int	main(int ac, array av)
{    
    void    (*func[12])();
    int     nb;

    keys = parser();
    check_init();
    if (ac <= 1) {
        error(FALSE, "Usage: repo COMMAND [OPTIONS]\n");
        error(TRUE, "Try \'repo --help\' for more information.\n");
    }
    if (strcmp(fkey("colors"), "true") == 0)
        colors = TRUE;
    else
        colors = FALSE;
    nb = find_function(av[1]);
    if (nb == -1) {
        error(FALSE, "%crepo: unrecognized option \'%s\'\n", c_red, av[1]);
        error(TRUE, "Try %c\'repo --help\'%c for more information.\n", c_normal, c_red);
    }
    init_functions(func);
    func[nb](ac, av);
    free_keys();
    return (STOP_SUCCESS);
}
