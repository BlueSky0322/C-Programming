#include "main.h"
#include "menu.h"

int main(){
	int input;

	// call menu() at least once. After menu() ends, ask user if they want to continue
	do
	{				
		menu();
		printf("\nInput 0 to terminate or any other key to continue: ");
		scanf("%d", &input);  //only gets 1 char. \n not included		
	} while ((input != 0));

	return 0;
}
