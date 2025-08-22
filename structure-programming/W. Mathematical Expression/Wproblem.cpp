#include <iostream>
#include <string>


using namespace std;

int main(){
    long    A , B , C  ;
    char Q = '=' ;
    char S ;
    cin >> A >> S >> B >> Q >> C ;
    bool right = false ;

    switch (S){
        case '+' :
         right =  (A + B == C) ;
       break;

       case '-' :
         right =  (A - B == C ) ;
       break;

       case '*' :
         right =  (A * B == C) ;
       break;
    }

    
  if (right){

    cout << "Yes" << endl ;

  }

    else if (S == '+'){
         cout << A + B << endl  ;

    }
    
    else if(S == '*') {
          cout << A * B << endl ;

    }

    else if(S == '-') {
          cout << A - B << endl ;

    }
  
    
  
    

    system("pause");
    return 0;
}