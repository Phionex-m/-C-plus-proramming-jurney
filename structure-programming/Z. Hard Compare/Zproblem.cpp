#include <iostream>
#include <cmath> 

using namespace std;

int main(){
    long long A , B , C , D ;
    cin >> A >> B >>  C >> D;

    double  a = B * log (A);
    double b  = D * log (C);

    if (a > b){

        cout << "YES"<< endl ;
    }

    else {
        
        cout << "NO"<< endl ;
    }

      system("pause");
    return 0;
}