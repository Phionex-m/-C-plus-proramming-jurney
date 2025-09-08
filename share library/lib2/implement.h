#if !defined(IMPLEMENT_H)
#define IMPLEMENT_H

#include <string>
#include <iostream>

using namespace std ;

const double PI = 3.14 ;

enum Color {
   
    RED,
    GREEN ,
    BLUE 
};

# pragma pack (push,1)
struct Point {

    int x ; 
    int y ;

};
#pragma pack(pop)

class Circle {

    private :
    double radius ;
    Color color ;

    public :

    Circle (double r , Color c );

    double getArea () const;
    string getColor () const ;

    //const for mke the method save without change anything 

};

double distance(const  Point& p1 ,const  Point& p2);



#endif // IMPLEMENT_H
