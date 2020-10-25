#include "lab3.h"
#include <windows.h>
#include <iostream>

#define COUNT_OF_THREADS 10
#define AMOUNT_OF_TIMES 3

DWORD ThreadID;
// id потоков
HANDLE hThread[COUNT_OF_THREADS];
// мьютекс для захвата секции
HANDLE lock;
// Семафоры для последовательного вывода
HANDLE semB, semC, semD, semWait, semContinue;

unsigned int lab3_thread_graph_id()
{
    return 9;
}

const char *lab3_unsynchronized_threads()
{
    return "fhi";
}

const char *lab3_sequential_threads()
{
    return "bcd";
}

DWORD WINAPI thread_a(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < AMOUNT_OF_TIMES; ++i)
    {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "a" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    return 0;
}

DWORD WINAPI thread_b(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < AMOUNT_OF_TIMES; ++i)
    {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "b" << std::flush;
        ReleaseMutex(lock);
        computation();
    }

    ReleaseSemaphore(semWait, 1, NULL);
    WaitForSingleObject(semContinue, INFINITE);

    for (int i = 0; i < AMOUNT_OF_TIMES; ++i)
    {
        WaitForSingleObject(semB, INFINITE);
        WaitForSingleObject(lock, INFINITE);
        std::cout << "b" << std::flush;
        ReleaseMutex(lock);
        computation();
        ReleaseSemaphore(semC, 1, NULL);
    }

    return 0;
}

DWORD WINAPI thread_c(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < AMOUNT_OF_TIMES; ++i)
    {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "c" << std::flush;
        ReleaseMutex(lock);
        computation();
    }

    ReleaseSemaphore(semWait, 1, NULL);
    WaitForSingleObject(semContinue, INFINITE);

    for (int i = 0; i < AMOUNT_OF_TIMES; ++i)
    {
        WaitForSingleObject(semC, INFINITE);
        WaitForSingleObject(lock, INFINITE);
        std::cout << "c" << std::flush;
        ReleaseMutex(lock);
        computation();
        ReleaseSemaphore(semD, 1, NULL);
    }

    ReleaseSemaphore(semWait, 1, NULL);
    WaitForSingleObject(semContinue, INFINITE);

    for (int i = 0; i < AMOUNT_OF_TIMES; ++i)
    {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "c" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    return 0;
}

DWORD WINAPI thread_d(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < AMOUNT_OF_TIMES; ++i)
    {
        WaitForSingleObject(semD, INFINITE);
        WaitForSingleObject(lock, INFINITE);
        std::cout << "d" << std::flush;
        ReleaseMutex(lock);
        computation();
        ReleaseSemaphore(semB, 1, NULL);
    }
    return 0;
}

DWORD WINAPI thread_e(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < AMOUNT_OF_TIMES; ++i)
    {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "e" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    return 0;
}

DWORD WINAPI thread_f(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < AMOUNT_OF_TIMES; ++i)
    {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "f" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    return 0;
}

DWORD WINAPI thread_g(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < AMOUNT_OF_TIMES; ++i)
    {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "g" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    return 0;
}

DWORD WINAPI thread_h(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < AMOUNT_OF_TIMES; ++i)
    {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "h" << std::flush;
        ReleaseMutex(lock);
        computation();
    }

    ReleaseSemaphore(semWait, 1, NULL);
    WaitForSingleObject(semContinue, INFINITE);

    for (int i = 0; i < AMOUNT_OF_TIMES; ++i)
    {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "h" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    return 0;
}

DWORD WINAPI thread_k(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < AMOUNT_OF_TIMES; ++i)
    {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "k" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    return 0;
}

DWORD WINAPI thread_i(LPVOID lpParam)
{
    UNREFERENCED_PARAMETER(lpParam);
    for (int i = 0; i < AMOUNT_OF_TIMES; ++i)
    {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "i" << std::flush;
        ReleaseMutex(lock);
        computation();
    }

    ReleaseSemaphore(semWait, 1, NULL);
    WaitForSingleObject(semContinue, INFINITE);

    for (int i = 0; i < AMOUNT_OF_TIMES; ++i)
    {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "i" << std::flush;
        ReleaseMutex(lock);
        computation();
    }

    ReleaseSemaphore(semWait, 1, NULL);
    WaitForSingleObject(semContinue, INFINITE);

    for (int i = 0; i < AMOUNT_OF_TIMES; ++i)
    {
        WaitForSingleObject(lock, INFINITE);
        std::cout << "i" << std::flush;
        ReleaseMutex(lock);
        computation();
    }
    return 0;
}


