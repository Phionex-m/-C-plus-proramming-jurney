#include <iostream>
#include <fstream>

using namespace std;
//file for writing only 
int main(){
    ofstream mariemfile("D:/Mariem.txt",ios::app);
    mariemfile<<"This file is writing only"<<endl;

    mariemfile.close();
    
    ifstream mfile ("D:/Readfile.txt");
    if (mfile){
        ofstream mfile("D:/Readfile.txt",ios::app);
       mfile<<endl << "the end";

    }

    else{
         ofstream mfile("D:/Readfile.txt",ios::app);
         mfile<<"the end";
     }
     mfile.close();
    cin.get();

    return 0;
}