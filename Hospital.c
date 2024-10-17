#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int appointmentID = 1110;
int serialNumber = 1;
int appointmentRemaining = 99;

struct Node
{
    char name[30];
    char address[50];
    char phoneNumber[20];
    char disease[50];
    struct Node *next;
};

struct Node *head = NULL;

void InsertData(char name[], char address[], char phoneNumber[], char disease[]);
void CancelAppointment(char name[]);
void DisplayData();

int main()
{
    struct Node patient;
    int choice;

    printf("* * * * * * * * * * * * * * *  ");
    printf("\n*  WELCOME TO NIELIT CLINIC *\n");
    printf("* * * * * * * * * * * * * * * ");
    while (1)
    {
        printf("\n Choose an option 1 to 3");
        printf("\n 1) Fix an appointment");
        printf("\n 2) Cancel an appointment");
        printf("\n 3) Display appointment details");
        printf("\n 4) Exit choice:");
        printf("\n Enter your choice from 1-4:- ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            if (appointmentRemaining == 0)
            {
                printf("\n APPOINTMENT SLOT IS FULL...");
            }
            else
            {
                printf(" Enter the name of the patient: ");
                scanf("%s", patient.name);
                printf(" Enter your address: ");
                scanf("%s", patient.address);
                printf(" Enter your phone number: ");
                scanf("%s", patient.phoneNumber);
                printf(" Enter your disease: ");
                scanf("%s", patient.disease);
                InsertData(patient.name, patient.address, patient.phoneNumber, patient.disease);
                printf("\n ********* %s, your reservation has been set successful *********\n", patient.name);
                serialNumber++;
                appointmentRemaining--;
                break;
            }
        case 2:
            printf("Enter the name of the patient: ");
            scanf("%s", &patient.name);
            CancelAppointment(patient.name);
        case 3:
            DisplayData();
            break;
        case 4:
            printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
            printf("\n* THANK YOU FOR CHOSING OUR CLINIC. YOUR HEALTH IS OUR SERVICE :) *");
            printf("\n* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *");
            return 0;
        default:
            printf("\n---Invalid choice! Please try again.---\n");
            break;
        }
    }
    return 0;
}

void InsertData(char name[], char address[], char phoneNumber[], char disease[])
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    struct Node *temp = head;
    strcpy(newNode->name, name);
    strcpy(newNode->address, address);
    strcpy(newNode->phoneNumber, phoneNumber);
    strcpy(newNode->disease, disease);
    newNode->next = NULL;

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

void CancelAppointment(char name[])
{
    struct Node *temp = head;
    struct Node *prev = NULL;

    if (temp != NULL && strcmp(temp->name, name) == 0)
    {
        head = temp->next;
        free(temp);
        printf("\n[ ---'%s',your appointment has been cancelled successfully --- ]\n", name);
        appointmentRemaining++;
        return;
    }

    while (temp != NULL && strcmp(temp->name, name) != 0)
    {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL)
    {
        printf("\n");
        printf("[ ---OPPS, no appointment fot '%s' found--- ]", name);
        printf("\n");
        printf("\n");
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("\n[ ---'%s',your appointment has been cancelled successfully --- ]\n", name);
    appointmentRemaining++;
}

void DisplayData()
{
    struct Node *temp = head;
    int currentSerialNumber = 1;
    int currentAppointmentID = 1110;
    int remainingAppointments = 99;

    if (temp == NULL)
    {
        printf("\n ---APPOINTMENT LISTS EMPTY---\n");
        return;
    }
    else
    {
        printf("\n* * * * * * * * * *");
        printf("\n* Patient Details *");
        printf("\n* * * * * * * * * *\n\n");

        while (temp != NULL)
        {
            printf("Serial Number: %d", currentSerialNumber);
            printf("\n-----------------------------------------------\n");
            printf("\tPatient's ID:           %d", currentAppointmentID);
            printf("\n\tPatient's Name:        %s", temp->name);
            printf("\n\tPatient's Address:     %s", temp->address);
            printf("\n\tPhone Number:          %s", temp->phoneNumber);
            printf("\n\tDisease:               %s", temp->disease);
            printf("\n\tAppointment remaining: %d", remainingAppointments);
            printf("\n-----------------------------------------------\n");
            temp = temp->next;
            currentSerialNumber++;
            currentAppointmentID++;
            remainingAppointments--;
        }
    }
    printf("\n");
}
