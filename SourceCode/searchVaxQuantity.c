#include "main.h"
#include "struct.h"

void searchVaxQuantity()
{
	int flag = 0;
	char vaxCode[3], buffer[200];
	//initialise two empty pointers
	struct vaccine* vaxHead = NULL;
	struct vaccine* vaxPointer = NULL;
	
	//open file
	FILE* vaxFilePtr;
	vaxFilePtr = fopen("vaccine.txt", "r");
	if (vaxFilePtr == NULL)
	{
		//terminate program with error status if file not found
		printf("Error! Could not open file.");
		exit(1);
	}
		
	else 
	{
		fgets(buffer, 200, vaxFilePtr); //retrieve line from file
		
		//initialise first node of linked list
		struct vaccine* firstVax = NULL;
		firstVax = (struct vaccine*)malloc(sizeof(struct vaccine));
		
		//assign vaxHead and vaxPointer to point to first node
		vaxHead = firstVax;
		vaxPointer = firstVax;

		//write contents into node
		sscanf(buffer, "%s %s %s %d %f %ld", firstVax->name_of_vax, firstVax->vax_code, firstVax->prod_country, &firstVax->dosage_req, &firstVax->pop_covered, &firstVax->quantity);
		
	
		fflush(stdin); //flush stdin buffer
		fgets(buffer, 200, vaxFilePtr); //retrieve next line from file
		
		//looping through the entire file
		while(!feof(vaxFilePtr))
		{
			//initialise next node
			struct vaccine* nextVax = NULL;
			nextVax = (struct vaccine*)malloc(sizeof(struct vaccine));
			nextVax->next = NULL; //set the pointer of the node to point to empty node
			
			//write contents into next node
			sscanf(buffer, "%s %s %s %d %f %ld", nextVax->name_of_vax, nextVax->vax_code, nextVax->prod_country, &nextVax->dosage_req, &nextVax->pop_covered, &nextVax->quantity);
			
			//set pointer to point to next node
			vaxPointer->next = nextVax;
			vaxPointer = vaxPointer->next;
			fflush(stdin); //flush stdin buffer
			fgets(buffer, 200, vaxFilePtr);	//retrieve next line from file
		}
		
		//initialise loop for error checking
		while (flag == 0)
		{
			printf("\nPlease input vaccine code: ");
			scanf("%s", vaxCode);
			vaxPointer = vaxHead; // set pointer to point to first node
			while (vaxPointer != NULL) //traverse through the linked list
			{
				if (strcmp(vaxCode, vaxPointer->vax_code) == 0)
				{
					flag = 1; //set flag value to exit loop
					printf("\nName of Vaccine | Vaccine Code | Quantity \n");
					//print linked list into console
					printf("%10s %15s %12ld\n", vaxPointer->name_of_vax, vaxCode, vaxPointer->quantity);
				}
				//point to next node
				vaxPointer = vaxPointer->next;
			}
			if (flag == 0)
			{
				//stay within the loop
				printf("Invalid vaccine code! Please input again.\n");
			}
		}	
	}
	fclose(vaxFilePtr); //close the file
	printf("\n"); 
	mainMenu();	//call back to main menu
}
