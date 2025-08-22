#include <iostream>
#include <cctype>
#include <string> 

using namespace std; 

int main() {
    
 char X ; 
 cin >> X ; 

if (isdigit(X)){
    
    cout<<"IS DIGIT"<<endl;
    
}
 else if (isalpha(X)&&isupper(X)){ 
     
     cout<<"ALPHA"<<endl<<"IS CAPITAL";
     
 }
  else {
      
       cout<<"ALPHA"<<endl<<"IS SMALL"; 
  }
 
  

    return 0;
}