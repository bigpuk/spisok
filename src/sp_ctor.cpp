#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "sp_ctor.h"

int sp_ctor(Spisok* sp_data)
{
    assert(sp_data);

    sp_data->spisok = (int*) calloc(DEFAULT_SIZE, sizeof(int));
    sp_data->prev = (int*) calloc(DEFAULT_SIZE, sizeof(int));
    sp_data->next = (int*) calloc(DEFAULT_SIZE, sizeof(int));
    if(!sp_data->spisok || !sp_data->prev || !sp_data->next)
    {
        printf("Ctor ERROR!");

        return CTOR_ERROR;
    }

    sp_data->head = 0;
    sp_data->tail = 0;
    sp_data->free = 1;
    sp_data->size = 0;

    return 0;
}