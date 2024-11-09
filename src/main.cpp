#include <stdio.h>

#include "sp_ctor.h"
#include "sp_in.h"
#include "sp_out.h"
#include "sp_dtor.h"
#include "sp_dump.h"
#include "prev_dump.h"
#include "common.h"

int main()
{
    Spisok sp_data = {};

    sp_ctor(&sp_data);

    sp_in(&sp_data, 7);
    sp_in(&sp_data, 7);
    sp_in(&sp_data, 7);
    sp_in(&sp_data, 7);
    sp_in(&sp_data, 7);
    sp_in(&sp_data, 7);
    sp_in(&sp_data, 7);

    sp_dump(&sp_data);
    sp_in(&sp_data, 7);


    // printf("%d\n", sp_out(&sp_data));
    // printf("%d\n", sp_out(&sp_data));
    // printf("%d\n", sp_out(&sp_data));
    // printf("%d\n", sp_out(&sp_data));

    sp_dump(&sp_data);

    sp_out(&sp_data);

    sp_dump(&sp_data);

    sp_out(&sp_data);
    sp_in(&sp_data, 7);


    sp_dump(&sp_data);

    sp_out(&sp_data);

    sp_dump(&sp_data);

    sp_out(&sp_data);

    sp_dtor(&sp_data);
}