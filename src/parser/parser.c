#include "repo.h"

int get_line_number(string filepath)
{
    size_t  len = 0;
    string  line = NULL;
    FILE    *config;
    int     nb = 0;

    config = fopen(filepath, "r");
    while (getline(&line, &len, config) != -1) {
        nb++;
    }
    free(line);
    fclose(config);
    return (nb);
}

string  set_key(string line)
{
    int     nb = 0;
    string  str;

    while (line[++nb] != ':');
    str = malloc(sizeof(char) * (nb + 1));
    if (!str)
        error(TRUE, "ERROR_CODE_MALLOC\n");
    str[nb] = '\0';
    for (int n = 0; n != nb; n++)
        str[n] = line[n];
    return (str);
}

string  set_value(string line)
{
    int     nb = 0;
    int     i;
    string  str;
    int     index = 0;

    while (line[++nb] != ':');
    nb++;
    i = nb;
    while (line[nb] != '\n' && line[nb] != '\0')
        nb++;
    str = malloc(sizeof(char) * (nb - i + 1));
    if (!str)
        error(TRUE, "ERROR_CODE_MALLOC\n");
    str[nb - i] = '\0';
    while (i != nb) {
        str[index] = line[i];
        index++;
        i++;
    }
    return (str);
}

k   set_key_value(string line)
{
    k   keys = malloc(sizeof(keys_t));

    if (!keys)
        error(TRUE, "ERROR_CODE_MALLOC\n");
    keys->key = set_key(line);
    keys->value = set_value(line);
    return (keys);
}

kv  parser(void)
{
    kv      keys;
    size_t  len = 0;
    string  line = NULL;
    int     linum;
    string  filepath = cmp(getenv("HOME"), "/.repo_config");
    FILE    *config;
    int     i = 0;

    config = fopen(filepath, "r");
    if (!config)
        error(TRUE, "ERROR_FILE\n");
    linum = get_line_number(filepath);
    keys = malloc(sizeof(k) * (linum + 1));
    if (!keys)
        error(TRUE, "ERROR_CODE_MALLOC\n");
    keys[linum] = NULL;
    while (getline(&line, &len, config) != -1) {
        keys[i] = set_key_value(line);
        i++;
    }
    fclose(config);
    free(filepath);
    return (keys);
}
