#include <stdio.h>

#include "sp_dump.h"

void sp_dump(Spisok* sp_data)
{
    printf("-----------------SP ARRAY-----------------\n");

    printf("size of spisok = %d\nhead = %d\ntail = %d\nfree = %d\n", sp_data->size, sp_data->head, sp_data->tail, sp_data->free);

    for(size_t sp_elem = 0; sp_elem < DEFAULT_SIZE; sp_elem++)
    {
        if(sp_data->spisok[sp_elem] == -1 && sp_elem != 0)
        {
            printf("  ");
        }
        else
        {
            printf(" ");
        }

        printf("%d", sp_elem);

        for(size_t space_num = 0; space_num < DEFAULT_SIZE / 10 - sp_elem / 10 + 1; space_num++)
        {
            printf(" ");
        }
    }

    printf("\n");

    for(size_t sp_elem = 0; sp_elem < DEFAULT_SIZE; sp_elem++)
    {
        printf("[%d] ", sp_data->spisok[sp_elem]);
    }

    printf("\n------------------------------------------\n");
}