#include <stdio.h>

#include "sp_dtor.h"

int sp_dtor(Spisok* sp_data)
{
    free(sp_data->spisok);
    free(sp_data->prev);
    free(sp_data->next);

    sp_data->free = 0;
    sp_data->head = 0;
    sp_data->size = 0;
    sp_data->tail = 0;

    return 0;
}