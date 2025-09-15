#include <iostream>
#include "zikr.h"
#include <windows.h>


using namespace std;


void showMessage(const string& msg) {
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, msg.c_str(), -1, NULL, 0);
    wstring wmsg(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, msg.c_str(), -1, &wmsg[0], size_needed);

    MessageBoxW(NULL, wmsg.c_str(), L"اذكار", MB_OK | MB_ICONINFORMATION);
}
int main() {

   ZikrManaging zikrManager;

    if (!zikrManager.ImportZekrFromTxt()) {
        showMessage("تعذر تحميل ملف Azkar.txt");
        return 1;
    }

    
    for (const auto& z : zikrManager.getList()) {
        showMessage(z.text);
    }

    zikrManager.reset();
    return 0;
}
