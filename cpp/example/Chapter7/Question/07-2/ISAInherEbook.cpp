#include <iostream>
#include <cstring>

class Book
{
private:
    char * title;   //책의 제목
    char * isbn;    //국제표준도서번호
    int price;      //책의 정가
public:
    Book(char * mytitle, char * myisbn, int myprice)
        : price(myprice)
    {
        title=new char[strlen(mytitle)+1];
        strcpy(title,mytitle);
        isbn=new char[strlen(myisbn)+1];
        strcpy(isbn,myisbn);
    }
    void ShowBookInfo()
    {
        std::cout<<"제목: "<<title<<std::endl;
        std::cout<<"ISBN: "<<isbn<<std::endl;
        std::cout<<"가격: "<<price<<std::endl;
    }
    ~Book()
    {
        delete []title;
        delete []isbn;

    }
};

class EBook : public Book
{
private:
    char * DRMKey;  //보안관련 키
public:
    EBook(char * mytitle, char * myisbn, int myprice, char * myDRMKey)
        : Book(mytitle,myisbn,myprice)
    {
        DRMKey=new char[strlen(myDRMKey)+1];
        strcpy(DRMKey,myDRMKey);
    }
    void ShowEBookInfo()
    {
        ShowBookInfo();
        std::cout<<"인증키: "<<DRMKey<<std::endl;
    }
    ~EBook()
    {
        delete []DRMKey;
    }
};

int main(void)
{
    Book book("좋은 C++", "555-12345-890-0", 20000);
    book.ShowBookInfo();
    std::cout<<std::endl;

    EBook ebook("좋은 C++ ebook","555-12345-890-1", 10000,"fdx9w0i8kiw");
    ebook.ShowEBookInfo();
    return 0;
}