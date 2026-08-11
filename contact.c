#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "contact.h"
#include "file.h"
#include "populate.h"

int arr[100],size = 0;

void listContacts(AddressBook *addressBook) 
{
    printf("Select sort criteria:\n");
    printf("1. Sort by name\n");
    printf("2. Sort by phone\n");
    printf("3. Sort by email\n");
    printf("Enter your choice: ");
    int sortChoice;
    scanf("%d", &sortChoice);
                
    Contact temp;
    switch(sortChoice)
    {
        case 1:printf("SORTING BY NAME\n");
        for(int i=0;i<addressBook->contactCount-1;i++)
    {
        
        for(int j=0;j<addressBook->contactCount-i-1;j++)
        {
            

            if(strcmp(addressBook->contacts[j].name,addressBook->contacts[j+1].name)>0)
            {
                temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j+1];
                addressBook->contacts[j+1] = temp;
            }
        }
    }
        break;
        case 2:printf("SORTING BY PHONE\n");    
        for(int i=0;i<addressBook->contactCount-1;i++)
    {
        
        for(int j=0;j<addressBook->contactCount-i-1;j++)
        {
            if(strcmp(addressBook->contacts[j].phone,addressBook->contacts[j+1].phone)>0)
            {
                temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j+1];
                addressBook->contacts[j+1] = temp;
            }
        }


    }

        break;
        case 3:printf("SORTING BY EMAIL\n");
        for(int i=0;i<addressBook->contactCount-1;i++)
    {
        
        for(int j=0;j<addressBook->contactCount-i-1;j++)
        {
            if(strcmp(addressBook->contacts[j].email,addressBook->contacts[j+1].email)>0)
            {
                temp = addressBook->contacts[j];
                addressBook->contacts[j] = addressBook->contacts[j+1];
                addressBook->contacts[j+1] = temp;
            }
        }
    }
        break;   
        default: printf("You have entered Invalid Choice, please enter a valid Choice. e.g(1,2,3)\n"); 

    }

    printf("Sr.No\tName\tPhone\tEmail\n");
    for(int i=0;i<addressBook->contactCount;i++)
    {
        printf("%d\t%s\t%s\t%s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    }
    
}

void initialize(AddressBook *addressBook) {
    addressBook->contactCount = 0;
    //populateAddressBook(addressBook);
    
    // Load contacts from file during initialization (After files)
    loadContactsFromFile(addressBook);
}

void saveAndExit(AddressBook *addressBook) {
    saveContactsToFile(addressBook); // Save contacts to file
    exit(EXIT_SUCCESS); // Exit the program
}

int validate_name(char*temp)
{
    int i=0;
    while(temp[i] != '\0')
    {
        if((temp[i]>='a' && temp[i]<='z') || (temp[i]>='A' && temp[i]<='Z') || temp[i]==' ')
        {
            i++;
        }
        else
        {
            printf("\tEntered name is invalid\n");
            return 1;
        }
    }
    return 0;
}
int validate_mobile(char*temp)
{
    int i=0;
    while(temp[i] != '\0')
    {
        if((temp[i]>='0' && temp[i]<='9'))
        {
            i++;
        }
        else
        {
            printf("\tEntered phone number is invalid\n");
            return 1;
        }
    }
    if(i>10 || i<10)
    {
        printf("\tEntered phone number is invalid\n");
        return 1;
    }
    return 0;
}
int validate_email(char*temp)
{
    if(strstr(temp,".com") == NULL)
    {
        printf("\tEntered email is invalid\n");
        return 1;
    }
    if(strchr(temp,'@') == NULL)
    {
        printf("\tEntered email is invalid\n");
        return 1;
    }
    return 0;
    
}

int unique_phone(char*temp,AddressBook*addressBook)
{
    int i;
    for(i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(addressBook->contacts[i].phone,temp)==0)
        {
            printf("\nEnter a unique phone number\n");
            return 1;
        }
    }
    return 0;
}

int unique_email(char*temp,AddressBook*addressBook)
{
    int i;
    for(i=0;i<addressBook->contactCount;i++)
    {
        if(strcmp(addressBook->contacts[i].email,temp)==0)
        {
            printf("\nEnter a unique email\n");
            return 1;
        }
    }
    return 0;
}

void createContact(AddressBook *addressBook)
{
	char temp[50];
    printf("\tMENU CREATE CONTACT\n");
    do
    {
        printf("\tEnter the name: ");
        scanf(" %[^\n]",temp);
    }while(validate_name(temp));
    strcpy(addressBook->contacts[addressBook->contactCount].name,temp);

    do
    {
        printf("\tEnter the phone number: ");
        scanf(" %[^\n]",temp);
    }while(validate_mobile(temp) | unique_phone(temp,addressBook));
    strcpy(addressBook->contacts[addressBook->contactCount].phone,temp);
    do
    {
        printf("\tEnter the email: ");
        scanf(" %[^\n]",temp);
    }while(validate_email(temp) | unique_email(temp,addressBook));
    strcpy(addressBook->contacts[addressBook->contactCount].email,temp);
    printf("\tContact created Successfully!\n");
    addressBook->contactCount++;
}



