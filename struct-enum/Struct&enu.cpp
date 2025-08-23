#include <iostream>
#include <vector>
using namespace std;
enum Status  {AVALIABLE , LOST , BORROWED }; 

 struct book 
 {
    int id ;
    string title ;
    Status status ;
 };
 

int main(){
   vector<book>B;
   // n is number of books , m is the status 
   int n , m ;

   cin >> n ;
    for (int i= 0 ; i < n ; i++){
        book b;
        cin >> b.id;
        cin >> b.title;

        B.push_back(b);
    }


    return 0;
}