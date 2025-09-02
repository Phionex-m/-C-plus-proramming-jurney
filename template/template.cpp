#include <iostream>
using namespace std;
 template < typename n >
class T {
    public :
    n name ;
 T (n name ){
    this -> name = name ;

}
n show(){
    return name ;

}
};

int main(){
    T i("Mariem");
   cout<< i.show()<<endl;
    return 0;
}