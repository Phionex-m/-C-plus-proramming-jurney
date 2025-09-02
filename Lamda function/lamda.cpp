#include <iostream>
#include <functional>
using namespace std;

void myfunction(function <void()> func){
    func();
}
// [capture] (parameter) {code}
int main(){
    
    int x = 10;
    auto message = [x](){
        cout << x << endl; 
    };
    x = 50 ; 
    myfunction(message) ; 
    system("pause");
    return 0;
}