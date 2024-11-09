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
        sp_data->free = -1;
    }

    if(sp_data->tail == 0)
    {
        (sp_data->tail)++;
    }

    return 0;
}