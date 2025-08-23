#include <iostream>
using namespace std;
 class Dog {
  public :

   void bark(string name ) ;
 };
 void Dog :: bark (string name ){
    cout<< name << endl ;
 }
int main(){
    Dog d ;
    d.bark("Max");
    return 0;
}