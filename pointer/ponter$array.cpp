#include <iostream>
using namespace std;

int main(){
    int x [3] = { 1 , 2 , 3 } ;
    
    int* point = &x[0] ;
     *point = 4  ;
    cout << *point << endl << endl  ;

  for ( int i = 0 ; i < 3 ; i ++ ){
     
   cout << x[i] << endl ; 
  }
    system("pause");
    return 0;
}