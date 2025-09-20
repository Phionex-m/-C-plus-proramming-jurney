#include <windows.h>
#include <string>
#include <vector>
#include "zikr.h"
#include <thread>
#include <chrono>

using namespace std;

// Global variables
ZikrManaging zikrManager;
HWND g_hwnd;
HWND g_hTextDisplay;
HWND g_hAddZekrEdit;
HWND g_hAddZekrButton;
HWND g_hTrayButton;
int g_currentZekrIndex = 0;
bool g_isRunningInTray = false;
thread g_trayThread;
bool g_trayIconAdded = false;

// Convert string to wstring
wstring StringToWString(const string& str) {
    int size_needed = MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, NULL, 0);
    wstring wstr(size_needed, 0);
    MultiByteToWideChar(CP_UTF8, 0, str.c_str(), -1, &wstr[0], size_needed);
    return wstr;
}

// Convert wstring to string
string WStringToString(const wstring& wstr) {
    int size_needed = WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, NULL, 0, NULL, NULL);
    string str(size_needed, 0);
    WideCharToMultiByte(CP_UTF8, 0, wstr.c_str(), -1, &str[0], size_needed, NULL, NULL);
    return str;
}

// Function to show tray notification
void ShowTrayNotification(const wstring& message) {
    NOTIFYICONDATAW nid = {};
    nid.cbSize = sizeof(NOTIFYICONDATAW);
    nid.hWnd = g_hwnd;
    nid.uID = 1; // Unique identifier for the icon
    nid.uFlags = NIF_INFO | NIF_TIP;
    nid.dwInfoFlags = NIIF_INFO; // Removed NIIF_LARGE_ICON
    nid.uTimeout = 5000; // 5 seconds
    
    wcscpy_s(nid.szInfo, message.c_str());
    wcscpy_s(nid.szInfoTitle, L"أذكار المسلم");
    wcscpy_s(nid.szTip, L"أذكار المسلم - تشغيل العائمة");
    
    // Add icon if not already added
    if (!g_trayIconAdded) {
        nid.uFlags |= NIF_ICON;
        nid.hIcon = LoadIcon(NULL, IDI_INFORMATION);
        Shell_NotifyIconW(NIM_ADD, &nid);
        g_trayIconAdded = true;
    } else {
        Shell_NotifyIconW(NIM_MODIFY, &nid);
    }
}

// Function to remove tray icon
void RemoveTrayIcon() {
    if (g_trayIconAdded) {
        NOTIFYICONDATAW nid = {};
        nid.cbSize = sizeof(NOTIFYICONDATAW);
        nid.hWnd = g_hwnd;
        nid.uID = 1;
        Shell_NotifyIconW(NIM_DELETE, &nid);
        g_trayIconAdded = false;
    }
}

// Function to run in tray mode
void RunInTrayMode() {
    // Show initial notification
    MessageBoxW(g_hwnd, L"بدأ تشغيل العائمة. ستظهر الإشعارات كل دقيقة.", L"أذكار المسلم", MB_OK | MB_ICONINFORMATION);
    
    while (g_isRunningInTray) {
        const vector<Zekr>& azkarList = zikrManager.getList();
        if (!azkarList.empty()) {
            wstring wtext = StringToWString(azkarList[g_currentZekrIndex].text);
            
            // Use MessageBox for notifications instead of tray notifications
            MessageBoxW(g_hwnd, wtext.c_str(), L"ذكر", MB_OK | MB_ICONINFORMATION);
            
            g_currentZekrIndex = (g_currentZekrIndex + 1) % azkarList.size();
        }
        
        // انتظر دقيقة واحدة قبل عرض الذكر التالي (60 ثانية)
        for (int i = 0; i < 60 && g_isRunningInTray; i++) {
            this_thread::sleep_for(chrono::seconds(1));
        }
    }
    
    // Remove tray icon when exiting tray mode
    RemoveTrayIcon();
}

