#include <iostream>
using namespace std;

int main() {
 long long  N , M;
    
    cin >> N >> M ; 
    
    
  if (N < 10 && M <10){
      
    int sum = N+M ; 
        cout <<sum<<"\n";
        
    }
    
  else {
    int  lastnum1  = N % 10;
    int  lastnum2  = M % 10;
    int sum2 = lastnum1 + lastnum2;
    cout << sum2 <<"\n";
    }
    

    return 0;
}

