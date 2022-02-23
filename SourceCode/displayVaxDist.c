//for every code in the linked list
//add amount of distributions
//sort the vax according to distributions
//display
#include "main.h"
#include "struct.h"

void displayVaxDist(){
	//initialise two empty pointers distHead and distPointer
	struct dist* distHead = NULL;
	struct dist* distPointer = NULL;
	
	char vaxCode[3], dummy[5], buffer1[200], buffer2[200];
	int quantity;
	long distQuantity, ldummy;
	float fdummy;
	
	//initialise first node distTotal
	struct dist* distTotal = NULL;
	distTotal = (struct dist*)malloc(sizeof(struct dist));
	
	//assign distTotal to distHead and distPointer
	distHead = distTotal;
	distPointer = distTotal;
	
	//open vaccine.txt file
	FILE *vaxFilePtr, *distFilePtr;
	vaxFilePtr = fopen("vaccine.txt", "r");
	if (vaxFilePtr == NULL)
	{
		//terminate program with error status if file not found
		printf("Error! Could not open file.");
		exit(1);
	}
	
	else
	{
		//write file into buffer
		fgets(buffer1, 200, vaxFilePtr);
		
		//write vax_code from buffer into first node of linked list
		sscanf(buffer1, "%s %s %s %d %f %ld", dummy , distTotal->vax_code, dummy, &ldummy, &fdummy, &ldummy);
		
		fflush(stdin); //flush stdin buffer
		fgets(buffer1, 200, vaxFilePtr); //write next line in file into buffer
		
		//reading through the file
		while(!feof(vaxFilePtr))
		{
			//initialise next node called nextDistTotal
			struct dist* nextDistTotal = NULL;
			nextDistTotal = (struct dist*)malloc(sizeof(struct dist));
			nextDistTotal->next = NULL; 
			
			//write next vax_code in buffer into next node
			sscanf(buffer1, "%s %s %s %d %f %ld", dummy , nextDistTotal->vax_code, dummy, &ldummy, &fdummy, &ldummy);
			
			//set quantity to 0 in all nodes
			nextDistTotal->quantity = 0;
			
			//assign distPointer to point at next node
			distPointer->next = nextDistTotal;
			distPointer = distPointer->next;
			fflush(stdin);
			fgets(buffer1, 200, vaxFilePtr);
		}
	}
	fclose(vaxFilePtr);
	
	//open dist.txt file
	distFilePtr = fopen("dist.txt", "r");
	if (distFilePtr == NULL)
	{
		printf("Error! Could not open file.");
		exit(1);
	}
	else 
	{
		fflush(stdin); //flush stdin buffer
		fgets(buffer2, 200, distFilePtr);//write file into buffer
		
		//reading through the file
		while(!feof(distFilePtr))
		{
			//write contents in buffer into linked list
			sscanf(buffer2, "%s %ld", vaxCode , &distQuantity);
			
			//assign distPointer to point at first node
			distPointer = distHead;
			//traversing through the linked list
			while (distPointer != NULL)
			{
				//compare vax_code in linked list with vaxCode from dist.txt
				if (strcmp(distPointer->vax_code, vaxCode) == 0)
				{
					//add amount from dist.txt into linked list quantity
					distPointer->quantity += distQuantity;
					break;
				}
				else
				{
					//point to next node
					distPointer = distPointer->next;		
				}
			}
			fflush(stdin);
			fgets(buffer2, 200, distFilePtr);	
		}
		
	}
	fclose(distFilePtr);
	
	//sorts the linked list
	bubbleSort(distHead);
	
	//assign distPointer to point to first node 
	distPointer = distHead;
	printf("\nVaccine Code | Quantity \n");
	//traversing the linked list
	while (distPointer != NULL)
	{
		//output onto console
		printf("%7s %15ld\n", distPointer->vax_code, distPointer->quantity);
		distPointer = distPointer->next; //point to next node
	}
	
	mainMenu();
}

		

