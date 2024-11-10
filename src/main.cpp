#include <stdio.h>

#include "sp_ctor.h"
#include "sp_in.h"
#include "sp_out.h"
#include "sp_insert.h"
#include "sp_dtor.h"
#include "sp_dump.h"
#include "prev_dump.h"
#include "next_dump.h"
#include "common.h"

int main()
{
    Spisok sp_data = {};
    if(!(&sp_data))
    {
        printf("main ERROR!");

        return 1;
    }

    sp_ctor(&sp_data);
    
    // sp_in(&sp_data, 7);
    // sp_in(&sp_data, 7);
    // sp_in(&sp_data, 7);
    // sp_in(&sp_data, 8);
    // sp_insert(&sp_data, 2);
    // sp_dump(&sp_data);
    sp_in(&sp_data, 7);

    sp_dump(&sp_data);
    prev_dump(&sp_data);
    next_dump(&sp_data);

    sp_out(&sp_data);

    sp_dump(&sp_data);
    prev_dump(&sp_data);
    next_dump(&sp_data);

    
    sp_in(&sp_data, 7);
    sp_in(&sp_data, 7);

    sp_out(&sp_data);
    sp_dump(&sp_data);
    prev_dump(&sp_data);
    next_dump(&sp_data);


    sp_in(&sp_data, 7);
    sp_in(&sp_data, 7);

    sp_dump(&sp_data);
    prev_dump(&sp_data);
    next_dump(&sp_data);

    sp_dtor(&sp_data);
}