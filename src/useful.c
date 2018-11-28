#include "repo.h"

string  cmp(string s1, string s2)
{
    int     size = (int) strlen(s1) + (int) strlen(s2);
    string  final = malloc(sizeof(string) * (size + 1));

    final[size] = EOL;
    for(int i = 0; i != (int) strlen(s1); i++) {
        final[i] = s1[i];
    }
    for (int i = (int) strlen(s1); i != size; i++) {
        final[i] = s2[i - (int) strlen(s1)];
    }
    return (final);
}

string  fkey(string str)
{
    for (int i = 0; keys[i] != NULL; i++) {
        if (strcmp(keys[i]->key, str) == 0)
            return (keys[i]->value);
    }    
    return (NULL);
}

bool    strchar(string str, char c)
{
    for (int i = 0; str[i] != '\0'; i++)
        if (str[i] == c)
            return (TRUE);
    return (FALSE);
}
