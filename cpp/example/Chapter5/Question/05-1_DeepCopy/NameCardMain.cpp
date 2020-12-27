#include <iostream>
#include <cstring>

namespace COMP_POS
{ 
    enum{CLERK,SENIOR,ASSIST,MANAGER};

    void ShowComPos(int pos)
    {
        switch(pos)
        {
            case CLERK : 
                std::cout<<"CLERK"<<std::endl;
                break;
            case SENIOR :
                std::cout<<"SENIOR"<<std::endl;
                break;
            case ASSIST : 
                std::cout<<"ASSIST"<<std::endl;
                break;
            case MANAGER : 
                std::cout<<"MANAGER"<<std::endl;
                break;
            default :
                break;
        }
    }
}

class NameCard
{
private :
    char * name;
    char * company;
    char * ph;
    int position;
public :
    NameCard(char * myname, char * myCompany, char * ph, int myrank)
        : position(myrank)
    {
        /* Name */
        int len=strlen(myname)+1;
        this->name=new char[len];
        strcpy(this->name,myname);
        
        /* Company */
        len=strlen(myCompany)+1;
        this->company=new char[len];
        strcpy(this->company,myCompany);
        
        /* Phone Number */
        len=strlen(ph)+1;
        this->ph=new char[len];
        strcpy(this->ph,ph);
    }
    NameCard(const NameCard & copy)
        : position(copy.position)
    {
        name=new char[strlen(copy.name)+1];
        strcpy(name,copy.name);
        company=new char[strlen(copy.company)+1];
        strcpy(company,copy.company);
        ph=new char[strlen(copy.ph)+1];
        strcpy(ph,copy.ph);
    }
    void ShowNameCardInfo()
    {
        std::cout<<"Name: "<<name<<std::endl;
        std::cout<<"Company: "<<company<<std::endl;
        std::cout<<"Phone Number: "<<ph<<std::endl;
        std::cout<<"Rank: "; COMP_POS::ShowComPos(position);
        std::cout<<std::endl;
    }
    ~NameCard()
    {
        delete []name;
        delete []company;
        delete []ph;
        std::cout<<"Called destructor!"<<std::endl;
    }
};


int main(void)
{
    NameCard manClerk("Lee", "ABCEng", "010-1111-2222", COMP_POS::CLERK);
    NameCard copy1=manClerk;
    NameCard manSENIOR("Hong", "OrangeEng", "010-3333-4444", COMP_POS::SENIOR);
    NameCard copy2=manSENIOR;

    copy1.ShowNameCardInfo();
    copy2.ShowNameCardInfo();

    return 0;
}