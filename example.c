#include "keys.h"
#include <windows.h>

int main(void) {
system("start cmd"); 
Sleep(10);
sendvkeys("a");
pressEnter();
return 0;
}
