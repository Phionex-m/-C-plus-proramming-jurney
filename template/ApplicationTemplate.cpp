#include <iostream>

using namespace std;

template <typename T>
T myMax(T n1, T n2) {
   T result = (n1 > n2 ) ? n1  : n2;
   return result ;

}

int main(){
    cout  << myMax(5, 10) << endl;
    
    return 0;
}