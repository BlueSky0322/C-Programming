char getVaxCode(){
	char vaxCode[3]; 
	
	printf("Please input vaccine code: ");
	fflush(stdin);
	scanf("%s", vaxCode);
	getchar();
	return vaxCode;
}
