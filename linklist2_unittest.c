#include <stdio.h>
#include "linklist2.h"

int main()
{
    struct Snack *snack = NULL;

    linklist_insert(&snack, 0, 0);
    linklist_insert(&snack, 0, 1);
    linklist_insert(&snack, 0, 2);
    linklist_insert(&snack, 0, 3);

    linklist_print(snack);

    printf("delete\n");
    linklist_delete(snack);
    linklist_insert(&snack, 1, 3);
    linklist_print(snack);

    printf("delete\n");
    linklist_delete(snack);
    linklist_insert(&snack, 2, 3);
    linklist_print(snack);
    return 0;
}
