#include <windows.h>
#include <iostream>

using namespace std;

void leftClick() {
    INPUT input[2] = {};

    input[0].type = INPUT_MOUSE;
    input[0].mi.dwFlags = MOUSEEVENTF_LEFTDOWN;

    input[1].type = INPUT_MOUSE;
    input[1].mi.dwFlags = MOUSEEVENTF_LEFTUP;

    SendInput(2, input, sizeof(INPUT));
}

int main() {
    cout << "Press F4 to start\n";

    bool clicking = false;

    while (true) {
        if (GetAsyncKeyState(VK_F4) & 1) { // toggle on key press
            clicking = !clicking;
        }

        if (clicking) {
            leftClick();
        }

        Sleep(1); // prevents 100% CPU usage
    }

    return 0;
}
