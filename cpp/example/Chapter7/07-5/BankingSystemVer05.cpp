/*
----------------------------
    version :: v05
    c++ example.
    AccountHandler라는 이름의 컨트롤 클래스 정의
    creat by sw Kim.
----------------------------
*/

#include <iostream>
#include <cstring>

const int NAME_LEN = 20;
enum {Make=1,Input,Output,LookUp,Exit};

/* 
    클래스 이름 : Account
    클래스 유형 : Entity 클래스
*/
class Account
{
private:
    int accountInfo;
    int money;
    char *cusname;
public:
    Account(int accountInfo, int money, char *name);    
    Account(const Account & copy);
    int GetAccInfo(void) const;
    void Addmoney(int GetMoney);
    int OutMoney(int GetMoney);
    void ShowAccInfo(void) const;
    ~Account();
};

Account::Account(int accountInfo, int money, char *name)
    : accountInfo(accountInfo), money(money) 
{
    cusname = new char [strlen(name)+1];
    strcpy(cusname,name);
}

Account::Account(const Account & copy) 
    : accountInfo(copy.accountInfo), money(copy.money)
{
    cusname = new char [strlen(copy.cusname)+1];
    strcpy(cusname,copy.cusname);
}

int Account::GetAccInfo(void) const {return accountInfo;}
void Account::Addmoney(int GetMoney) {money += GetMoney;}
int Account::OutMoney(int GetMoney)
{
    if(money < GetMoney)
    {
        std::cout<<"잔고의 금액을 초과하였습니다."<<std::endl;
        std::cout<<"잔고의 금액 : "<< money <<"출금 요청금액 : "<<GetMoney<<std::endl;
        return 0;
    }
    money -= GetMoney;
}
void Account::ShowAccInfo(void) const
{
    std::cout<<"계좌ID : "<<accountInfo<<std::endl;
    std::cout<<"name : "<<cusname<<std::endl;
    std::cout<<"money : "<<money<<std::endl;
    std::cout<<std::endl;
}
Account::~Account()
{
    delete []cusname;
}

/* 
    클래스 이름 : AccountHandler
    클래스 유형 : 컨트롤(Control) 클래스
*/

class AccountHandler
{
private:
    Account * accArr[100];
    int accnum;
public:
    AccountHandler();
    void ShowMenu(void);
    void MakeAccount(void);
    void ShowAllAccount(void);
    void InputMoney(void);
    void OutputMoney(void);
    ~AccountHandler();
};
AccountHandler::AccountHandler() : accnum(0)
{}
void AccountHandler::ShowMenu(void)
{
    std::cout<<"=====Menu====="<<std::endl;
    std::cout<<"1.계좌개설"<<std::endl;
    std::cout<<"2.입금"<<std::endl;
    std::cout<<"3.출금"<<std::endl;
    std::cout<<"4.계좌정보 전체 출력"<<std::endl;
    std::cout<<"5.프로그램 종료"<<std::endl;
    std::cout<<"선택 : ";
}
void AccountHandler::MakeAccount(void)
{
    int ID,money;
    char name[NAME_LEN];

    std::cout<<"[계좌개설]"<<std::endl;
    std::cout<<"계좌ID : "; std::cin>>ID;
    std::cout<<"고객이름 : "; std::cin>>name;
    std::cout<<"money : "; std::cin>>money;

    accArr[accnum++] = new Account(ID, money, name);
}
void AccountHandler::ShowAllAccount(void)
{
    std::cout<<std::endl;
    for(int i=0;i<accnum;i++)
    {
        accArr[i]->ShowAccInfo();
    }
}
void AccountHandler::InputMoney(void)
{
    int ID,money;
    
    std::cout<<"계좌 번호를 입력하여 주세요."<<std::endl; std::cin>>ID;
    
    for(int i=0;i<accnum;i++)
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
void AccountHandler::OutputMoney(void)
{
    int ID,money;
        
    std::cout<<"계좌 번호를 입력하여 주세요."<<std::endl; std::cin>>ID;
    
    for(int i=0;i<accnum;i++)
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
AccountHandler::~AccountHandler()
{
    for(int i;i<accnum;i++)
        delete accArr[i];
}

/* 
    컨트롤 클래스 AccountHandler 중심으로 변경된 Main 함수
*/

int main()
{
    AccountHandler handler;
    int select;

    while(1)
    {
        handler.ShowMenu();
        std::cin>>select;
        switch(select)
        {
            case Make:
                handler.MakeAccount();
                break;;
            case Input:
                handler.InputMoney();
                break;;
            case Output:
                handler.OutputMoney();
                break;;
            case LookUp:
                handler.ShowAllAccount();
                break;;
            case Exit:
                return 0;
            defualt:
                std::cout<<"Please Select Menu.."<<std::endl;
        }
    }
    return 0;
}