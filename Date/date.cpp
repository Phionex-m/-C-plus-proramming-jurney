#include <iostream>
#include <ctime>

using namespace std;

int main(){

  //To show the current date and time 
    time_t currentTime ;
    time(&currentTime);
    char output[50] ;
     struct tm* currentTM = localtime(&currentTime);
    strftime(output, 50, "%I", currentTM);
    cout<<endl <<"Hours in 12h system is  "<<output<<endl<<endl<< "The current date is "<< ctime(&currentTime)<<endl;
      
  //converse timestamp into datetime structure 

    struct tm datee = *localtime(&currentTime);
    //cout << asctime(&datee);
    cout<<"The numbers of year from creating this system "<<datee.tm_year<<endl;

   //To show a specific time and date 

 struct  tm STm ;
 time_t SpecificTM ;
 STm.tm_mon=4;
 STm.tm_mday=10;
 STm.tm_year=2006-1900;
 STm.tm_hour=3;
 STm.tm_min=30;
 STm.tm_sec=55;
 STm.tm_isdst=-1;

  //mktime To converse the datetime struct to timestamp

 SpecificTM = mktime(&STm);
  // cout << asctime(&STm);
 
 cout<<endl<< "A specific date I choose "<< ctime(&SpecificTM)<<endl ; 

   // cout << output << endl;


    cin.get();
    return 0;
}