#ifndef REPO_H_
#define REPO_H_

#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <fcntl.h>
#include <dirent.h>
#include <unistd.h>
#include <stdio.h>
#include <stdarg.h>
#include <string.h>
#include <stdlib.h>
#include <errno.h>

typedef int     bool;
typedef char*   string;
typedef char**  array;
typedef struct  dirent  dirent_t;
typedef struct  stat    stat_t;

#define MSG_SIZE 4096

#define TRUE 1
#define FALSE 0
#define EOL '\0'

#include "colors.h"
#include "error.h"
#include "parser.h"

kv  keys;

string  cmp(string, string);
string  fkey(string);
bool    strchar(string, char);
void    repo_push(int, array);
void    repo_clone(int, array);
void    repo_create(int, array);
void    repo_delete(int, array);
void    repo_list(int, array);
void    repo_make(int, array);
void    repo_set_perms(int, array);
void    repo_get_perms(int, array);
void    repo_info(int, array);
void    repo_init(int, array);
void    check_init(void);
void    find_item(array, string);
void    help(void);
string  fill_string(int, ...);
void    free_keys(void);
void    free_list(array);

#endif
