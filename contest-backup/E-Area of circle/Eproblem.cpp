#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    cout << fixed <<setprecision(9);
    
    const double pi = acos(-1); 
    double R;
    cin >> R;
    double Area = pi * R * R ; 
    cout << Area <<"\n";

    return 0;

}