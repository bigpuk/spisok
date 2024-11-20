#include <stdio.h>
#include <assert.h>

#include "sp_insert.h"
#include "sp_in.h"

int sp_insert(Spisok* sp_data, int place_after, int num_to_insert)
{
    assert(sp_data);
    assert(place_after);

    if(place_after > DEFAULT_SIZE - 1)
    {
        printf("Can not insert beacuse place to insert is more than maximum size!");

        return INSERT_ERROR;
    }
    else if(place_after > sp_data->head)
    {
        printf("Can not insert beacuse it is the last element!");

        return INSERT_ERROR;
    }

    int is_last = 0;

    if(sp_data->next[sp_data->head] == 0)
    {
        is_last = 1;
    }
    else is_last = 0;

    sp_in(sp_data, num_to_insert);

    int elem_after_place = (place_after + 1) % DEFAULT_SIZE;
    if(elem_after_place == 0)
    {
        elem_after_place++;
    }

    sp_data->prev[elem_after_place] = sp_data->head;
    sp_data->prev[sp_data->head] = place_after;

    sp_data->next[place_after] = sp_data->head;
    sp_data->next[sp_data->head] = elem_after_place;
    
    if(is_last)
    {
        int last_elem_before = sp_data->head - 1;
        if(last_elem_before <= 0)
        {
            last_elem_before = DEFAULT_SIZE - 1;
        }
        sp_data->next[sp_data->head - 1] = 0;
    }

    return 0;
}