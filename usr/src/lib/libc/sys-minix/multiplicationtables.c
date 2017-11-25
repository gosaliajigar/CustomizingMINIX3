// provides _syscall and message
#include <lib.h>
// provides function prototype
#include <unistd.h>   

/* 
 * multiplicationtables -- user library for accessing system call CALCTABLES (calc_tables) for multiplication tables
 *
 * Author Name    : Jigar Gosalia
 * Course Name    : CSC 502 : Principles of OS & Distributed Systems 
 * Professor Name : Dr. Yurong Xu 
 */
int multiplicationtables(int value) {

	// Minix message to pass parameters to a system call
    message m;      

    // set first integer of message to value
    // select multiplication tables
    m.m1_i1 = value;
    m.m1_i2 = 0;
    m.m1_i3 = 0;

    // invoke underlying system call
    return _syscall(PM_PROC_NR, CALCTABLES, &m);
}
