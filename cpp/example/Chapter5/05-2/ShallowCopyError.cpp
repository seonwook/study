/* 
    얕은 복사 Error 예제.
    두개의 객체가 참조하는 값이 같으므로 한 객체가 소멸되면
    그것을 참조하고 있던 다른 객체는 소멸될 떄 소멸 될 참조자(이미 소멸되어 버렸으니 없다)가 없으니 Error를 발생한다.
    이것을 해결하기 위해서 깊은 복사 즉, 객체를 복사할 때 참조자 까지 복사하여 해결한다.
 */

#include <iostream>
#include <cstring>

class Person
{
private:
    char * name;
    int age;
public:
    Person(char * myname, int myage)
    {
        int len=strlen(myname)+1;
        name=new char[len];
        strcpy(name,myname);
        age=myage;
    }
    /* 깊은 복사를 위한 부분 추가 */
    Person(const Person & copy)
        : age(copy.age)
    {
        name=new char[strlen(copy.name)+1];
        strcpy(name,copy.name);
    }
    void ShowPersonInfo() const
    {
        std::cout<<"이름 : "<<name<<std::endl;
        std::cout<<"나이 : "<<age<<std::endl;
    }
    ~Person()
    {
        delete [] name;
        std::cout<<"Called destructor!"<<std::endl;
    }
};

int main(void)
{
    Person man1("Lee dong woo",29);
    Person man2=man1;
    man1.ShowPersonInfo();
    man2.ShowPersonInfo();
    return 0;
}