/*
----------------------------
    version :: v02
    c++ example.
    struct -> class
    creat by sw Kim.
----------------------------
*/

#include <iostream>
#include <cstring>

const int NAME_LEN = 20;
void MakeAccount(void);
void ShowMenu(void);
void ShowAllAccount(void);
void InputMoney(void);
void OutputMoney(void);

enum choice{
    Make=1,
    Input,
    Output,
    LookUp,
    Exit
}select;

// typedef struct{
//     int accountInfo;
//     char name[NAME_LEN];
//     int money;
// }Info;

class Account
{
private:
    int accountInfo;
    int money;
    char *cusname;

public:
    Account(int accountInfo, int money, char *name)
        : accountInfo(accountInfo), money(money) 
    {
        cusname = new char [strlen(name)+1];
        strcpy(cusname,name);
    }

    int GetAccInfo(void) {return accountInfo;}
    void Addmoney(int GetMoney) {money += GetMoney;}
    int OutMoney(int GetMoney)
    {
        if(money < GetMoney)
        {
            std::cout<<"잔고의 금액을 초과하였습니다."<<std::endl;
            std::cout<<"잔고의 금액 : "<< money <<"출금 요청금액 : "<<GetMoney<<std::endl;
            return 0;
        }
        money -= GetMoney;
    }

    void ShowAccInfo(void)
    {
        std::cout<<"계좌ID : "<<accountInfo<<std::endl;
        std::cout<<"name : "<<cusname<<std::endl;
        std::cout<<"money : "<<money<<std::endl;
        std::cout<<std::endl;
    }

    ~Account()
    {
        delete []cusname;
    }
};

Account *accArr[100];
int accNum=0;

int main()
{
    int select;
    int accountInfo,money;
    char name[50];

    while(1)
    {
        ShowMenu();
        std::cin>>select;
        
        switch(select)
        {
            case Make:
                MakeAccount();
                break;;
            case Input:
                InputMoney();
                break;;
            case Output:
                OutputMoney();
                break;;
            case LookUp:
                ShowAllAccount();
                break;;
            case Exit:
                for(int i=0; i<accNum; i++)
                {
                    delete accArr[i];
                }
                return 0;
            defualt:
                std::cout<<"Please Select Menu.."<<std::endl;
        }
    }
    return 0;
}

void MakeAccount(void)
{
    int ID,money;
    char name[NAME_LEN];

    std::cout<<"[계좌개설]"<<std::endl;

    std::cout<<"계좌ID : "; std::cin>>ID;
    std::cout<<"고객이름 : "; std::cin>>name;
    std::cout<<"money : "; std::cin>>money;

    accArr[accNum++] = new Account(ID, money, name);
}

void ShowAllAccount(void)
{
    std::cout<<std::endl;
    for(int i=0;i<accNum;i++)
    {
        accArr[i]->ShowAccInfo();
    }
}

void InputMoney(void)
{
    int ID,money;
    
    std::cout<<"계좌 번호를 입력하여 주세요."<<std::endl; std::cin>>ID;
    
    for(int i=0;i<accNum;i++)
    {
        if(accArr[i]->GetAccInfo() == ID)
        {
            std::cout<<"입금할 금액을 입력해 주세요. : "; std::cin>>money;

            accArr[i]->Addmoney(money);
            std::cout<<"Success!!"<<std::endl;
            accArr[i]->ShowAccInfo();
            return;
        }
        else
        {
            std::cout<<"조회 된 계좌번호가 없습니다."<<std::endl;
        }
    }
}

void OutputMoney(void)
{
    int ID,money;
        
    std::cout<<"계좌 번호를 입력하여 주세요."<<std::endl; std::cin>>ID;
    
    for(int i=0;i<accNum;i++)
    {
        if(accArr[i]->GetAccInfo() == ID)
        {
            std::cout<<"출금할 금액을 입력해 주세요."; std::cin>>money;
                    
            /* possible OutPut money */
            accArr[i]->OutMoney(money);
            accArr[i]->ShowAccInfo();

            return;
        }
        else
        {
            std::cout<<"조회 된 계좌번호가 없습니다."<<std::endl;
        }
    }
}
void ShowMenu(void)
{
    std::cout<<"=====Menu====="<<std::endl;
    std::cout<<"1.계좌개설"<<std::endl;
    std::cout<<"2.입금"<<std::endl;
    std::cout<<"3.출금"<<std::endl;
    std::cout<<"4.계좌정보 전체 출력"<<std::endl;
    std::cout<<"5.프로그램 종료"<<std::endl;
    std::cout<<"선택 : ";
}