int lab3_init()
{
    // создание семафоров
    // Парамеры семафора: null, макс. знач. счетчика, мин. значен. счетчика, имя
    semB = CreateSemaphore(NULL, 1, 1, NULL);
    semC = CreateSemaphore(NULL, 0, 1, NULL);
    semD = CreateSemaphore(NULL, 0, 1, NULL);
    semWait = CreateSemaphore(NULL, 0, 2, NULL);
    semContinue = CreateSemaphore(NULL, 0, 2, NULL);

    // мьютекс
    lock = CreateMutex(NULL, FALSE, NULL);
    if (lock == NULL)
    {
        std::cerr << "Mutex init failed" << std::endl;
        return 1;
    }

    /// ПЕРВЫЙ ЭТАП

    // запуск потока А
    hThread[0] = CreateThread(NULL, 0, thread_a, NULL, 0, &ThreadID);
    if (hThread[0] == NULL)
    {
        std::cerr << "Can't create thread A. Error: " << GetLastError() << std::endl;
        return 1;
    }

    // запуск потока B
    hThread[1] = CreateThread(NULL, 0, thread_b, NULL, 0, &ThreadID);
    if (hThread[1] == NULL)
    {
        std::cerr << "Can't create thread B. Error: " << GetLastError() << std::endl;
        return 1;
    }

    // запуск потока C
    hThread[2] = CreateThread(NULL, 0, thread_c, NULL, 0, &ThreadID);
    if (hThread[2] == NULL)
    {
        std::cerr << "Can't create thread C. Error: " << GetLastError() << std::endl;
        return 1;
    }

    // ожидание завершения одного цикла потока B
    WaitForSingleObject(semWait, INFINITE);

    // ожидание завершения одного цикла потока C
    WaitForSingleObject(semWait, INFINITE);

    // ожидание окончания потока А
    WaitForSingleObject(hThread[0], INFINITE);

    /// ВТОРОЙ ЭТАП

    // запуск потока D
    hThread[3] = CreateThread(NULL, 0, thread_d, NULL, 0, &ThreadID);
    if (hThread[3] == NULL)
    {
        std::cerr << "Can't create thread D. Error: " << GetLastError() << std::endl;
        return 1;
    }

    // продолжение потока B
    ReleaseSemaphore(semContinue, 1, NULL);

    // продолжение потока C
    ReleaseSemaphore(semContinue, 1, NULL);


    // ожидание окончания потока B
    WaitForSingleObject(hThread[1], INFINITE);


    // ожидание окончания потока D
    WaitForSingleObject(hThread[3], INFINITE);

    // ожидание завершения второго цикла потока C
    WaitForSingleObject(semWait, INFINITE);

    /// ТРЕТИЙ ЭТАП

    // запуск потока E
    hThread[4] = CreateThread(NULL, 0, thread_e, NULL, 0, &ThreadID);
    if (hThread[4] == NULL)
    {
        std::cerr << "Can't create thread E. Error: " << GetLastError() << std::endl;
        return 1;
    }

    // продолжение потока C
    ReleaseSemaphore(semContinue, 1, NULL);

    // ожидание окончания потока C
    WaitForSingleObject(hThread[2], INFINITE);

    // ожидание окончания потока E
    WaitForSingleObject(hThread[4], INFINITE);

    /// ЧЕТВЕРТЫЙ ЭТАП

    // запуск потока F
    hThread[5] = CreateThread(NULL, 0, thread_f, NULL, 0, &ThreadID);
    if (hThread[5] == NULL)
    {
        std::cerr << "Can't create thread F. Error: " << GetLastError() << std::endl;
        return 1;
    }

    // запуск потока H
    hThread[6] = CreateThread(NULL, 0, thread_h, NULL, 0, &ThreadID);
    if (hThread[6] == NULL)
    {
        std::cerr << "Can't create thread H. Error: " << GetLastError() << std::endl;
        return 1;
    }

    // запуск потока I
    hThread[7] = CreateThread(NULL, 0, thread_i, NULL, 0, &ThreadID);
    if (hThread[7] == NULL)
    {
        std::cerr << "Can't create thread H. Error: " << GetLastError() << std::endl;
        return 1;
    }

    // ожидание окончания потока F
    WaitForSingleObject(hThread[5], INFINITE);

    // ожидание завершения первого цикла потока H
    WaitForSingleObject(semWait, INFINITE);

    // ожидание завершения первого цикла потока I
    WaitForSingleObject(semWait, INFINITE);

    /// ПЯТЫЙ ЭТАП

    // запуск потока G
    hThread[8] = CreateThread(NULL, 0, thread_g, NULL, 0, &ThreadID);
    if (hThread[8] == NULL)
    {
        std::cerr << "Can't create thread G. Error: " << GetLastError() << std::endl;
        return 1;
    }

    // продолжение потока H
    ReleaseSemaphore(semContinue, 1, NULL);

    // продолжение потока I
    ReleaseSemaphore(semContinue, 1, NULL);

    // ожидание окончания потока G
    WaitForSingleObject(hThread[8], INFINITE);

    // ожидание окончания потока H
    WaitForSingleObject(hThread[6], INFINITE);

    // ожидание завершения второго цикла потока I
    WaitForSingleObject(semWait, INFINITE);

    /// ШЕСТОЙ ЭТАП

    // запуск потока K
    hThread[9] = CreateThread(NULL, 0, thread_k, NULL, 0, &ThreadID);
    if (hThread[9] == NULL)
    {
        std::cerr << "Can't create thread K. Error: " << GetLastError() << std::endl;
        return 1;
    }

    // продолжение потока I
    ReleaseSemaphore(semContinue, 1, NULL);

    // ожидание окончания потока I
    WaitForSingleObject(hThread[7], INFINITE);

    // ожидание окончания потока K
    WaitForSingleObject(hThread[9], INFINITE);



    // освобождение ресурсов
    for (int i = 0; i < COUNT_OF_THREADS; ++i)
        CloseHandle(hThread[i]);
    // закрытие мьютекса
    CloseHandle(lock);
    // закрытие семафоров
    CloseHandle(semB);
    CloseHandle(semC);
    CloseHandle(semD);
    CloseHandle(semWait);
    CloseHandle(semContinue);
    std::cout << std::endl;
    return 0;
}