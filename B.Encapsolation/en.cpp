#include <iostream>
using namespace std;
 class Person {

    private :
     int age ;

     public :

     Person(int age ){
        this ->age = age ;
     }
     friend int  showAge (Person p );
     

    };
   int  showAge (Person p ){
    p.age= 20 ;
    return p.age;
  }
    
int main(){
    Person p1 (19);
     
    cout<< showAge(p1) << endl ;
    cin.get();
    return 0;
}