#include "main.h"

void fileToStruct(){
	FILE* inventoryCreation;
	inventoryCreation = fopen("vaccine.txt", "r+");
	
	if (inventoryCreation == NULL)
	{
		printf("Error! Could not open file.");
	}
		
	else 
	{
		char buffer[200];
		fgets(buffer, 200, inventoryCreation);
		
		vaccine vax[50];
		int i = 0;
		while(!feof(inventoryCreation)){
			vaccine* v = vax + i;
			sscanf(buffer, "%s %s %s %d %d %f", &v->name_of_vax, &v->vax_code, &v->prod_country, &v->dosage_req, &v->quantity, &v->pop_covered);
			fgets(buffer, 200, inventoryCreation);
			i++;
		}
		
		
	
		}
		
		
	
	fclose(inventoryCreation);
}

