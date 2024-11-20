#include <stdio.h>
#include <assert.h>

#include "sp_dump.h"

void sp_dump(Spisok* sp_data)
{
    assert(sp_data);
    
    printf("\n------------------------------SPISOK ARRAY------------------------------\n");

    printf("size of spisok = %ld\nhead = %d\ntail = %d\nfree = %d\n\n", sp_data->size, sp_data->head, sp_data->tail, sp_data->free);

    for(size_t sp_elem = 0; sp_elem < DEFAULT_SIZE; sp_elem++)
    {
        if(sp_data->spisok[sp_elem] == -1)
        {
            printf(" ");
        }

        if(sp_elem == 0)
        {
            printf(" ");
        }
        else if(sp_elem / 10 == 0)
        {
            printf("   ");
        }
        else
        {
            for(size_t space_num = 0; space_num < 3 - sp_elem / 10; space_num++)
            {
                printf(" ");
            }
        }

        printf("%ld", sp_elem);

        if(sp_elem == 9)
        {
            printf(" ");
        }
        // for(size_t space_num = 0; space_num < sp_elem / 10 + 2; space_num++)
        // {
        //     printf(" ");
        // }
    }

    printf("\n");

    for(size_t sp_elem = 0; sp_elem < DEFAULT_SIZE; sp_elem++)
    {
        printf("[%d] ", sp_data->spisok[sp_elem]);
    }

    printf("\n------------------------------------------------------------------------\n\n");
}