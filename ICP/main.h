#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct vaccine
{
	char name_of_vax[15];
	char vax_code[3];
	char prod_country[15];
	int dosage_req;
	int quantity;
	float pop_covered;
	struct vaccine *next;
}vaccine;


typedef struct distributed
{	
	char vax_code[3];	
	int quantity;
}dist;
