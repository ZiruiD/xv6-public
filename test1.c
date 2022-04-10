//A Simple C program
#include "types.h"
#include "stat.h"
#include "user.h"

	
//passing command line arguments
	
int main(int argc, char *argv[])
{
    int *x= (int *) 6;
    
    printf(1, "Successfully run system call %d\n", mprotect(x,1));
    exit();
}

