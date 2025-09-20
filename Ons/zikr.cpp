#include <iostream>
#include <windows.h>
#include <fstream>
#include <chrono>
#include <thread>
#include <vector>
#include "zikr.h"


using namespace std;


 // ظهرت عندى مشكلة ان لما باجى اضيف ذكر بيعمل جنبه null
 // فعملت دى عشان احل مشكلة ال Encoding للعربى
 
 string ConvertToUTF8(const string& str) {
    int size_needed = MultiByteToWideChar(CP_ACP, 0, str.c_str(), (int)str.size(), NULL, 0);
    wstring wstr(size_needed, 0);
    MultiByteToWideChar(CP_ACP, 0, str.c_str(), (int)str.size(), &wstr[0], size_needed);
    
    size_needed = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), (int)wstr.size(), NULL, 0, NULL, NULL);
    string utf8_str(size_needed, 0);
    WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), (int)wstr.size(), &utf8_str[0], size_needed, NULL, NULL);
    
    return utf8_str;
}

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
        this_thread::sleep_for(chrono::minutes(2));

    }

   }

}
}

// Method to make the user able to add zikr 
bool ZikrManaging::AddZekrToFile(const string& newZekr) {
    if (newZekr.empty()) {
        return false;
    }
ofstream file("Azkar.txt", ios::app);
    if (!file.is_open()) {
        return false;
    }

    // add new zikr to the file 
    file <<endl <<  endl << newZekr << endl;
    file.close();

    // update the file 
    return ImportZekrFromTxt();
}




void ZikrManaging::reset() {
    CurrentCount = 0;
    cout << "Go to the first Zekr again"<<endl;

    if (!list.empty()) {
        cout  << list[0].text << endl;
    }
}

