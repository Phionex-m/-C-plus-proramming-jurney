#include <iostream>
#include "math_utile.h"
using namespace std;

int add (int num1 , int num2 ){
    return num1 + num2;

}
int multi(int n1 , int n2){

    return n1 * n2 ;

}

// without pragma the compilor using bading 
struct Test1
{
    char a ; //1 byte 
    int b ; // 4 byte 
    double c ; // 8 byte
};

//Using pragma to show the fixed size with aline without exceeds  
#pragma pack(push , 1)
struct Test2 {

    char a ; //1 byte 
    int b ; // 4 byte 
    double c ; // 8 byte
};
#pragma pack(pop)

int main(){
    nd num1 = 5 , num2 = 8 ;
   cout <<  add(num1 , num2)<<endl ;
  nd n1 = 2 , n2 = 3 ;
  cout << multi(n1 , n2) << endl ;
  cout << "Size of Test1 " << sizeof(Test1)<<endl;
  cout << "Size of Test2 " << sizeof(Test2)<<endl;


    return 0;
}