#include <iostream>
#include <cmath>
using namespace std;

int main() {
    
    long A , B ; 
     char  oper; 
    cin >> A  ; 
    cin >> oper ;
    
    switch (oper ){
        
        case '+'  :
          cin >> B ;
       cout<< A + B <<endl ;
       break ;
       case '-':
         cin >> B ;
       cout<< A - B << endl ;
       break ;
       case '*':
         cin >> B ;
       cout<< A * B << endl ;
       break ;
       case '/':
         cin >> B ;
       cout<< floor(A / B)  << endl ;
       break ;
       default: 
       cout << "invalid operation ! "; 
        
    }
    

    return 0;
}