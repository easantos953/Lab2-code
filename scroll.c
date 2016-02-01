#include <stdio.h>
#include <stdlib.h>
//#include <dos.h>

void display(int count){
	
	volatile long int * hex3_hex0 = (long int *) 0xFF200020;
	volatile long int * hex5_hex4 = (long int *) 0xFF200010;
	
	switch(count){
		case 0:
		*(hex3_hex0) = 0xc; // c
		*(hex5_hex4) = 0x00; // ca
		break;
		case 1:
		*(hex3_hex0) = 0xca; // ca
		*(hex5_hex4) = 0x00; // ca
		break;
		case 2:
		*(hex3_hex0) = 0xcaf; // ca
		*(hex5_hex4) = 0x00; // ca
		break;
		case 3:
		*(hex3_hex0) = 0xcaff; // ca
		*(hex5_hex4) = 0x00; // ca
		break;
		case 4:
		*(hex3_hex0) = 0xaffe; // ca
		*(hex5_hex4) = 0xc; // ca
		break;
		case 5:
		*(hex3_hex0) = 0xffee; // ca
		*(hex5_hex4) = 0xca; // ca
		break;
		case 6:
		*(hex3_hex0) = 0xfeec; // ca
		*(hex5_hex4) = 0xaf; // ca
		break;
		case 7:
		*(hex3_hex0) = 0xeeca; // ca
		*(hex5_hex4) = 0xff; // ca
		break;
		case 8:
		*(hex3_hex0) = 0xecaf; // ca
		*(hex5_hex4) = 0xfe; // ca
		break;
		case 9:
		*(hex3_hex0) = 0xcaff; // ca
		*(hex5_hex4) = 0xee; // ca
		break;
		case 10:
		*(hex3_hex0) = 0xaffe; // ca
		*(hex5_hex4) = 0xec; // ca
		break;
	}
}
int main(void)
{
//	volatile int * led = (int *) 0xFF200038; // red LED address
//	volatile long int * hex3_hex0 = (long int *) 0xFF200020;
//	volatile long int * hex5_hex4 = (long int *) 0xFF200010;

//	volatile long int * sdram = (long int *) 0xC0000000;
//	volatile long int * on_chip = (long int *) 0xC4000000;
//	volatile long int * hps_sdram = (long int *) 0x0010000;
//	volatile long int * hps_on_chip = (long int*) 0xFFFF0000;

	int count = 0;
	int stop = 10;
	unsigned int a = 0;
	unsigned int b = 0;
        int delay = 750000000; 
	int choice = 0;
	printf("Enter a speed (1-5): ");

	while(1){
	display(count);	
       
	choice = 0;
	a=0;
	b=0;

	while(choice == 0 && a < delay){	
		while(choice == 0 && b < delay){
			a++;
			b++;
			}
		}	
	
	switch(choice){
	case 1:
	printf("Enter a speed (1-5): ");
		delay = 700000000;
		break;
	case 2:
	printf("Enter a speed (1-5): ");
		delay = 725000000;
		break;
	case 3:
	printf("Enter a speed (1-5): ");
		delay = 750000000;
		break;
	case 4:
	printf("Enter a speed (1-5): ");
		delay = 775000000;
		break;
	case 5:
	printf("Enter a speed (1-5): ");
		delay = 800000000;
		break;
	default:
		break;
	}
//	delay(500);
	if(count == stop){
		count = 5;
		continue;
		}
	count++;
	}
	
	return 0;

}

