#include "types.h"
#include "stat.h"
#include "user.h"
#include "mmu.h"

int
main(int argc, char *argv[])
{
    printf(1,"-------------------------------test for mprotect----------------------------------\n");


    //length is not positive
    printf(1,"---------------test for positive length---------------------\n");
    printf(1,"Length is not positive:\n");
    int* x = (int*) PGSIZE;
    int mprotect_num_returned_1 = mprotect((void*) x,-10);
    printf(1,"Number returned by mprotect: %d\n", mprotect_num_returned_1); //should return -1
    *x=5;  //overwrite
    printf(1,"After Overwritten: %d\n", *x); //should be 5 because it is still writable


    //address is not page aligned
    printf(1,"---------------test for page aligned---------------------\n");
    printf(1,"Address is not page aligned:\n");
    int* y = (int*) 6000;
    int mprotect_num_returned_2 = mprotect((void*) y,1);
    printf(1,"Number returned by mprotect: %d\n", mprotect_num_returned_2); //should return -1
    *x=5;  //overwrite
    printf(1,"After Overwritten: %d\n", *x); //should be 5 because it is still writable


    //successful changing
    printf(1,"---------------test for successful changing---------------------\n");
    printf(1,"Valid address and length:\n");
    int* a = (int*) PGSIZE;
    int mprotect_num_returned_3 = mprotect((void*) a,1);
    printf(1,"Number returned by mprotect: %d\n", mprotect_num_returned_3); //should return 0
    printf(1,"Process should be killed by the overwritten below:\n");
    *x=5;  //overwrite, but the process should be killed at this point


    exit();

}
