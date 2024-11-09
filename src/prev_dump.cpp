#include <stdio.h>

#include "prev_dump.h"

void prev_dump(Spisok* sp_data)
{
    printf("\n-----------------PREV ARRAY-----------------\n");

    for(size_t prev_elem = 0; prev_elem < DEFAULT_SIZE; prev_elem++)
    {
        if(sp_data->spisok[prev_elem] == -1 && prev_elem != 0)
        {
            printf("  ");
        }
        else
        {
            printf(" ");
        }

        printf("%d", prev_elem);

        for(size_t space_num = 0; space_num < DEFAULT_SIZE / 10 - prev_elem / 10 + 1; space_num++)
        {
            printf(" ");
        }
    }

    for(size_t prev_elem = 0; prev_elem < DEFAULT_SIZE; prev_elem++)
    {
        printf("[%d] ", sp_data->prev[prev_elem]);
    }

    printf("\n--------------------------------------------\n\n");
}