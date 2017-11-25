// provides _syscall and message
#include <lib.h>
#include <stdio.h>
// provides atoi
#include <stdlib.h>

/* 
 * calcTables -- accessing system call CALCTABLES (calc_tables) directly
 *
 * Author Name    : Jigar Gosalia
 * Course Name    : CSC 502 : Principles of OS & Distributed Systems 
 * Professor Name : Dr. Yurong Xu 
 */

int main(int argc, char **argv) {

    // MINIX uses message to pass parameters to a system call
    message m;      

    // At least 3 integer parameter
    if (argc < 4) {
    	printf("USAGE: ./calcTables ITEMS OPT_1 OPT_2  : where ITEMS, OPT_1 & OPT_2 are positive integers.\n");
		exit(1);
    }

    int i = atoi(argv[1]);
    int j = atoi(argv[2]);
    int k = atoi(argv[3]);
 
    if (i>0 && j>=0 && k>=0) {
	    // set first integer of message to i  
	    m.m1_i1 = i;
	    // set second integer of message to j
	    m.m1_i2 = j;
	    // set third integer of message to k
	    m.m1_i3 = k;
	
		/* _syscall leads to the system server identified by PM_PRO_NR (the PM server process) invoking the
		 * function identified by call number CALCTABLES with parameters in the message copied to address &m
	     */   
	    return (_syscall(PM_PROC_NR, CALCTABLES, &m));
    } else {
        printf("USAGE: ./calcTables ITEMS OPT_1 OPT_2  : where ITEMS, OPT_1 & OPT_2 are positive integers.\n");
		exit(1);
    }
    return 0;
}

