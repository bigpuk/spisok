#include <stdio.h>
#include <assert.h>

#include "sp_out.h"

int sp_out(Spisok* sp_data)
{
    assert(sp_data);

    if(!sp_data->size)
    {
        printf("Can not do out because size is 0!\n");

        return OUT_ERROR;
    }
    
    int num_to_out = sp_data->spisok[sp_data->tail];

    sp_data->spisok[sp_data->tail] = -1;

    (sp_data->size)--;
    sp_data->tail = (sp_data->tail + 1) % DEFAULT_SIZE;

    return num_to_out;
}