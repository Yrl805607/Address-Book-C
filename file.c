#include <stdio.h>
#include<unistd.h>
#include "file.h"

void saveContactsToFile(AddressBook *addressBook) {
  
    FILE*fp;
    if((fp=fopen("contact.csv","w")) == NULL)
    {
        fprintf(stderr,"Error opening file!\n");
        return;
    }

    for(int i=0;i<addressBook->contactCount;i++)
        fprintf(fp,"%s,%s,%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email);
    fclose(fp);

    for(int i=0;i<=100;i++)
    {
        printf("\tSaving Contacts----------> %d%%\r",i);
        fflush(stdout);
        usleep(50000);
    }    
    printf("\n\tSaved successfully!\n");
}

void loadContactsFromFile(AddressBook *addressBook) 
{
    FILE*fp;
    if((fp=fopen("contact.csv","r")) == NULL)
    {
        fprintf(stderr,"File not found!\n");
        return;
    }
    int i=0;
    while((fscanf(fp,"%[^,],%[^,],%s\n",addressBook->contacts[i].name,addressBook->contacts[i].phone,addressBook->contacts[i].email)) == 3)
    {
        addressBook->contactCount++;
        i++;
    }
    fclose(fp);
}
