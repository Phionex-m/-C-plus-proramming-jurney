#include <iostream>
#include "zikr.h"



using namespace std;

int main(){
 ZikrManaging zikrManager ;



cout << zikrManager. ImportZekrFromTxt() << endl ;

zikrManager.displayAllGradually();

zikrManager.reset();


 


    cin.get();
    return 0;
}