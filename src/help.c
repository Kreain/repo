#include "repo.h"

void    help(void)
{
    printf("Usage: repo COMMAND [OPTIONS]\n");
    printf("OPTIONS:\n");
    printf("    create  [name]              -   create the repository [name]\n");
    printf("    clone   [name]              -   clone the repository [name]\n");   
    printf("    push    [commit_message]    -   push the directory you are in with the [commit_message]\n");
    printf("    list    {name|!}            -   list all repositories if no name is specified\n");
    printf("                                    set name to search if repository exists\n");
    printf("                                    add '!' at the end of the name to search all repositories starting with this name\n");
}
