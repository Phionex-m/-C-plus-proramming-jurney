#include <iostream>
#include "zikr.h"
#include <windows.h>


using namespace std;

int main() {

    SetConsoleOutputCP(CP_UTF8);
    ZikrManaging zikrManager;

    if (!zikrManager.ImportZekrFromTxt()) {
        cout << "No azkar loaded. Please check Azkar.txt" << endl;
        return 1; // ❌ خروج من البرنامج
    }

    zikrManager.displayAllGradually();
    zikrManager.reset();

    cin.get();
    return 0;
}
