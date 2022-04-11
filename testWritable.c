#include "types.h"
#include "stat.h"
#include "user.h"
#include "mmu.h"

int
main(int argc, char *argv[])
{
    printf(1,"-------------------------------test for munprotect----------------------------------\n");


    //length is not positive
    printf(1,"---------------test for positive length---------------------\n");
    printf(1,"Length is not positive:\n");
    int* a = (int*) PGSIZE;
    int munprotect_num_returned_1 = munprotect((void*) a,-10);
    printf(1,"Number returned by munprotect: %d\n", munprotect_num_returned_1); //should return -1


    //address is not page aligned
    printf(1,"---------------test for page aligned---------------------\n");
    printf(1,"Address is not page aligned:\n");
    int* b = (int*) 6000;
    int munprotect_num_returned_2 = munprotect((void*) b,1);
    printf(1,"Number returned by munprotect: %d\n", munprotect_num_returned_2); //should return -1


    //successful changing
    printf(1,"---------------test for successful changing---------------------\n");
    printf(1,"Valid address and length:\n");
    int* x = (int*) PGSIZE;
    //change to read-only first
    printf(1,"Change to Read-only:\n");
    int mprotect_num_returned = mprotect((void*) x,1);
    printf(1,"Number returned by mprotect: %d\n", mprotect_num_returned); //should return 0

    //change back to writable
    printf(1,"Change back to writable:\n");
    int munprotect_num_returned_3 = munprotect((void*) x,1);
    printf(1,"Number returned by munprotect: %d\n", munprotect_num_returned_3); //should return 0
    *x=5;
    printf(1,"After Overwritten: %d\n", *x); //should be 5 because it is writable now




    exit();

}