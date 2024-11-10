#include <stdio.h>
#include <assert.h>

#include "sp_insert.h"

void sp_insert(Spisok* sp_data, int elem_to_place_in)
{
    assert(sp_data);

    int num_to_insert = sp_data->spisok[sp_data->head];

    for(size_t moved_elems = 0; moved_elems < sp_data->size - elem_to_place_in; moved_elems++)
    {
        sp_data->spisok[sp_data->size - moved_elems] = sp_data->spisok[sp_data->size - moved_elems - 1];
    }

    sp_data->spisok[elem_to_place_in] = num_to_insert;
}