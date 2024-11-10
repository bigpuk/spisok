#include <stdio.h>
#include <assert.h>

#include "sp_in.h"

int sp_in(Spisok* sp_data, int num_to_in)
{
    assert(sp_data);
    
    if(sp_data->size >= DEFAULT_SIZE - 1)
    {
        printf("Can not do in because maximum size is reached\n");

        return IN_ERROR;
    }
   
    sp_data->spisok[sp_data->free] = num_to_in;

    // if(sp_data->head != 0)
    // {
    //     sp_data->prev[(sp_data->head + 1) % DEFAULT_SIZE] = sp_data->head;
    // }

    sp_data->head = (sp_data->head + 1) % (DEFAULT_SIZE);
    if(sp_data->head == 0)
    {
        (sp_data->head)++;
    }
    
    (sp_data->size)++;
    
    if(sp_data->size < DEFAULT_SIZE)
    {
        sp_data->free = (sp_data->free + 1) % (DEFAULT_SIZE);

        if(sp_data->free == 0)
        {
            (sp_data->free)++;
        }
    }
    else
    {
        sp_data->free = BLANK_VALUE;
    }

    if(sp_data->tail == 0)
    {
        (sp_data->tail)++;
    }

    if(sp_data->head != 1)
    {
        sp_data->prev[sp_data->head] = sp_data->head - 1;

        sp_data->next[sp_data->head - 1] = sp_data->head;
        sp_data->next[sp_data->head] = 0;
    }
    else
    {
        if(sp_data->size > 1)
        {
            sp_data->prev[sp_data->head] = DEFAULT_SIZE - 1;

            sp_data->next[DEFAULT_SIZE - 1] = sp_data->head;
        }

        if(sp_data->size == 1)
        {
            sp_data->prev[sp_data->head] = 0;
            sp_data->next[sp_data->head] = 0;
        }
        else
        {
            sp_data->prev[sp_data->head] = BLANK_VALUE;
            sp_data->next[sp_data->head] = BLANK_VALUE;
        }
    }

    return 0;
}