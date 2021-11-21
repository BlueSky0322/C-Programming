/*NG LUM THYN TP061914*/
#include <stdio.h>

void addRecord(){
	struct vaccine{
		char name_of_vax[30], vax_code[3], prod_country[20];
		int dosage_req, initial_quantity;
		float pop_covered;
	}V;
	
	int main(){
		FILE* inventoryCreation;
		inventoryCreation = fopen("vaccine.txt", "a");
	
		if (inventoryCreation == NULL)
		{
			printf("Error! Could not open file.");
		}
	
		else 
		{
			printf("Add vaccine records: \n");
			printf("Enter vaccine name: ");
			gets(V.name_of_vax);
		
			printf("Enter vaccine code: ");
			gets(V.vax_code);
			
			printf("Enter producing country: ");
			gets(V.prod_country);
		
			printf("Enter dosage required: ");
			scanf("%d", &V.dosage_req);
			getchar();
			
			printf("Enter population covered: ");
			scanf("%f", &V.pop_covered);
		
			printf("Enter initial quantity: ");
			scanf("%d", &V.initial_quantity);
	
			fprintf(inventoryCreation, "%s, %s, %s, %d, %d, %.1f", V.name_of_vax, V.vax_code, V.prod_country, V.dosage_req, V.initial_quantity, V.pop_covered);
	}	

		fclose(inventoryCreation);
	
		return 0;
	}
}