int searchContact(AddressBook *addressBook) 
{
    size=0;
    char temp[50];
    int count = 0;
    int opt;
    printf("\tMENU SEARCH CONTACT\n");
    printf("\tPress 1 for search by name\n\tPress 2 for search by phone number\n\tPress 3 for search by email\n\t");
    scanf("%d",&opt);
    
    switch(opt)
    {
        case 1:
        printf("\tSearching by name :\n");
        printf("\tEnter the name:\n\t");
        scanf(" %[^\n]",temp);

        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcasestr(addressBook->contacts[i].name,temp) != NULL)
            {
                arr[size] = i+1;
                size++;
                count++;
                printf("\t%d\t%s\t%s\t%s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            }
        }
        
        if(count == 0)
        {
            printf("\tContact not found\n");
            return 0;
        }
        return 1;
        break;
        case 2:
        printf("\tSearching by phone number :\n");
        printf("\tEnter the phone:\n\t");
        scanf(" %[^\n]",temp);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcasestr(addressBook->contacts[i].phone,temp) != NULL)
            {
                arr[size] = i+1;
                size++;
                count++;
                printf("\t%d\t%s\t%s\t%s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            }
        }
        
        if(count == 0)
        {
            printf("\tContact not found\n");
            return 0;
        }
        return 1;
        break;
        case 3:
        printf("\tSearching by email :\n");
        printf("\tEnter the email:\n\t");
        scanf(" %[^\n]",temp);
        for(int i=0;i<addressBook->contactCount;i++)
        {
            if(strcasestr(addressBook->contacts[i].email,temp) != NULL)
            {
                arr[size] = i+1;
                size++;
                count++;
                printf("\t%d\t%s\t%s\t%s\n",i+1,addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
            }
        }
        
        if(count == 0)
        {
            printf("\tContact not found\n");
            return 0;
        }
        return 1;
        break;
        default:
        printf("\tInvalid input\n");
        return 0;
    }
}

void editContact(AddressBook *addressBook)
{
    char temp[20];
    int index,opt,flag=1;
    
    printf("\tMENU EDIT CONTACT\n");
	if(searchContact(addressBook))
    {
        label:
             printf("\tEnter the index you want to edit:\n\t");
             scanf("%d",&index);
             for(int i=0;i<size;i++)
             {
                if(index == arr[i])
                {
                    flag=0;
                }
             }
             if(flag)
             {
                printf("\tYou have entered an invalid index\n");
                goto label;
             }
        
        edit:
             printf("\tPress 1 to edit name\n\tPress 2 to edit phone\n\tPress 3 to edit email\n\t");
             scanf("%d",&opt);
             
             switch(opt)
             {
                case 1:
                      do{
                        printf("\tEnter the name to edit:\n\t");
                        scanf(" %[^\n]",temp);
                        }while(validate_name(temp));
                        strcpy(addressBook->contacts[index-1].name,temp);
                        printf("\tName edited Successfully\n");

                break;
                case 2:
                       do{
                        printf("\tEnter the phone to edit:\n\t");
                        scanf(" %[^\n]",temp);
                        }while(validate_mobile(temp) | unique_phone(temp,addressBook));
                        
                        strcpy(addressBook->contacts[index-1].phone,temp);
                        printf("\tPhone edited Successfully\n");
                break;
                case 3:
                       do{
                        printf("\tEnter the email to edit:\n\t");
                        scanf(" %[^\n]",temp);
                        }while(validate_email(temp) | unique_email(temp,addressBook));
                        
                        strcpy(addressBook->contacts[index-1].email,temp);
                        printf("\tEmail edited Successfully\n");
                break;
                default:printf("\tInvalid Choice\n");
                goto edit;
             }



    }
}

void deleteContact(AddressBook *addressBook)
{
    int index,flag=1;
    char ch;
    printf("\tMENU DELETE CONTACT\n");
	if(searchContact(addressBook))
    {
        start:
             printf("\tEnter the index you want to edit:\n\t");
             scanf("%d",&index);
             for(int i=0;i<size;i++)
             {
                if(index == arr[i])
                {
                    flag=0;
                }
             }
             if(flag)
             {
                printf("\tYou have entered an invalid index\n");
                goto start;
             }

             end:
               printf("\tDelete Confirmation\n");
               printf("\t%d %s %s %s\n",index,addressBook->contacts[index-1].name,addressBook->contacts[index-1].phone,addressBook->contacts[index-1].email);
               printf("\tEnter 'Y' or 'y' for Yes & 'N' or 'n' for no\n\t");
               scanf(" %c",&ch);

               switch(ch)
               {
                case 'Y':
                case 'y':
                for(int i=index-1;i<addressBook->contactCount;i++)
                {
                    addressBook->contacts[i] = addressBook->contacts[i+1]; 
                    
                }
                addressBook->contactCount--;
                printf("\tContact deleted Successfully!\n");
                break;
                case 'N':
                case 'n':
                return;
                break;
                default:
                printf("\tEntered option is invalid\n");
                goto end;
               }
             
    }
    
    
}
