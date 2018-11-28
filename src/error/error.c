#include "repo.h"

void    display_color(string color)
{
    if (colors == TRUE)
        write(2, color, 5);
}

void    error(bool stop, string str, ...)
{
    va_list list;
    string  temp;

    va_start(list, str);
    for(int i = 0; str[i] != EOL; i++) {
        if (str[i] != '%')
            write(2, &str[i], 1);
        else {
            if (str[i + 1] == 'c')
                display_color(va_arg(list, string));
            else {
                temp = va_arg(list, string);
                write(2, temp, strlen(temp));
                temp = NULL;
            }
            i++;
        }
    }
    write(2, c_normal, 5);
    if (stop == TRUE) {
        free_keys();
        exit(STOP_FAILURE);
    }
}
