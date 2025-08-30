#include <iostream>
using namespace std;
 class Book {
    public :
    string title ="Zycola" ;
    string author = "ali";
   
   virtual void view(){
        cout<<title << author <<endl ;

    }

 };
 class Library : public Book {

    public :
    int bookId=1235;
    void view() override{
        cout<<bookId<<endl ;

    }
 };

int main(){
    Book *b ;
    Library l;
    b = &l;
    b ->view();

    cin.get();
    return 0;
}