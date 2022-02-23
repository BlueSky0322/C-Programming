#include "main.h"

void updateVaxQuantityMenu(){
	
	
	int updateChoice;
	
	printf("\n*****Update Vaccine Quantities Menu*****\n");
	printf("Please select an option (1-3) to continue: \n");
	printf("(1) Received Vaccines\n");
	printf("(2) Distributed Vaccines\n");
	printf("(3) Back to Main Menu\n");
	printf("Your option: ");
	scanf("%d", &updateChoice); //get 1 int
	
	switch (updateChoice)
	{
	case 1:		
		updateVaxQuantity(updateChoice);
		break;
	case 2:
		updateVaxQuantity(updateChoice);
		break;	
	case 3:
		mainMenu();
		break;
	default:
		printf("Invalid input!");
	}
}
