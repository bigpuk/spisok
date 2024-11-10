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
    CTOR_ERROR = 0xC444BEDA,
    IN_ERROR = 0x1444BEDA,
    OUT_ERROR = 0x0444BEDA
};

#define POISON 0xC0FFEE
#define DEFAULT_SIZE 8
#define BLANK_VALUE -1
//abcdef01    //абсдефол

#endif