#include "main.h"

void mainMenu()
{
	int option;		
	printf("\n************Main Menu************\n");
	printf("Please select an option (1-4) to proceed: \n");
	printf("(0) Terminate Program\n");
	printf("(1) Inventory Creation\n");
	printf("(2) Update Vaccine Quantities\n");
	printf("(3) Search vaccine and its available quantity\n");
	printf("(4) Produce a list of all vaccines and their distributed quantities\n");
	printf("Your option: ");
	scanf("%d", &option); // accept 1 int	

	switch (option)
	{
	case 0:
		exit(0);
	case 1:		
		inventoryCreationMenu();
		break;
	case 2:	
		updateVaxQuantityMenu();
		break;
	case 3:
		searchVaxQuantity();
		break;
	case 4:
		displayVaxDist();
		break;
	default:
		printf("Invalid input!");
	}
}
