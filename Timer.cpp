#include "Timer.h"
using namespace std;

Timer::Timer() {
    // Инициализация времени при создании объекта
    startTime = chrono::high_resolution_clock::now();
}

// Метод для получения прошедшего времени в секундах
double Timer::GetElapsedTime() {
    auto currentTime = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsedTime = currentTime - startTime;
    return elapsedTime.count();
}

// Метод для перезапуска счетчика времени
void Timer::Reset() {
    startTime = chrono::high_resolution_clock::now();
}