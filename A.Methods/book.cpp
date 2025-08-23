#include <iostream>
using namespace std;
  class Book {
    public:
    string name ;
    int year ;
    string author ;

  };
   
int main(){
    Book b1 ;
    cin >> b1.author >> b1.name >> b1.year  ;
    cout << b1.author << "," << b1.year << endl << b1.name ;

    system("pause");
    return 0;
}