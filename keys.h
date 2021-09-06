#include <windows.h>
#include <unistd.h>

void pressEnter()
{
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.time = 0;
    ip.ki.dwFlags = KEYEVENTF_UNICODE;
    ip.ki.wScan = VK_RETURN; //VK_RETURN is the code of Return key
    ip.ki.wVk = 0;
    ip.ki.dwExtraInfo = 0;
    SendInput(1, &ip, sizeof(INPUT));
}

void pressWindows(){
	INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.time = 0;
    ip.ki.dwFlags = KEYEVENTF_UNICODE;
    ip.ki.wScan = VK_RWIN;
    ip.ki.wVk = 0;
	 ip.ki.dwExtraInfo = 0;
    SendInput(1, &ip, sizeof(INPUT));
}

int sendvkeys(stringstart) //Quick note about this function it uses the usleep which is clock based but should be using winAPI to make sure that each call is in step i redacted this for my purposes
{
	char * string = stringstart;
	size_t length = strlen(string);
	size_t i = 0; 
	for (; i < length; i++) { // STEP THROUGH EACH KEY 1 BY 1
	usleep(500); // FEEL FREE TO MODIFY THE DELAY OR DELAY WITH ANOTHER FUNCTION
	pressKeyB(string[i]); // SEND 1 KEY
}
}
void pressKeyB(char mK)
{
    HKL kbl = GetKeyboardLayout(0);
    INPUT ip;
    ip.type = INPUT_KEYBOARD;
    ip.ki.time = 0;
    ip.ki.dwFlags = KEYEVENTF_UNICODE;
    if ((int)mK<65 && (int)mK>90) //FOR LOWERCASE
    {
        ip.ki.wScan = 0;
        ip.ki.wVk = VkKeyScanEx( mK, kbl );
    }
    else //FOR UPPERCASE
    {
        ip.ki.wScan = mK;
        ip.ki.wVk = 0;

    }
    ip.ki.dwExtraInfo = 0;
    SendInput(1, &ip, sizeof(INPUT));
}

void hideWindow(){
	HWND window;
	AllocConsole();
	window=FindWindowA("ConsoleWindowClass",NULL);
	ShowWindow(window,0);
}
