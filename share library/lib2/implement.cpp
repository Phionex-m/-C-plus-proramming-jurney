#include <iostream>
#include "implement.h"
#include <cmath>

Circle :: Circle(double r , Color  c ) : radius(r) , color(c) {}
double Circle :: getArea() const {

    return PI * radius * radius ;

}
string Circle :: getColor() const {

    switch(color){

        case RED : return "Red" ;
        case GREEN : return "Green" ;
        case BLUE : return "Blue" ;
       
    }

    return "unknown" ;

} 

double distance(const  Point& p1 ,const  Point& p2){

    int dx = p1.x - p2.x ;
    int dy = p1.y - p2.y ;

    return sqrt(dx*dx + dy*dy);

}