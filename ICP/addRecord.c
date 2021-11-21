#include "main.h"
#include "inventoryCreationMenu.h"
#include "writeToFile.h"

/*
void addRecord()
{
    int count, i; 
    printf("\nHow many records do you want to enter? ");//initialise loop structure
    scanf("%d", &count);

    for(i=0; i<count; i++)
    {
        if(i==0)
        {
        	//create the first node vaxRecord in the first iteration
            vaxRecord = malloc(sizeof(struct vaccine));
            //move the newVaxRecord pointer to vaxRecord
			newVaxRecord = vaxRecord; 
        }
        else
        {
            newVaxRecord->next = malloc(sizeof(struct vaccine));
            newVaxRecord = newVaxRecord->next;
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
		scanf("%d", &newVaxRecord->quantity);
    }
    newVaxRecord->next = NULL;
    writeToFile();
    inventoryCreationMenu();
}*/

void addRecord(){
	vaccine *vaxRecord, *newVaxRecord;
	int num, i;	
	FILE *vaxFilePtr;

	printf("\nHow many records do you want to enter? ");
	scanf("%d", &num);
		
	for (i = 0; i < num; i++)
	{
		if (i==0)
		{
			vaxRecord = malloc(sizeof(struct vaccine));
			newVaxRecord = vaxRecord;
		}
		else
        {
            newVaxRecord->next = malloc(sizeof(struct vaccine));
            newVaxRecord = newVaxRecord->next;
        }
		
		newVaxRecord->next = malloc(sizeof(struct vaccine));
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
		scanf("%d", &newVaxRecord->quantity);
		
	}
	 newVaxRecord->next = NULL;
	 
	vaxFilePtr = fopen("vaccine.txt", "a");
	if (vaxFilePtr == NULL)
	{
		fprintf(stderr, "Error! Could not open file.");
		exit(1);
	}
	else
	{
		writeToFile(vaxFilePtr, vaxRecord);
	}
	fclose(vaxFilePtr);
	inventoryCreationMenu();
}



