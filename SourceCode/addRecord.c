#include "main.h"
#include "struct.h"

void addRecord(){
	//initialise two pointers
	vaccine *vaxRecord, *newVaxRecord;
	int num, i;	
	FILE *vaxFilePtr;
	
	printf("\nHow many records do you want to enter? ");
	scanf("%d", &num); //stores and integer
	
	//initialise for loop for num instances of record inputs	
	for (i = 0; i < num; i++)
	{
		if (i==0)
		{
			//initialise first node called vaxRecord
			vaxRecord = malloc(sizeof(struct vaccine));
			newVaxRecord = vaxRecord;
		}
		else
        {	
        	//initialise next node called newVaxRecord
            newVaxRecord->next = malloc(sizeof(struct vaccine));
            newVaxRecord = newVaxRecord->next; //linking the current node with the next node
        }
        
		printf("\nENTER VACCINE DETAILS\n");
			
		printf("Enter vaccine name: ");
		scanf("%15s", newVaxRecord->name_of_vax);
		
		printf("Enter vaccine code: ");
		scanf("%3s", newVaxRecord->vax_code);
		
		printf("Enter producing country: ");
		scanf("%15s", newVaxRecord->prod_country);
			
		printf("Enter dosage required: ");
		scanf("%d", &newVaxRecord->dosage_req);
		
		printf("Enter population covered: ");
		scanf("%f", &newVaxRecord->pop_covered);
		
		printf("Enter initial quantity: ");
		scanf("%ld", &newVaxRecord->quantity);
		
	}
	//assign the next pointer in newVaxRecord as NULL
	//basically terminating the linked list
	newVaxRecord->next = NULL;
	 
	vaxFilePtr = fopen("vaccine.txt", "a");
	if (vaxFilePtr == NULL)
	{
		fprintf(stderr, "Error! Could not open file.");
		exit(1);
	}
	else
	{
		//write contents into file
		writeToFile(vaxFilePtr, vaxRecord);
	}
	fclose(vaxFilePtr);
	inventoryCreationMenu();
}



