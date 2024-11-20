#include <stdio.h>
#include <assert.h>

#include "sp_pop.h"

int sp_pop(Spisok* sp_data)
{
    assert(sp_data);                    //TODO del any elem

    if(!sp_data->size)
    {
        printf("Can not do pop because size is 0!\n");

        return POP_ERROR;
    }
    
    int num_to_pop = sp_data->spisok[sp_data->tail];

    sp_data->spisok[sp_data->tail] = BLANK_VALUE;

    (sp_data->size)--;

    sp_data->tail = (sp_data->tail + 1) % DEFAULT_SIZE;
    if(sp_data->tail == 0)
    {
        (sp_data->tail)++;
    }

    if(sp_data->size == 0)
    {
        sp_data->head = 0;
        sp_data->tail = 0;
        sp_data->free = 1;
    }

    if(sp_data->tail != 1 && sp_data->tail != 0)
    {
        sp_data->next[sp_data->tail - 1] = BLANK_VALUE;

        sp_data->prev[sp_data->tail - 1] = BLANK_VALUE;
        sp_data->prev[sp_data->tail] = 0;
    }
    else
    {
        if(sp_data->size > 1)
        {
            sp_data->next[DEFAULT_SIZE - 1] = BLANK_VALUE;

            //sp_data->prev[sp_data->tail - 1] = BLANK_VALUE;
        }
        else
        {
            sp_data->prev[1] = BLANK_VALUE;
            sp_data->next[1] = BLANK_VALUE;
        }
    }

    return num_to_pop;
}