#include "main.h"
void writeToFile(FILE*fptr, vaccine *iterator)
{
	if(iterator->next != NULL)
	{
		fprintf(fptr, "%s %s %s %d %.1f %d\n", iterator->name_of_vax, iterator->vax_code, iterator->prod_country, iterator->dosage_req, iterator->pop_covered, iterator->quantity);
		writeToFile(fptr, iterator->next);
	}
	else
		fprintf(fptr, "%s %s %s %d %.1f %d\n", iterator->name_of_vax, iterator->vax_code, iterator->prod_country, iterator->dosage_req, iterator->pop_covered, iterator->quantity);
}

/*
void writeToFile()
{
    FILE * vaxFilePtr = fopen("vaccine.txt", "a");;
    struct vaccine * iterator = vaxRecord;
	
    if(vaxFilePtr==NULL)
    {
        printf("Error\n");
    }

    else
    {
        while(iterator!= NULL)
        {
            fprintf(vaxFilePtr, "%s %s %s %d %.1f %d\n", iterator->name_of_vax, iterator->vax_code, iterator->prod_country, iterator->dosage_req, iterator->pop_covered, iterator->quantity);
            iterator= iterator->next;
        }
    }

    fclose(vaxFilePtr);
}
*/
