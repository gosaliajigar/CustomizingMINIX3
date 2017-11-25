#include <unistd.h>
#include <stdlib.h>
#include <stdio.h> 

/* 
 * usermenu -- user driven menu for choosing which user library function to be called which eventually calls system call 
 *             CALCTABLES (calc_tables) for summation tables
 *
 * Author Name    : Jigar Gosalia
 * Course Name    : CSC 502 : Principles of OS & Distributed Systems 
 * Professor Name : Dr. Yurong Xu 
 */

int get_choice() {
	int choice;
	printf("Which user library function would you like to call?\n"); 
	printf("\t1: Multiplication Tables\n");
	printf("\t2: Summation      Tables\n");
	printf("\t3: Square         Tables\n");
	printf("\t4: Cubic          Tables\n");
	printf("\nYour choice? : "); 
	scanf("%d",&choice);
	return choice;
}

int get_input() {
	int input;
	printf("\nEnter input : "); 
	scanf("%d",&input); 
	return input;
}

int main() {
	int choice, input, key;
	while(1) { 
		choice = get_choice();
		switch(choice) {
			case 1:
				input = get_input();
				multiplicationtables(input);
				break;
			case 2: 
				input = get_input(); 
				summationtables(input);
				break;
			case 3: 
				input = get_input(); 
				squaretables(input);
				break;
			case 4: 
				input = get_input(); 
				cubictables(input);
				break;
			default: 
				printf("\n!!Good Bye!!\n"); 
				exit(0);
		}
		printf("PRESS ANY NUMBER[0-9] & PRESS ENTER TO CONTINUE ... "); 
		scanf("%d",&key);
		if (key>=0 && key<=9) {
			continue;
		} else {
			break;
		}
	} 
	return 0;
}
