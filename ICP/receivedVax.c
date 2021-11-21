#include "main.h"

void receivedVax(){
	int vaxAmountInt, vaxAmountAdd, i, n, temp;
	char vaxCode[3]; 
	struct vaccine* vaxhead = NULL;
	struct vaccine* vaxpointer = NULL;
	//struct distributed dist = {"",""};
	
	FILE* vaxFilePtr, *test; // *distributedVax;
	vaxFilePtr = fopen("vaccine.txt", "r+");
	test = fopen("temp.txt", "w");
	//distributedVax = fopen("dist.txt", "a");
	
	if (vaxFilePtr == NULL)
	{
		printf("Error! Could not open file.");
	}
		
	else 
	{
		//printf("Debug\n");
		char buffer[200];
		fgets(buffer, 200, vaxFilePtr);
		//printf("Debug\n");
		struct vaccine* firstvax = NULL;
		firstvax = (struct vaccine*)malloc(sizeof(struct vaccine));
		//printf("Debug\n");
		vaxhead = firstvax;
		vaxpointer = firstvax;
		//printf("Debug\n");
		fflush(stdin);
		sscanf(buffer, "%s %s %s %d %f %d", firstvax->name_of_vax, firstvax->vax_code, firstvax->prod_country, &firstvax->dosage_req, &firstvax->pop_covered, &firstvax->quantity);
		
		//printf("Debug\n");
		
		while(!feof(vaxFilePtr))
		{
			struct vaccine* nextvax = NULL;
			nextvax = (struct vaccine*)malloc(sizeof(struct vaccine));
			nextvax->next = NULL;
			
			sscanf(buffer, "%s %s %s %d %f %d", nextvax->name_of_vax, nextvax->vax_code, nextvax->prod_country, &nextvax->dosage_req, &nextvax->pop_covered, &nextvax->quantity);
			
			vaxpointer->next = nextvax;
			vaxpointer = vaxpointer->next;
			
			fgets(buffer, 200, vaxFilePtr);	
		}
		
		struct vaccine *vaxpointer = vaxhead;
		while (vaxpointer->next != NULL)
		{
			
			fprintf(test, "%s %s %s %d %.1f %d\n", vaxpointer->name_of_vax, vaxpointer->vax_code, vaxpointer->prod_country, vaxpointer->dosage_req, vaxpointer->pop_covered, vaxpointer->quantity);	
			/*if (strcmp(vaxCode, vaxpointer->vax_code) == 0)
			{
				printf("Received amount: ");
				scanf("%d", &vaxAmountAdd);
				vaxAmountInt = vaxpointer->quantity;
				vaxAmountInt += vaxAmountAdd;
				vaxpointer->quantity = vaxAmountInt;
				printf("%d", vaxAmountInt);
				fprintf(test, "%s %s %s %d %.1f %d\n", vaxpointer->name_of_vax, vaxpointer->vax_code, vaxpointer->prod_country, vaxpointer->dosage_req, vaxpointer->pop_covered, vaxpointer->quantity);
			}*/
			vaxpointer = vaxpointer->next;	
		}
		
		//printf("Please input vaccine code: ");
		//scanf("%s", vaxCode);
		
		
	}
		
	fclose(test);
	fclose(vaxFilePtr);
}
	//n = i;
   /*while (flag == 0)
	{
		printf("Please input vaccine code: ");
		fflush(stdin);
		scanf("%s", vaxCode);
		getchar();
		
		for (i = 0; i < n; i++)
		{
			if (strcmp(vaxCode, vax[i].vax_code) == 0)
			{
				flag = 1;
				printf("Received amount: ");
				scanf("%d", &vaxAmountAdd);
				temp = i;
			}
		
			else
			{
				fprintf(test, "%s %s %s %d %d %.1f\n", vax[i].name_of_vax, vax[i].vax_code, vax[i].prod_country, vax[i].dosage_req, vax[i].initial_quantity, vax[i].pop_covered);
			}
		}
			
		if(flag == 0){
			printf("Invalid vaccine code entered.\n");
		}
	}*/
	
	/*vaxAmountInt = &vax[temp].initial_quantity;
	*vaxAmountInt += vaxAmountAdd;
	fprintf(test, "%s %s %s %d %d %.1f\n", vax[temp].name_of_vax, vax[temp].vax_code, vax[temp].prod_country, vax[temp].dosage_req, vax[temp].initial_quantity, vax[temp].pop_covered);
	
	//strcpy(dist.vax_code, vax[temp].vax_code);
	//strcpy(dist.quantity, vaxAmountAdd);

	fclose(test);
	fclose(inventoryCreation);
	
	remove("vaccine.txt");
	rename("temp.txt", "vaccine.txt");
	printf("Data successfully updated.\n");
	printf("%d vaccines have been added to vaccine with vaccine code %s.", vaxAmountAdd, vaxCode);
	
    }
}*/



