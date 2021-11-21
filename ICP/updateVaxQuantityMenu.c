#include "main.h"
#include "receivedVax.h"

void updateVaxQuantityMenu(){
	
	
	int updateChoice;
	
	printf("Update Vaccine Quantities Menu: \n");
	printf("Please select an option (1/2) to continue: \n");
	printf("(1) Received vaccines\n");
	printf("(2) Distributed vaccines\n");
	printf("Your option: ");
	scanf("%d", &updateChoice); //get 1 char
	
	switch (updateChoice)
	{
	case 1:		
		receivedVax();
		break;
	case 2:	
	case 3:
	case 4:
	default:
		printf("Invalid input !");
	}
}
