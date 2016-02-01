#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Simple test program 
int main(void)
{

	volatile int * led = (int *) 0xFF200038; // red LED address
	volatile long int * hex3_hex0 = (long int *) 0xFF200020;
	volatile long int * hex5_hex4 = (long int *) 0xFF200010;
	//volatile int * switchptr = (int *) 0xFF200030; // SW slider switch address

	long int user_int;
	char unwantedCharacters[40];
	unwantedCharacters[0] = 0;

	while(1){
		printf("Enter a number (-1 to quit): ");
		scanf("%ld", &user_int);
		gets(unwantedCharacters);
		
		if(user_int == -1){
			printf("bye\n");
			break;
		}
		else if(user_int > 2147483647){
			printf("too long\n");
			continue;
		}
		else if(unwantedCharacters[0] != 0){
			printf("enter number please\n");
			continue;
		}
		else if(user_int < 0){
			printf("negative\n");
			continue;
		}
		else{
			*(hex3_hex0) = user_int;
			*(hex5_hex4) = user_int >> 16;
			*(led) = user_int >> 24;
			
			printf("you printed %ld\n", user_int);
		}
	}

	return 0;
}
