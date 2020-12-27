#ifndef __NameCard_H__
#define __NameCard_H__

namespace COMP_POS
{ 
    enum{
        CLERK=0,
        SENIOR,
        ASSIST,
        MANAGER
    };
}

class NameCard
{
private :
    char * name;
    char * company;
    char * ph;
    char * rank;
public :
    NameCard(char * myname, char * myCompany, char * ph, int myrank);
    void ShowNameCardInfo();
    ~NameCard();
};

#endif