// Window procedure
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
    // Load azkar
    if (!zikrManager.ImportZekrFromTxt()) {
        MessageBoxW(NULL, L"تعذر تحميل ملف Azkar.txt", L"خطأ", MB_OK | MB_ICONERROR);
    }

    // Register the window class
    const wchar_t CLASS_NAME[] = L"Zikr Window Class";

    WNDCLASSW wc = {};
    wc.lpfnWndProc = WindowProc;
    wc.hInstance = hInstance;
    wc.lpszClassName = CLASS_NAME;
    wc.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);

    RegisterClassW(&wc);

    // Create the window
    HWND hwnd = CreateWindowExW(
        0,
        CLASS_NAME,
        L"أذكار المسلم",
        WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, CW_USEDEFAULT, 700, 550,
        NULL,
        NULL,
        hInstance,
        NULL
    );

    if (hwnd == NULL) {
        return 0;
    }

    g_hwnd = hwnd;

    // Create text display area
    g_hTextDisplay = CreateWindowW(
        L"STATIC",
        L"",
        WS_CHILD | WS_VISIBLE | SS_CENTER | SS_CENTERIMAGE | WS_BORDER,
        50, 50, 600, 150,
        hwnd,
        NULL,
        hInstance,
        NULL
    );

    // Create next button
    CreateWindowW(
        L"BUTTON",
        L"التالى",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_DEFPUSHBUTTON,
        150, 220, 100, 30,
        hwnd,
        (HMENU)1,
        hInstance,
        NULL
    );

    // Create reset button
    CreateWindowW(
        L"BUTTON",
        L"إعادة",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        270, 220, 100, 30,
        hwnd,
        (HMENU)2,
        hInstance,
        NULL
    );

    // Create tray mode button
    g_hTrayButton = CreateWindowW(
        L"BUTTON",
        L"تشغيل كعائمة",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        390, 220, 100, 30,
        hwnd,
        (HMENU)8,
        hInstance,
        NULL
    );

    // Create label for adding new zekr
    CreateWindowW(
        L"STATIC",
        L"إضافة ذكر جديد:",
        WS_CHILD | WS_VISIBLE,
        50, 270, 200, 25,
        hwnd,
        NULL,
        hInstance,
        NULL
    );

    // Create edit control for new zekr
    g_hAddZekrEdit = CreateWindowW(
        L"EDIT",
        L"",
        WS_CHILD | WS_VISIBLE | WS_BORDER | ES_AUTOHSCROLL,
        50, 300, 400, 25,
        hwnd,
        NULL,
        hInstance,
        NULL
    );

    // Create button to add new zekr
    g_hAddZekrButton = CreateWindowW(
        L"BUTTON",
        L"إضافة",
        WS_TABSTOP | WS_VISIBLE | WS_CHILD | BS_PUSHBUTTON,
        460, 300, 100, 25,
        hwnd,
        (HMENU)3,
        hInstance,
        NULL
    );

    // Create menu bar
    HMENU hMenu = CreateMenu();
    HMENU hFileMenu = CreateMenu();
    HMENU hZekrMenu = CreateMenu();

    AppendMenuW(hFileMenu, MF_STRING, 4, L"إعادة تحميل الأذكار");
    AppendMenuW(hFileMenu, MF_STRING, 5, L"خروج");
    
    AppendMenuW(hZekrMenu, MF_STRING, 6, L"عرض كل الأذكار");
    AppendMenuW(hZekrMenu, MF_STRING, 7, L"إضافة ذكر جديد");
    AppendMenuW(hZekrMenu, MF_STRING, 9, L"تشغيل كعائمة");

    AppendMenuW(hMenu, MF_POPUP, (UINT_PTR)hFileMenu, L"ملف");
    AppendMenuW(hMenu, MF_POPUP, (UINT_PTR)hZekrMenu, L"الأذكار");

    SetMenu(hwnd, hMenu);

    // Set font for text display
    HFONT hFont = CreateFontW(20, 0, 0, 0, FW_NORMAL, FALSE, FALSE, FALSE, ARABIC_CHARSET,
        OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY, DEFAULT_PITCH, L"Arial");
    if (hFont) {
        SendMessageW(g_hTextDisplay, WM_SETFONT, (WPARAM)hFont, TRUE);
        SendMessageW(g_hAddZekrEdit, WM_SETFONT, (WPARAM)hFont, TRUE);
        SendMessageW(g_hAddZekrButton, WM_SETFONT, (WPARAM)hFont, TRUE);
        SendMessageW(g_hTrayButton, WM_SETFONT, (WPARAM)hFont, TRUE);
    }

    // Show the first zekr
    if (!zikrManager.getList().empty()) {
        wstring wtext = StringToWString(zikrManager.getList()[0].text);
        SetWindowTextW(g_hTextDisplay, wtext.c_str());
    }

    ShowWindow(hwnd, nCmdShow);

    // Run the message loop
    MSG msg = {};
    while (GetMessageW(&msg, NULL, 0, 0)) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }

    return 0;
}

