#include "repo.h"

string  add_element(string str, string ele)
{
    int size;

    if (str == NULL) {
        size = strlen(ele);
        str = malloc(sizeof(char) * (size + 1));
        str[0] = '\0';
        str = strcat(str, ele);
        str[size] = '\0';
    } else {
        size = strlen(str);
        size += strlen(ele);
        str = realloc(str, size + 1);
        str = strcat(str, ele);
        str[size] = '\0';
    }
    return (str);
}

string  fill_string(int nb, ...)
{
    va_list list;
    string  str = NULL;
    int     i = 0;

    va_start(list, nb);
    while (i != nb) {
        str = add_element(str, va_arg(list, string));
        i++;
    }
    va_end(list);
    return (str);
}
