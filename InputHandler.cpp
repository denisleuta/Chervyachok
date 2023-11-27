/*#include "InputHandler.h"
#include <conio.h>
    char InputHandler::GetInput() {
        if (_kbhit()) {
            return _getch();
        }
        return 0;
    }
    */

#include "InputHandler.h"


#ifdef __linux__
#include <iostream>
#include <termios.h>
#include <unistd.h>
#include <fcntl.h>

char InputHandler::GetInput() {
    struct termios oldt, newt;
    char ch;
    int oldf;

    // Сохраняем текущие настройки терминала
    tcgetattr(STDIN_FILENO, &oldt);

    // Копируем их для редактирования
    newt = oldt;

    // Отключаем буферизацию ввода
    newt.c_lflag &= ~(ICANON | ECHO);

    // Применяем новые настройки
    tcsetattr(STDIN_FILENO, TCSANOW, &newt);

    // Сохраняем режим флагов
    oldf = fcntl(STDIN_FILENO, F_GETFL, 0);

    // Устанавливаем неблокирующий режим ввода
    fcntl(STDIN_FILENO, F_SETFL, oldf | O_NONBLOCK);

    // Чтение символа (если доступно)
    ch = getchar();

    // Возвращаем старые настройки
    tcsetattr(STDIN_FILENO, TCSANOW, &oldt);

    // Возвращаем старый режим флагов
    fcntl(STDIN_FILENO, F_SETFL, oldf);

    if (ch != EOF) {
        return ch;
    }

    return 0;
}
#elif _WIN32
#include <conio.h>

char InputHandler::GetInput() {
    if (_kbhit()) {
        return _getch();
    }
    return 0;
}
#else
#error "Unsupported operating system"
#endif