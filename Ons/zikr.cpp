#include <iostream>
#include <windows.h>
#include <fstream>
#include <chrono>
#include <thread>
#include <vector>
#include "zikr.h"


using namespace std;



ZikrManaging::ZikrManaging() : CurrentCount(0) {}

// memory management 
bool ZikrManaging::ImportZekrFromTxt() {
    ifstream file("Azkar.txt");
    
    // If file doesn't exist, create with default azkar
    if (!file.is_open()) {
        ofstream createFile("Azkar.txt");
        if (createFile) {
            vector<string> defaultAzkar = {
                "سبحان الله",
                "الحمد لله", 
                "الله أكبر",
                "لا إله إلا الله",
                "أستغفر الله"
            };
            
            for (const auto& zekr : defaultAzkar) {
                createFile << zekr << endl;  // Each on new line
            }
            createFile.close();
            
            file.open("Azkar.txt");
        }
    }
    
    if (!file.is_open()) {
        return false;
    }
    
    list.clear();
    string line;
    
    while (getline(file, line)) {
        // Trim whitespace from each line
        size_t start = line.find_first_not_of(" \t\n\r");
        if (start == string::npos) continue; // Skip empty lines
        
        size_t end = line.find_last_not_of(" \t\n\r");
        string trimmed = line.substr(start, end - start + 1);
        
        if (!trimmed.empty()) {
            Zekr zekr;
            zekr.text = trimmed;
            list.push_back(zekr);
        }
    }
    
    file.close();
    return true;
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
    // Step 1: Check if input is empty
    if (newZekr.empty()) {
        return false;
    }
    
    // Step 2: Trim whitespace from beginning and end
    string trimmed = newZekr;
    
    // Remove spaces from start
    size_t start = trimmed.find_first_not_of(" \t\n\r");
    if (start != string::npos) {
        trimmed = trimmed.substr(start);
    }
    
    // Remove spaces from end
    size_t end = trimmed.find_last_not_of(" \t\n\r");
    if (end != string::npos) {
        trimmed = trimmed.substr(0, end + 1);
    }
    
    // Step 3: Check if it's empty after trimming
    if (trimmed.empty()) {
        return false;
    }
    
    // Step 4: Add to memory list
    Zekr newZekrObj;
    newZekrObj.text = trimmed;
    list.push_back(newZekrObj);
    
    // Step 5: Append to file (IMPORTANT: use ios::app for append mode)
    ofstream file("Azkar.txt", ios::app);  // ios::app means append to end of file
    if (!file.is_open()) {
        return false;
    }
    
    // Step 6: Write the trimmed text to file
    file << trimmed << endl;
    file.close();
    
    return true;
}



void ZikrManaging::reset() {
    CurrentCount = 0;
    cout << "Go to the first Zekr again"<<endl;

    if (!list.empty()) {
        cout  << list[0].text << endl;
    }
}

