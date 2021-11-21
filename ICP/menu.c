#include "main.h"
#include "inventoryCreationMenu.h"
#include "fileToStruct.h"

void menu()
{
	int option;		

	printf("Please select an option to proceed: \n");
	printf("(1) Inventory Creation\n");
	printf("(2) Update Vaccine Quantities\n");
	printf("Your option: ");
	scanf("%d", &option); // accept 1 int	

	switch (option)
	{
	case 1:		
		inventoryCreationMenu();
		break;
	case 2:	
		updateVaxQuantityMenu();
		break;
	case 3:
		fileToStruct();
	case 4:
	default:
		printf("Invalid input !");
	}
}
