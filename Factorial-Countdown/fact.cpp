#include <iostream>
using namespace std;

<<<<<<< HEAD
int factorial  ( int n ) { 
=======
int fact ( int n ) { 
>>>>>>> 943e0c338cc3d17939033fc714cf245d3971f276

  if (n == 0 || n == 1 ){
    
    return 1  ; 
    
  }
  
  else if (n < 0 ){
    
    cout << " The negative numbers don't have factorial " << endl ; 
  }
  
    else { 
      
        
<<<<<<< HEAD
       return n * factorial(n -1);
=======
       return n * fact(n -1);
>>>>>>> 943e0c338cc3d17939033fc714cf245d3971f276
  
    } 
}
    
      
    int main() 
{
  int n ; 
  cin >> n ; 
   
<<<<<<< HEAD
  cout << factorial(n) << endl ; 
=======
  cout << fact(n) << endl ; 
>>>>>>> 943e0c338cc3d17939033fc714cf245d3971f276
    
    
    system ("pause ") ; 
    
    return 0;
}
