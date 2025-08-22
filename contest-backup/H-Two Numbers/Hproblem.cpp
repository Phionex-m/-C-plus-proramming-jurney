#include <iostream>
#include <cmath>

using namespace std; 

int main() {
    
  double  A ,B  ;
   cin >> A >> B ; 
   double  div = A / B ; 
    
    double  floorResult = floor(div);
    double  roundResult = round(div);
    double  ceilResult = ceil(div);
    
    cout<<"floor "<<A<<" / "<<B<<" = "<<floorResult<<"\n"; 
    cout<<"ceil "<<A<<" / "<<B<<" = "<<ceilResult<<"\n"; 
    cout<<"round "<<A<<" / "<<B<<" = "<<roundResult<<"\n"; 
    


    return 0;
}