#include <iostream>
#include <string>
using namespace std ; 

int main() {
    
    string F1 , S1 ;
    cin>>F1>>S1 ;
    string F2 , S2 ;
    cin>>F2>>S2 ;
    
    string bro = (S1 == S2)? "ARE Brothers":"NOT" ;

    cout<<bro<<"\n";
    
    return 0;
}
