#include "main.h"
#include "menu.h"
#include "addRecord.h"
#include "displayRecord.h"

void inventoryCreationMenu(){
	int inv_crea_choice;
	
	printf("\nInventory Creation Menu\n");
	printf("Please select an option to proceed: \n");
	printf("(1) Add Records\n");
	printf("(2) Display Records\n");
	printf("(3) Back to Main Menu\n");
	printf("Your option: ");
	scanf("%d", &inv_crea_choice);
	
	switch (inv_crea_choice)
	{
	case 1:		
		addRecord();
		break;
	case 2:		
		displayRecord();
		break;
	case 3:		
		menu();
		break;
	default:
		printf("\nWrong Input!\n");
	}
}
