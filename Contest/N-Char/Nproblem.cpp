#include <iostream>
#include <cctype>

using namespace std; 

int main() {
    
 char X ; 
 cin >> X ; 

if (isupper(X)){ 
    
     char lower = tolower(X);
     cout<<lower<<endl ;
     
 }
 
  else {
      
      char upper = toupper(X);
       cout<<upper<<endl ; 
       
  }
 
  

    return 0;
}