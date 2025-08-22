#include <iostream>
#include <string>


using namespace std;

int main(){
    int   A , B ;
    char S ;
    cin >> A >> S >> B;
    bool right = false ;

    switch (S){
        case '<' :
         right =  (A < B) ;
       break;

       case '>' :
         right =  (A > B) ;
       break;

       case '=' :
         right =  (A == B) ;
       break;
    }

    string compare = (right? "Right" : "Wrong");

    cout << compare << endl ;

    system("pause");
    return 0;
}