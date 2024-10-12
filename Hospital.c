#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Node
{
    char name[20];
    int ID;
    struct Node *next;
};
struct Node *head = NULL;
void InsertData(char name[], int roll);
void DisplayData();
int main()
{

    struct Node patient;
    int number;
    printf("\n Enter the number of patients: ");
    scanf("%d", &number);
    for (int i = 0; i < number; i++)
    {
        printf("%d)", i + 1);
        printf("Enter the name of the patient: ");
        scanf("%s", patient.name);
        printf("\n Enter the reservation ID of the pateints: ");
        scanf("%d", &patient.ID);
        InsertData(patient.name, patient.ID);
        printf("\n");
    }
    DisplayData();
    return 0;
}
void InsertData(char name[], int ID)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    strcpy(newNode->name, name);                                                                                                                                                 
    newNode->ID = ID;

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newNode;
    }

}
void DisplayData()
{
    struct Node *temp = head;
    printf("\nPatient Details: \n");
    while (temp != NULL)
    {
        printf("{Patient Name: %s}\n{Patient ID: %d}\n \n", temp->name, temp->ID);
        temp = temp->next;
    }
    printf("\n");
}