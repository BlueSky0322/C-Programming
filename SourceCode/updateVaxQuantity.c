#include "main.h"
#include "struct.h"

void updateVaxQuantity(int updateChoice){
	int  flag = 0;
	long vaxAmountInt, vaxAmountAdd;
	char vaxCode[3], buffer[200]; 
	struct vaccine* vaxHead = NULL;
	struct vaccine* vaxPointer = NULL;
	
	FILE *vaxFilePtr, *temp, *distFilePtr;
	vaxFilePtr = fopen("vaccine.txt", "r");
	temp = fopen("temp.txt", "w");
	distFilePtr = fopen("dist.txt", "a");
	
	if (vaxFilePtr == NULL)
	{
		printf("Error! Could not open file.");
		exit(1);
	}	
	else 
	{
		//retrieve first line from file
		fgets(buffer, 200, vaxFilePtr); 
		
		//initialise first node of linked list
		struct vaccine* firstVax = NULL;
		firstVax = (struct vaccine*)malloc(sizeof(struct vaccine));
		
		//assign vaxHead and vaxPointer to point to first node
		vaxHead = firstVax;
		vaxPointer = firstVax;

		//write contents into node
		sscanf(buffer, "%s %s %s %d %f %ld", firstVax->name_of_vax, firstVax->vax_code, firstVax->prod_country, &firstVax->dosage_req, &firstVax->pop_covered, &firstVax->quantity);
		
		//looping through the file from the second line
		while(fgets(buffer, 200, vaxFilePtr))
		{
			//initialise next node
			struct vaccine* nextVax = NULL;
			nextVax = (struct vaccine*)malloc(sizeof(struct vaccine));
			nextVax->next = NULL;
			
			//write contents into next node
			sscanf(buffer, "%s %s %s %d %f %ld", nextVax->name_of_vax, nextVax->vax_code, nextVax->prod_country, &nextVax->dosage_req, &nextVax->pop_covered, &nextVax->quantity);
			
			//set pointer to point to next node
			vaxPointer->next = nextVax;
			vaxPointer = vaxPointer->next;
		}
		
		//error checking loop
		while (flag == 0)
		{
			printf("Please input vaccine code: ");
			scanf("%s", vaxCode); //store a char
			vaxPointer = vaxHead;
			if (updateChoice == 2)
			{
				printf("Distributed amount: ");
				scanf("%ld", &vaxAmountAdd);
				vaxAmountAdd *= -1;
			}
			else 
			{
				printf("Received amount: ");
				scanf("%ld", &vaxAmountAdd);
			}
			
			while (vaxPointer != NULL)
			{
				if (strcmp(vaxCode, vaxPointer->vax_code) == 0)
				{
					flag = 1;
					vaxAmountInt = vaxPointer->quantity;
					vaxAmountInt += vaxAmountAdd;
					vaxPointer->quantity = vaxAmountInt;
					
					if (updateChoice == 2)
					{
						vaxAmountAdd *= -1;
						fprintf(distFilePtr, "%s %ld\n", vaxCode, vaxAmountAdd);
					}	
				}
				vaxPointer = vaxPointer->next;	
			}
			if (flag == 0)
			{
				printf("Invalid vaccine code! Please input again.\n\n");
			}
		}
	}
	
	vaxPointer = vaxHead;
	while (vaxPointer != NULL)
	{
		fprintf(temp, "%s %s %s %d %.1f %ld\n", vaxPointer->name_of_vax, vaxPointer->vax_code, vaxPointer->prod_country, vaxPointer->dosage_req, vaxPointer->pop_covered, vaxPointer->quantity);
		vaxPointer = vaxPointer->next;	
	}
	
	fclose(temp);
	fclose(vaxFilePtr);
	fclose(distFilePtr);
	printf("\nData successfully updated!\n");
	remove("vaccine.txt");
	rename("temp.txt", "vaccine.txt");
	
	if (updateChoice == 2)
	{
		
		printf("%d vaccines have been subtracted from vaccine with vaccine code %s.\n", vaxAmountAdd, vaxCode);
	}
	else
	{
		printf("%d vaccines have been added to vaccine with vaccine code %s.\n", vaxAmountAdd, vaxCode);
	}
	mainMenu();
}
	


