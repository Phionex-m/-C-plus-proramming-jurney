#include <iostream>
#include "implement.h"

using namespace std ;

int main (){


    Rectangle r1(6 , 5);
    cout <<"The area of rectangle : " << r1.getArea() << endl ;
    cout <<"The area of rectangle : " << r1.getPeremiter() << endl ;

    Point p1 = { 0 , 0 };
    Point p2 = { 3 , 4 };
    cout <<"Distance between the points " << distance(p1,p2) << endl ;
    
    Circle c1(4.6 ,GREEN);
    cout << "Circle Area : " << c1.getArea() << endl ;

    cout<< "Circle Color : " << c1.getColor() << endl ;

    cin.get() ;

    return 0 ;
    
}