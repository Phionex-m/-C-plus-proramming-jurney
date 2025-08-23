#include <iostream>
#include <cmath> 
using namespace std;

class Calculator {
  public :  
   int x = 0 ; 
   int n = 0 ; 
   int sum = 0 ; 
   int multi = 0 ; 
   int  sub = 0  ; 
   int  divi = 0 ; 
   Calculator (){
     cin >> x >> n ; 
     
       sum = x + n ; 
       multi  = x * n ; 
       sub = x - n ; 
     
       
      if (n != 0 ) { 
          divi = float (x / n);
      } 
      else {
        
      
            cout << "Division by zero not found " << endl ; 
            
      }
      cout << sum << endl << multi << endl << sub  << endl; 
      
   }
}; 

int main() 
{
  Calculator c1 ; 
  
    return 0;
}