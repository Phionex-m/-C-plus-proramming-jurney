#include <iostream>
using namespace std;
  class  Shape {
 public :
 double length = 5 ;
 double radius = 8;
 double width = 3 ;
 double base = 5  ;
 double height = 9;

 virtual void  area1 (){
    cout << length <<radius<< width<< endl ;

 }
    //  Shape (double l , double r , double w ){

    //     l=length;
    //     w=width;
    //     r = radius;
    //  }

};

class Circle : public Shape {

 public :
 double arae = radius*radius*3.14;
 void area1 () override {
        cout << "Area of circle = " << arae << endl;

}
};

class Rec : public Shape {

 public :
 double arae2 =(length + width)*2 ;

 void area1 () override{
    cout<< "Area of Rectangle  = " << arae2 << endl ;
 }

};

class Triangle : public Shape {

 public :
 double arae3 =0.5 * base * height ;
  
 void area1 () override{
    cout<< "Area of Triangle  = " << arae3 << endl ;
 }

};



int main(){

    Shape *s;
    Circle c ;
    s=&c;
    s -> area1();

    Shape *s1;
    Rec r ;
    s1=&r;
    s1 -> area1();

    Shape *s2;
   Triangle t ;
    s2 =&t;
    s2 -> area1();

cin.get();
    
    return 0;
}