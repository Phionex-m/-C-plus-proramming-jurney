#include <iostream>
using namespace std;

int main(){
double  N ; 
cin >> N ; 
int i =(int)N  ; 
float a = N - i  ; 
if (a < 0.00001 ){
   
  cout << "int" << " " << i << endl ; 
   
 }
 
 else {
    
   cout << "float" << " " << i  << " " << a <<  endl ;  
 }
    
system("pause");
    return 0;
}