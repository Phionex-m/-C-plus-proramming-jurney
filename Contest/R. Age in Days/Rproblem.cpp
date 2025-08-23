#include <iostream>
#include <cmath>
using namespace std;

int main(){
    long N ;
    cin>> N ;
    double year = floor( N / 365);
    cout << year <<" years" <<endl;
     long  remind = N % 365 ;
    
     double month = floor(remind / 30 );
     cout << month <<" months"<<endl;
    long  re = remind % 30 ;
    long day = re ;
    cout << re <<" days" << endl ;

  
    return 0;
    }