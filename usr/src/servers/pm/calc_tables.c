#include <stdio.h>
#include "pm.h"

/* 
 * calc_tables -- system call CALCTABLES (calc_tables) implementation
 *
 * Author Name    : Jigar Gosalia
 * Course Name    : CSC 502 : Principles of OS & Distributed Systems 
 * Professor Name : Dr. Yurong Xu 
 */
 
int calc_tables() {
    /* m_in is a global variable set to PM's incoming message.
     * m_in.m1_i1, m_in.m1_i2 and m_in.m1_i3 are the integer
     * parameter set in user library */
    int i = m_in.m1_i1; 
    int j = m_in.m1_i2;
    int k = m_in.m1_i3;
    
    printf("\n\nSYSTEM CALL CALCTABLES invoked (ITEMS=%d OPT_1=%d OPT_2=%d)\n\n", i, j, k);
    
    printf("OPT_1==0  & OPT_2==0  ==> Multiplication Table\n");
    printf("OPT_1 >0  & OPT_2==0  ==> Summation      Table\n");
    printf("OPT_1==0  & OPT_2 >0  ==> Square         Table\n");
    printf("OPT_1 >0  & OPT_2 >0  ==> Cubic          Table\n");
    
    printf("\n");

    if (i > 0) {
	    int rows = i;
	    int columns = rows;
	    int row, column;
	
	    if (j == 0 && k == 0) {
		    for (row=0; row<=0; row=row+1) {
		      printf(" %2d | ", row);
		      for (column=1; column<=columns; column=column+1) {
		        printf("%5d", 1*column);
		      }
		      printf("\n");
		      printf(" %s | ", "__");
		      for (column=1; column<=columns; column=column+1) {
		        printf("%5s", "_____");
		      }
		      printf("\n");
		    }
		    for (row=1; row<=rows; row=row+1) {
		      printf(" %2d | ", row);
		      for (column=1; column<=columns; column=column+1) {
		        printf("%5d", row*column);
		      }
		      printf("\n");
		    }
	    } else if (j > 0 && k == 0) {
		    printf(" %2s | %7s\n", "N", "SUM(1-N)");
		    printf(" %s | %7s\n", "__", "_______");
		
		    for (row=1; row<=rows; row=row+1) {
		      printf(" %2d | %7d\n", row, ((row * (row+1))/2));
		    }
	    } else if (j == 0 && k > 0) {
		    printf(" %2s | %7s\n", "N", "N^2");
		    printf(" %s | %7s\n", "__", "_______");
		
		    for (row=1; row<=rows; row=row+1) {
		      printf(" %2d | %7d\n", row, row*row);
		    }
	    } else if (j > 0 && k > 0) {
		    printf(" %2s | %7s\n", "N", "N^3");
		    printf(" %s | %7s\n", "__", "_______");
		
		    for (row=1; row<=rows; row=row+1) {
		      printf(" %2d | %7d\n", row, row*row*row);
		    }
	    } else {
			printf("ERROR: INVALID INPUTS %d %d %d", i, j, k);
	    }
    } else {
    	printf("ERROR: INVALID INPUTS %d %d %d", i, j, k);
    }
    printf("\n\n");
    return 0;
}
