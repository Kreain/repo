#include "repo.h"

void    help(void)
{
    printf("Usage: repo COMMAND [OPTIONS]\n");
    printf("version : 1.0.0\n");
    printf("OPTIONS:\n");
    printf("    create  [name]                  -   create the repository [name]\n");
    printf("    clone   [name]                  -   clone the repository [name]\n");   
    printf("    push    {files}                 -   push the directory you are in\n");
    printf("                                        you can specify the files you want to push {ie: repo push file1 file2 ...}\n");
    printf("                                        if no files are specified, it will push everything\n");
    printf("                                        the commit message will be asked as input\n");
    printf("    list    {|!|name}                -   list all repositories if no name is specified\n");
    printf("                                        set name to search if repository exists\n");
    printf("                                        add '!' at the end of the name to search all repositories starting with this name\n");
    printf("    make    [name]                  -   create, set permissions and clone the repository [name]\n");
    printf("    delete  [name]                  -   delete the repository [name]\n");
    printf("    remove  [name]                  -   same command as delete [name]\n");
    printf("    setp    [name] {user} {perms}   -   set permissions {perms} to {user} on the repository [name]\n");
    printf("                                        if no user and perms are entered, it will set the default permissions of .repo_config\n");
    printf("                                        if only a user is entered with no perms, it will remove permissions for this user\n");
    printf("    getp    [name]                  -   get the permissions of the repository [name]\n");
    printf("    info    [name] {file}           -   get information on the repository [name]\n");
    printf("                                        if only the repository is specified, you will get a tree of the repository\n");
    printf("                                        if you specify a dir/file in this repository, you will get a cat/tree of the {file}\n");
    printf("    --help                          -   open this help\n");
    printf("\n");
    printf("If you have a bug to report or some upgrade requests, you can send an e-mail to martin.laplanche@epitech.eu, or leave\n");
    printf("an issue in the github repository\n");
}
