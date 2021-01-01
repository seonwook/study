#include <iostream>
#include <cstring>

class MyFriendInfo
{
private:
    char * name;
    int age;
public:
    MyFriendInfo(char* myname, int myage)
        : age(myage)
    {
        name=new char[strlen(myname)+1];
        strcpy(name,myname);
    }
    void ShowMyFriendInfo()
    {
        std::cout<<"이름 : "<<name<<std::endl;
        std::cout<<"나이 : "<<age<<std::endl;
    }
    ~MyFriendInfo()
    {
        delete []name;
    }
};

class MyFriendDetailInfo : public MyFriendInfo
{
private:
    char * addr;
    char * phone;
public:
    MyFriendDetailInfo(char * myname,int myage,char * myaddr, char * myphone)
        :   MyFriendInfo(myname, myage)
    {
        addr=new char[strlen(myaddr)+1];
        strcpy(addr,myaddr);
        phone=new char[strlen(myphone)+1];
        strcpy(phone,myphone);
    }
    void ShowMyFriendDetailInfo()
    {
        ShowMyFriendInfo();
        std::cout<<"주소 : "<<addr<<std::endl;
        std::cout<<"전화 : "<<phone<<std::endl<<std::endl;
    }
    ~MyFriendDetailInfo()
    {
        delete []addr;
        delete []phone;
    }
};

int main(void)
{
    MyFriendDetailInfo frd1("KIM",29,"서울시","010-1234-5678");
    MyFriendDetailInfo frd2("JEON",29,"서울시","010-5678-1234");
    frd1.ShowMyFriendDetailInfo();
    frd2.ShowMyFriendDetailInfo();
    return 0;
}