// Window procedure implementation
LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam) {
    switch (uMsg) {
    case WM_COMMAND:
        {
            int wmId = LOWORD(wParam);
            // Handle button clicks
            if (wmId == 1) { // Next button
                const vector<Zekr>& azkarList = zikrManager.getList();
                if (!azkarList.empty()) {
                    g_currentZekrIndex = (g_currentZekrIndex + 1) % azkarList.size();
                    wstring wtext = StringToWString(azkarList[g_currentZekrIndex].text);
                    SetWindowTextW(g_hTextDisplay, wtext.c_str());
                }
            }
            else if (wmId == 2) { // Reset button
                const vector<Zekr>& azkarList = zikrManager.getList();
                if (!azkarList.empty()) {
                    g_currentZekrIndex = 0;
                    wstring wtext = StringToWString(azkarList[0].text);
                    SetWindowTextW(g_hTextDisplay, wtext.c_str());
                }
            }
            else if (wmId == 3) { // Add new zekr button
                wchar_t buffer[256];
                GetWindowTextW(g_hAddZekrEdit, buffer, 256);
                string newZekr = WStringToString(buffer);
                
                if (zikrManager.AddZekrToFile(newZekr)) {
                    MessageBoxW(hwnd, L"تم إضافة الذكر بنجاح", L"نجاح", MB_OK | MB_ICONINFORMATION);
                    SetWindowTextW(g_hAddZekrEdit, L"");
                    
                    // Update display if needed
                    if (g_currentZekrIndex == 0 && !zikrManager.getList().empty()) {
                        wstring wtext = StringToWString(zikrManager.getList()[0].text);
                        SetWindowTextW(g_hTextDisplay, wtext.c_str());
                    }
                } else {
                    MessageBoxW(hwnd, L"فشل في إضافة الذكر", L"خطأ", MB_OK | MB_ICONERROR);
                }
            }
            else if (wmId == 4) { // Reload azkar
                if (zikrManager.ImportZekrFromTxt()) {
                    MessageBoxW(hwnd, L"تم إعادة تحميل الأذكار بنجاح", L"نجاح", MB_OK | MB_ICONINFORMATION);
                    if (!zikrManager.getList().empty()) {
                        g_currentZekrIndex = 0;
                        wstring wtext = StringToWString(zikrManager.getList()[0].text);
                        SetWindowTextW(g_hTextDisplay, wtext.c_str());
                    }
                } else {
                    MessageBoxW(hwnd, L"فشل في تحميل الأذكار", L"خطأ", MB_OK | MB_ICONERROR);
                }
            }
            else if (wmId == 5) { // Exit
                g_isRunningInTray = false;
                if (g_trayThread.joinable()) {
                    g_trayThread.join();
                }
                RemoveTrayIcon();
                PostQuitMessage(0);
            }
            else if (wmId == 6) { // Show all azkar
                string allAzkar;
                const vector<Zekr>& azkarList = zikrManager.getList();
                for (const auto& zekr : azkarList) {
                    allAzkar += zekr.text + "\n";
                }
                wstring wallAzkar = StringToWString(allAzkar);
                MessageBoxW(hwnd, wallAzkar.c_str(), L"كل الأذكار", MB_OK | MB_ICONINFORMATION);
            }
            else if (wmId == 7) { // Add new zekr from menu
                SetFocus(g_hAddZekrEdit);
            }
            else if (wmId == 8 || wmId == 9) { // Tray mode button or menu item
                if (!g_isRunningInTray) {
                    g_isRunningInTray = true;
                    g_trayThread = thread(RunInTrayMode);
                    SetWindowTextW(g_hTrayButton, L"إيقاف العائمة");
                } else {
                    g_isRunningInTray = false;
                    if (g_trayThread.joinable()) {
                        g_trayThread.join();
                    }
                    MessageBoxW(hwnd, L"تم إيقاف وضع العائمة.", L"إيقاف العائمة", MB_OK | MB_ICONINFORMATION);
                    SetWindowTextW(g_hTrayButton, L"تشغيل كعائمة");
                }
            }
        }
        break;
    case WM_DESTROY:
        g_isRunningInTray = false;
        if (g_trayThread.joinable()) {
            g_trayThread.join();
        }
        RemoveTrayIcon();
        PostQuitMessage(0);
        return 0;
    case WM_PAINT:
        {
            PAINTSTRUCT ps;
            HDC hdc = BeginPaint(hwnd, &ps);
            FillRect(hdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW+1));
            EndPaint(hwnd, &ps);
        }
        return 0;
    }
    return DefWindowProcW(hwnd, uMsg, wParam, lParam);
}