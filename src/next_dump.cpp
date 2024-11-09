#include <stdio.h>

#include "next_dump.h"

void next_dump(Spisok* sp_data)
{
    printf("\n-----------------NEXT ARRAY-----------------\n");

    for(size_t next_elem = 0; next_elem < DEFAULT_SIZE; next_elem++)
    {
        if(sp_data->spisok[next_elem] == -1 && next_elem != 0)
        {
            printf("  ");
        }
        else
        {
            printf(" ");
        }

        printf("%d", next_elem);

        for(size_t space_num = 0; space_num < DEFAULT_SIZE / 10 - next_elem / 10 + 1; space_num++)
        {
            printf(" ");
        }
    }

    for(size_t next_elem = 0; next_elem < DEFAULT_SIZE; next_elem++)
    {
        printf("[%d] ", sp_data->next[next_elem]);
    }

    printf("\n--------------------------------------------\n\n");
}