#include "main.h"
#include "struct.h"

void displayRecord()
{
	//initialise two empty pointers
	struct vaccine* vaxHead = NULL;
	struct vaccine* vaxPointer = NULL;
	char buffer[200]; //buffer to store lines from files
	
	//open the file
	FILE* vaxFilePtr;
	vaxFilePtr = fopen("vaccine.txt", "r+");
	if (vaxFilePtr == NULL)
	{
		//terminate program with error status if file not found
		printf("Error! Could not open file.");
		exit(1); 
	}
	
	//if file exists...
	else 
	{
		//retrieve first line from file
		fgets(buffer, 200, vaxFilePtr); 
		
		//initialise an empty node called firstVax
		struct vaccine* firstVax = NULL;
		firstVax = (struct vaccine*)malloc(sizeof(struct vaccine));
		
		//assign empty pointers to point at first node
		vaxHead = firstVax;
		vaxPointer = firstVax;

		//write contents from buffer into node
		sscanf(buffer, "%s %s %s %d %f %ld", firstVax->name_of_vax, firstVax->vax_code, firstVax->prod_country, 
											 &firstVax->dosage_req, &firstVax->pop_covered, &firstVax->quantity);
		
	
		fflush(stdin); //flush stdin buffer
		fgets(buffer, 200, vaxFilePtr);//retrieve next line from file
		
		while(!feof(vaxFilePtr)) //looping through the entire file
		{
			//initialise the next node called nextVax
			struct vaccine* nextVax = NULL;
			nextVax = (struct vaccine*)malloc(sizeof(struct vaccine));
			nextVax->next = NULL;//set the pointer of the node to point to empty node
			
			//write contents from buffer into node
			sscanf(buffer, "%s %s %s %d %f %ld", nextVax->name_of_vax, nextVax->vax_code, nextVax->prod_country, 
												 &nextVax->dosage_req, &nextVax->pop_covered, &nextVax->quantity);
			
			//set pointer to point to next node
			vaxPointer->next = nextVax;
			vaxPointer = vaxPointer->next;
			fflush(stdin);//flush stdin buffer
			fgets(buffer, 200, vaxFilePtr);	//retrieve next line from file
		}
		//assign vaxPointer to point to first node
		vaxPointer = vaxHead;
		printf("\nName of Vaccine | Vaccine Code | Producing Country | Dosage Required | Population Covered (%%) | Initial Quantity \n");
		while (vaxPointer != NULL)
		{
			printf("%-20s %-15s %-15s %10d %20.1f %20ld\n", vaxPointer->name_of_vax, vaxPointer->vax_code, vaxPointer->prod_country, 
															vaxPointer->dosage_req, vaxPointer->pop_covered, vaxPointer->quantity);
			vaxPointer = vaxPointer->next;
		}
	}
	fclose(vaxFilePtr);
	inventoryCreationMenu();
}



