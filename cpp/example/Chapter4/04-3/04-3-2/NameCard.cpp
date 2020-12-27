#include <iostream>
#include <cstring>
#include "NameCard.h"

NameCard::NameCard(char * myname, char * myCompany, char * myph, int myrank)
{
    /* Name */
    int len=strlen(myname)+1;
    name=new char[len];
    strcpy(name,myname);
    
    /* Company */
    len=strlen(myCompany)+1;
    company=new char[len];
    strcpy(company,myCompany);
    
    /* Phone Number */
    len=strlen(myph)+1;
    ph=new char[len];
    strcpy(ph,myph);

    switch(myrank)
    {
        case COMP_POS::CLERK : 
            rank = "CLERK";
            break;
        case COMP_POS::SENIOR :
            rank = "SENIOR";
            break;
        case COMP_POS::ASSIST : 
            rank = "ASSIST";
            break;
        case COMP_POS::MANAGER : 
            rank = "MANAGER";
            break;
        default :
            break;
    }
}

void NameCard::ShowNameCardInfo()
{
    std::cout<<"Name: "<<name<<std::endl;
    std::cout<<"Company: "<<company<<std::endl;
    std::cout<<"Phone Number: "<<ph<<std::endl;
    std::cout<<"Rank: "<<rank<<std::endl<<std::endl;
}

NameCard::~NameCard()
{
   delete []name;
   delete []company;
   delete []ph;
   std::cout<<"Called destructor!"<<std::endl;
}