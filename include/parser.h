#ifndef PARSER_H_
#define PARSER_H_

typedef struct keys
{
    string  key;
    string  value;
} keys_t;

typedef keys_t*   k;
typedef keys_t**  kv;

kv  parser(void);

#endif
