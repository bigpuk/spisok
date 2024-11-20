#ifndef COMMON_H
#define COMMON_H

#include <stdlib.h>

struct Spisok
{
    int* spisok;
    int* prev;
    int* next;

    int head;
    int tail;
    int free;
    size_t size;
};

enum Errors
{
    CTOR_ERROR = 0xBEDA,
    IN_ERROR = 0xBEDA,
    POP_ERROR = 0xBEDA,
    INSERT_ERROR = 0xBEDA,
    DEL_ERROR = 0xBEDA
};

#define POISON 0xC0FFEE
#define DEFAULT_SIZE 8
#define BLANK_VALUE -1
//abcdef01    //абсдефол

#endif