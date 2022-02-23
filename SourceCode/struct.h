typedef struct vaccine
{
	char name_of_vax[15];
	char vax_code[3];
	char prod_country[15];
	int dosage_req;
	long quantity;
	float pop_covered;
	struct vaccine *next;
}vaccine;


typedef struct dist
{	
	char vax_code[3];	
	long quantity;
	struct dist *next;
}dist;

//function that rely on link list node
void writeToFile(FILE*fptr, vaccine *iterator);
void bubbleSort(struct dist *start);
void swap(struct dist *a, struct dist *b);
