#include <stdio.h>
#include <assert.h>

#include "sp_del.h"

int sp_del(Spisok* sp_data, int place)
{
    assert(sp_data);

    if(!sp_data->size)
    {
        printf("Can not do del because size is 0!\n");

        return DEL_ERROR;
    }

    if(!place)
    {
        printf("Can not do del to element 0!\n");

        return DEL_ERROR;
    }
    
    int num_to_del = sp_data->spisok[place];

    sp_data->spisok[place] = BLANK_VALUE;

    int elem_after_place = (place + 1) % DEFAULT_SIZE;
    if(elem_after_place == 0)
    {
        elem_after_place++;
    }

    sp_data->prev[elem_after_place] = sp_data->prev[place];
    sp_data->prev[place] = BLANK_VALUE;

    int elem_before_place = place - 1;
    if(elem_before_place <= 0)
    {
        elem_before_place = DEFAULT_SIZE - 1;
    }

    if(sp_data->tail != place)
    {
        sp_data->next[elem_before_place] = sp_data->next[place];
    }
    sp_data->next[place] = BLANK_VALUE;

    return num_to_del;
}