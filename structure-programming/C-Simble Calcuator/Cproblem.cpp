#include <iostream>

using namespace std;

int main(){
    long long x , y ;
    cin>> x >> y ; 
    long long sum = y+x;
    long long multi = x*y;
    long long  sub = x-y;

    cout<< x <<" + "<< y <<" = "<< sum <<"\n";
    cout<< x <<" * "<< y <<" = "<<  multi <<"\n";
    cout<< x <<" - "<< y <<" = "<< sub <<"\n";
    
    return 0;
}