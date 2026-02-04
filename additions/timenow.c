/*
 * Nolerr-OS - Copyright (c) 2025 Артемий Юров
 * Лицензия MIT: свободное использование с сохранением авторства
 */
#include "../libraru/initlibery.h"
#include "../clearwin.h"
#include "../INIT.h"
#include <conio.h>


void times(void)
{
    printf("Нажмите любую клавишу, чтобы выйти в меню...\n");

    while (1)
    {
        // Проверка: если нажата клавиша — выходим из цикла
        if (_kbhit()) {
            _getch(); // Очищаем буфер нажатия
            break;    // Выход из цикла while
        }

        time_t mytime = time(NULL);
        struct tm *now = localtime(&mytime);
        
        CLEAR;
        printf("Date: %02d.%02d.%d\n", now->tm_mday, now->tm_mon + 1, now->tm_year + 1900);
        printf("Time: %02d:%02d:%02d\n", now->tm_hour, now->tm_min, now->tm_sec);
        
        SLEEP(1);
    }

    // Вместо завершения программы просто возвращаемся в начало
    CLEAR;
    starts();
}