#include <iostream>
#include <chrono>
#include <thread>

using namespace std;

int main() 
{
  
  int n = 0 ; 
  
  
  
    
      
      for (int i = 5 ; i >= n ; i-- ) { 
        
      this_thread::sleep_for(chrono::seconds(1));
        cout << i << endl ; 
        
       system("cls");
        }
        
      

      
      
      this_thread::sleep_for(chrono::milliseconds(500));
      cout << " Happy new year "   << endl ;   
      
      
  
    
    
    system ("pause ") ; 
    
    return 0;
}
