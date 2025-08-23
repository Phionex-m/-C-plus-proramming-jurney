#include <iostream>
using namespace std;
 class Animal {
   public :
    void eat ();
 };
 void Animal :: eat(){
    cout<< "Eating" << endl ;

 }

 class Dog {
  public :
    void bark (){

        cout << "Barking" << endl ;
    }

    
 };
 class Max : public Dog , public  Animal {


 } ;
int main(){
   Max x ;
   x.bark();
   x.eat();
   cin.get();
    return 0;
}