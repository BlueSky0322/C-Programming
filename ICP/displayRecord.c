#include "main.h"
#include "inventoryCreationMenu.h"

void displayRecord(){
	FILE* inventoryCreation;
	inventoryCreation = fopen("vaccine.txt", "r");
	
	if (inventoryCreation == NULL)
	{
		printf("Error! Could not open file.");
	}
		
	else 
	{
		printf("\nName of Vaccine | Vaccine Code | Producing Country | Dosage Required | Population Covered (%%) | Initial Quantity \n");
		char buffer[200];
		fgets(buffer, 200, inventoryCreation);
		
		vaccine vax[50];
		int i = 0;
		while(!feof(inventoryCreation)){
			vaccine* v = vax + i;
			sscanf(buffer, "%s %s %s %d %f %d", &v->name_of_vax, &v->vax_code, &v->prod_country, &v->dosage_req, &v->pop_covered, &v->quantity);
			fgets(buffer, 200, inventoryCreation);
			i++;
		}
		int n = i;
		for (i = 0; i < n; i++){
			printf("%-20s %-15s %-15s %10d %20.1f %20d\n", vax[i].name_of_vax, vax[i].vax_code, vax[i].prod_country, vax[i].dosage_req, vax[i].pop_covered, vax[i].quantity);
		}
	}
	fclose(inventoryCreation);
	printf("\n");
	inventoryCreationMenu();
}
