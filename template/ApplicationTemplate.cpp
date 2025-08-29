#include <iostream>
using namespace std;
template<typename y >
y Max (y n1 , y n2){
   y result = (n1 > n2) ? n1 : n2 ;
    return result ;

}
int main(){
    cout << Max(6,7)<< endl ;

    cin.get();

    return 0;
}