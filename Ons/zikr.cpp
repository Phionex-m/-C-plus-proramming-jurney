#include <iostream>
#include <fstream>
#include <chrono>
#include <thread>
#include <vector>
#include "zikr.h"


using namespace std;


 


ZikrManaging::ZikrManaging() : CurrentCount(0) {}

// memory management 
bool ZikrManaging::ImportZekrFromTxt() {

    list.clear();
    
    // This part for found the file and load it to the user and avoid any crashes and errors (try, catch)
    
        ifstream file("Azkar.txt");

        if (!file.is_open()){

            cout << "Error : File not found " << endl ;
          


        // list.push_back({"فِي ذِكْرِ اللهِ أُنْسُكِ"});
        // list.push_back({"إِلَّا بِذِكْرِ اللهِ تَطْمَئِنُ الْقُلُوبُ"});
        // list.push_back({"سُبْحَانَ اللهِ وَبِحَمْدِهِ"});
        // list.push_back({"أَسْتَغْفِرُ اللهَ الْعَظِيمَ"});
        // list.push_back({"لَا إِلَهَ إِلَّا أَنْتَ سُبْحَانَكَ إِنِّي كُنْتُ مِنَ الظَّالِمِينَ"});
        // list.push_back({"لَا تَزَالُ الْمَلَائِكَةُ مَشْغُولَةً بِبِنَاءِ قَصْرِكَ مَا دَامَ لِسَانُكَ رَطْبًا بِذِكْرِ اللهِ"});
        // list.push_back({"لَا إِلَهَ إِلَّا اللهُ وَحْدَهُ لَا شَرِيكَ لَهُ"});
        // list.push_back({"كُلُّ أَمْرٍ سَيَمُرُّ بِإِذْنِ اللهِ"});
        // list.push_back({"إِنَّ اللهَ إِذَا كَلَّفَ أَعَانَ"});
        // list.push_back({"حَسْبِيَ اللهُ لَا إِلَهَ إِلَّا هُوَ عَلَيْهِ تَوَكَّلْتُ وَهُوَ رَبُّ الْعَرْشِ الْعَظِيمِ"});
        
           return true ;

        }
        
        string zikr ;
        int lineNumber = 0 ;
        while (getline(file,zikr)){

            // cout<< zikr << endl ;

           
            //ignore empty lines or any signs 
            if (zikr.empty() ){

                continue;
            }

            Zekr zekr ;
            zekr.text = zikr ;
            list.push_back(zekr);
           
            
            lineNumber++;

        }

        file.close();

        return true ;

    }


void ZikrManaging::displayAllGradually() const {

   if(list.empty()){
    cout << "No zikr available" << endl ;

   }

   else {

   for (size_t i = 0 ; i < list.size() ; ++i){

    cout << list[i].text << endl ;

    if (i < list.size()-1){
        this_thread::sleep_for(chrono::seconds(3));

    }

   }

}
}

void ZikrManaging::reset() {
    CurrentCount = 0;
    cout << "Go to the first Zekr again"<<endl;

    if (!list.empty()) {
        cout  << list[0].text << endl;
    }
}

//الكود مطلعش نتائج محتاج تعديل فى الدوال و الحاجات بتاعته الباقى مكتوب فى الكراسة 
