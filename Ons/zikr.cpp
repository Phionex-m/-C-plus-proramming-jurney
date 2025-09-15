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

    ifstream file("Azkar.txt");

    if (!file.is_open()) {
        cout << "Error: File not found!" << endl;
        return false; // ❌ رجع false لو الملف مش موجود
    }

    string line;
    while (getline(file, line)) {
        if (line.empty()) {
            continue; // تجاهل السطور الفاضية
        }

        Zekr zekr;
        zekr.text = line;
        list.push_back(zekr);
    }

    file.close();

    return !list.empty(); // ✅ رجع true لو فعلاً فيه أذكار
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
