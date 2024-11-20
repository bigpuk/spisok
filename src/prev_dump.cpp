#include <stdio.h>
#include <assert.h>

#include "prev_dump.h"

void prev_dump(Spisok* sp_data)
{
    assert(sp_data);
    
    printf("\n-------------------------------PREV ARRAY-------------------------------\n");

    printf("size of spisok = %ld\nhead = %d\ntail = %d\nfree = %d\n\n", sp_data->size, sp_data->head, sp_data->tail, sp_data->free);

    for(size_t prev_elem = 0; prev_elem < DEFAULT_SIZE; prev_elem++)
    {
        if(sp_data->prev[prev_elem] == -1)
        {
            printf(" ");
        }
        
        if(prev_elem == 0)
        {
            printf(" ");
        }
        else if(prev_elem / 10 == 0)
        {
            printf("   ");
        }
        else
        {
            for(size_t space_num = 0; space_num < 3 - prev_elem / 10; space_num++)
            {
                printf(" ");
            }
        }

        printf("%ld", prev_elem);

        if(prev_elem == 9)
        {
            printf(" ");
        }
    }

    printf("\n");

    for(size_t prev_elem = 0; prev_elem < DEFAULT_SIZE; prev_elem++)
    {
        printf("[%d] ", sp_data->prev[prev_elem]);
    }

    printf("\n------------------------------------------------------------------------\n\n");
}