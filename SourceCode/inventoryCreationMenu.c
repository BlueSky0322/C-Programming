#include "main.h"

void inventoryCreationMenu(){
	int choice;
	
	printf("\n*****Inventory Creation Menu*****\n");
	printf("Please select an option (1-3) to proceed: \n");
	printf("(1) Add Records\n");
	printf("(2) Display Records\n");
	printf("(3) Back to Main Menu\n");
	printf("Your option: ");
	scanf("%d", &choice);
	
	switch (choice)
	{
	case 1:		
		addRecord();
		break;
	case 2:		
		displayRecord();
		break;
	case 3:		
		mainMenu();
		break;
	default:
		printf("\nWrong Input!\n");
	}
}
