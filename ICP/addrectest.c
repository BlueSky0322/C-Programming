#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    char name[50];
    int age;
    struct Node *next;
}Node;

// user-defined functions
void printPetRecord(Node *head);
void writeToFile(FILE *fptr, Node *head);

// main()
int main(void)
{
    int count, i;
    Node *petRecord, *newRecord;
    FILE *fp;

    if( (petRecord = malloc(sizeof(Node))) == NULL )
    {
        fprintf(stderr, "Unable to allocate memory.\n");
        exit(2);
    }
    newRecord = petRecord;
    printf("How many pets do you have? ");
    scanf("%d", &count);

    for(i = 0; i < count; i++)
    {
        printf("Name of Pet: ");
        scanf("%50s", newRecord->name);
        printf("Age of Pet: ");
        scanf("%d", &newRecord->age);
        if(i == count-1)
        {
            newRecord->next = NULL;
        }
        else
        {
            if( (newRecord->next = malloc(sizeof(Node))) == NULL)
            {
                fprintf(stderr, "Memory Unavailable.\n");
                exit(3);
            }
        }
        newRecord = newRecord->next;
    }
    printf("\n\n");
    // Modified arguments
    printPetRecord(petRecord);

    // Open file before sending to writeToFile
    if(!(fp = fopen("petname.txt", "w")))
    {
        fprintf(stderr, "Unable to open file \"petname.txt\"\n");
        exit(1);
    }
    // Modified arguments
    writeToFile(fp, petRecord);
    
    fclose(fp);
    return 0;
}

// function to print linked_list
void printPetRecord(Node *head)
{
    if(head->next != NULL)
    {
        printf("Name of Pet: %s\nAge of Pet: %d\n", head->name, head->age);
        printPetRecord(head->next);
    }
    else
        printf("Name of Pet: %s\nAge of Pet: %d\n", head->name, head->age);
}

// function to print list to file
void writeToFile(FILE *fptr, Node *head)
{
    if(head->next != NULL)
    {
        fprintf(fptr, "\nPet Name: %s\nAge: %d\n\n", head->name, head->age);
        writeToFile(fptr, head->next);
    }
    else
        fprintf(fptr, "\nPet Name: %s\nAge: %d\n\n", head->name, head->age);
}

