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

using namespace std;
const int NAME_LEN = 20;
// void MakeAccount(void);
// void ShowMenu(void);
// void ShowAccount(void);
// void InputMoney(void);
// void OutputMoney(void);

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
    void MakeAccount(void);
    void ShowMenu(void);
    void ShowAccount(void);
    void InputMoney(void);
    void OutputMoney(void);
    ~Account()
    {
        delete []cusname;
    }
};

Account *accArr[100];
int accArr[100];
int accNum=0;

int main()
{
    int select;
    int accountInfo,money;
    char name[50];

    while(1)
    {
        ShowMenu();
        cin>>select;
        
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
                ShowAccount();
                break;;
            case Exit:
                return 0;
            defualt:
                cout<<"Please Select Menu.."<<endl;
        }
    }
    return 0;
}

void MakeAccount(void)
{
    int ID,money;
    char name[NAME_LEN];

    cout<<"[계좌개설]"<<endl;

    cout<<"계좌ID : "; cin>>ID;
    cout<<"고객이름 : "; cin>>name;
    cout<<"money : "; cin>>money;

    accArr[accNum].accountInfo=ID;
    accArr[accNum].money=money;
    strcpy(accArr[accNum].name,name);
    accNum++;
}
void ShowAccount(void)
{
    cout<<endl;
    for(int i=0;i<accNum;i++)
    {
        cout<<"계좌ID : "<<accArr[i].accountInfo<<endl;
        cout<<"이름 : "<<accArr[i].name<<endl;
        cout<<"잔액 : "<<accArr[i].money<<endl<<endl;
    }
}

void InputMoney(void)
{
    int ID,money;
    
    cout<<"계좌 번호를 입력하여 주세요."<<endl; cin>>ID;
    
    for(int i=0;i<accNum;i++)
    {
        if(accArr[i].accountInfo == ID)
        {
            cout<<"입금할 금액을 입력해 주세요."; cin>>money;
            
            accArr[i].money += money;
            
            cout<<"계좌ID : "<<accArr[i].accountInfo<<endl;
            cout<<"이름 : "<<accArr[i].name<<endl;
            cout<<"잔액 : "<<accArr[i].money<<endl;

            return;
        }
        else
        {
            cout<<"조회 된 계좌번호가 없습니다."<<endl;
        }
    }
}

void OutputMoney(void)
{
    int ID,money;
        
    cout<<"계좌 번호를 입력하여 주세요."<<endl; cin>>ID;
    
    for(int i=0;i<accNum;i++)
    {
        if(accArr[i].accountInfo == ID)
        {
            cout<<"출금할 금액을 입력해 주세요."; cin>>money;
                    
            /* possible OutPut money */
            if(accArr[i].money >= money)
            {
                accArr[i].money -= money;
            }
            cout<<"계좌ID : "<<accArr[i].accountInfo<<endl;
            cout<<"이름 : "<<accArr[i].name<<endl;
            cout<<"잔액 : "<<accArr[i].money<<endl;

            return;
        }
        else
        {
            cout<<"조회 된 계좌번호가 없습니다."<<endl;
        }
    }
}
void ShowMenu(void)
{
    cout<<"=====Menu====="<<endl;
    cout<<"1.계좌개설"<<endl;
    cout<<"2.입금"<<endl;
    cout<<"3.출금"<<endl;
    cout<<"4.계좌정보 전체 출력"<<endl;
    cout<<"5.프로그램 종료"<<endl;
    cout<<"선택 : ";
}

