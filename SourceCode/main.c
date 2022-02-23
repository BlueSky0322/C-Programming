#include "main.h"
#include "functionProt.h"
#include "menuFunctionProt.h"
#include "struct.h"

int main(){
	int input;
	
	printf("\n=======VACCINE INVENTORY MANAGEMENT SYSTEM======= \n");
	// call menu() at least once. After menu() ends, ask user if they want to continue
	do
	{				
		mainMenu();
		printf("\n\nInput 0 to terminate or any other number continue: ");
		scanf("%d", &input);  //receives integer input
	} while ((input != 0));

	return 0;
}
