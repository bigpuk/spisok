#include <stdio.h>
#include <assert.h>

#include "next_dump.h"

void next_dump(Spisok* sp_data)
{
    assert(sp_data);

    printf("\n-------------------------------NEXT ARRAY-------------------------------\n");

    printf("size of spisok = %ld\nhead = %d\ntail = %d\nfree = %d\n\n", sp_data->size, sp_data->head, sp_data->tail, sp_data->free);

    for(size_t next_elem = 0; next_elem < DEFAULT_SIZE; next_elem++)
    {
        if(sp_data->next[next_elem] == -1)
        {
            printf(" ");
        }
        
        if(next_elem == 0)
        {
            printf(" ");
        }
        else if(next_elem / 10 == 0)
        {
            printf("   ");
        }
        else
        {
            for(size_t space_num = 0; space_num < 3 - next_elem / 10; space_num++)
            {
                printf(" ");
            }
        }

        printf("%ld", next_elem);

        if(next_elem == 9)
        {
            printf(" ");
        }
    }

    printf("\n");

    for(size_t next_elem = 0; next_elem < DEFAULT_SIZE; next_elem++)
    {
        printf("[%d] ", sp_data->next[next_elem]);
    }

    printf("\n------------------------------------------------------------------------\n\n");
}