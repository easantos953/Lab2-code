#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Simple test program 

static inline unsigned int getCycles ()
{
	unsigned int cycleCount;
	// Read CCNT register
	asm volatile ("MRC p15, 0, %0, c9, c13, 0\t\n": "=r"(cycleCount));  
	return cycleCount;
}

static inline void initCounters ()
{
	// Enable user access to performance counter
	asm volatile ("MCR p15, 0, %0, C9, C14, 0\t\n" :: "r"(1));
	// Reset all counters to zero
	int MCRP15ResetAll = 23; 
	asm volatile ("MCR p15, 0, %0, c9, c12, 0\t\n" :: "r"(MCRP15ResetAll));  
	// Enable all counters:  
	asm volatile ("MCR p15, 0, %0, c9, c12, 1\t\n" :: "r"(0x8000000f));  
	// Disable counter interrupts
	asm volatile ("MCR p15, 0, %0, C9, C14, 2\t\n" :: "r"(0x8000000f));
	// Clear overflows:
	asm volatile ("MCR p15, 0, %0, c9, c12, 3\t\n" :: "r"(0x8000000f));
}

int main(void)
{
	volatile int * led = (int *) 0xFF200038; // red LED address
	volatile long int * hex3_hex0 = (long int *) 0xFF200020;
	volatile long int * hex5_hex4 = (long int *) 0xFF200010;

	volatile long int * sdram = (long int *) 0xC0000000;
	volatile long int * on_chip = (long int *) 0xC4000000;
	volatile long int * hps_sdram = (long int *) 0x0010000;
	volatile long int * hps_on_chip = (long int*) 0xFFFF0000;
	//volatile int * switchptr = (int *) 0xFF200030; // SW slider switch address

	long int user_int;
	long int user_int2;
	char unwantedCharacters[40];
	int choice;
	int i = 0;
	unsigned int time;
	int fakeCounter = 0;
	unwantedCharacters[0] = 0;
	initCounters();

	while(1){
	printf("1. HPS SDRAM 2. HPS On Chip 3. FPGA SDRAM 4. FPGA On Chip\n");
	printf("Select a memory block: ");
	scanf("%d", &choice);	

	switch(choice){
	case(1):
		time = getCycles();
		for(i = 0; i< 8000; i++)
			*(hps_sdram) = i + 1;
		time = getCycles() - time;
		printf("Elapsed Time: %d cycles\n", time);
		printf("HPS SDRAM is %ld\n", *(hps_sdram));
		break;
	case(2):
		time = getCycles();
		for(i = 0; i< 8000; i++)
			*(hps_on_chip) = i + 1;
		time = getCycles() - time;
		printf("Elapsed Time: %d cycles\n", time);
		printf("HPS on chip is %ld\n", *(hps_on_chip));
		break;
	case(3):
		time = getCycles();
		for(i = 0; i< 8000; i++)
			*(sdram) = i + 1;
		time = getCycles() - time;
		printf("Elapsed Time: %d cycles\n", time);
		printf("FPGA SDRAM is %ld\n", *(sdram));
		break;
	case(4):
		time = getCycles();
		for(i = 0; i< 8000; i++)
			*(on_chip) = i + 1;
		time = getCycles() - time;
		printf("Elapsed Time: %d cycles\n", time);
		printf("FPGA on chip is %ld\n", *(on_chip));
		break;
	default:
		printf("number pls\n");
		}
	}
	return 0;
}
	

	/*while(1){
		printf("Enter a number: (-1 to quit)");
		scanf("%ld", &user_int);
		gets(unwantedCharacters);
		
		if(user_int == -1){
			printf("bye\n");
			break;
		}
		else if(unwantedCharacters[0] != 0){
			printf("enter number\n");
			continue;
		}
		else if(user_int > LONG_MAX){
			printf("too long\n");
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
	int select;
	int i = 0;
	int fakeCounter = 0;
	unsigned int time;

	while(1){
	printf("1. HPS Chip 2. HPS DRAM 3. FPGA On Chip 4. FPGA SDRAM ");
	scanf("%d", &select);
	
	if(select == 1){
	printf("type a number: ");
	scanf("%ld", &user_int);
	
	*(hps_on_chip) = user_int;
	
	i = 0;
	fakeCounter = 0;
	initCounters (); 
	time = getCycles();
	for (i = 0; i < 20000; i++)
	fakeCounter = fakeCounter + 1;
	time = getCycles() - time;
	printf ("Elapsed Time: %d cycles\n", time);

	time = getCycles();
	for (i = 0; i < 200000; i++)
	fakeCounter = fakeCounter + 1;
	time = getCycles() - time;
	printf ("Elapsed Time: %d cycles\n", time);


	printf("on_chip currently holds %ld\n", *(sdram));
}

/////////////////////////////////////////////////////////////////

	printf("2. Write to SDRAM: ");
	scanf("%ld", &user_int2);
	
	*(hps_sdram) = user_int2;
	

	i = 0;
	fakeCounter = 0;
	initCounters (); 

	time = getCycles();
	for (i = 0; i < 20000; i++)
	fakeCounter = fakeCounter + 1;
	time = getCycles() - time;
	printf ("Elapsed Time: %d cycles\n", time);

	time = getCycles();
	for (i = 0; i < 200000; i++)
	fakeCounter = fakeCounter + 1;
	time = getCycles() - time;
	printf ("Elapsed Time: %d cycles\n", time);

	printf("sdram currently holds %ld", *(hps_sdram));

	return 0;
}*/
