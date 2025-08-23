#include <iostream>
#include <string>

using namespace std;

int main() {
    int n, x;
    cin >> n >> x;

    string multi = (x != 0 && n % x == 0) || (n != 0 && x % n == 0)? "Multiples"  : "No Multiples";  

    cout << multi << "\n";
    
    return 0;
}