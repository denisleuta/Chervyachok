#include "InputHandler.h"
#include <conio.h>
    char InputHandler::GetInput() {
        if (_kbhit()) {
            return _getch();
        }
        return 0;
    }
