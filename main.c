/*
 * Nolerr-OS - Copyright (c) 2025 Артемий Юров
 * Лицензия MIT: свободное использование с сохранением авторства
 */

#include <stdio.h>
#include <stdlib.h>
#include "INIT.h"
#include "clearwin.h"

void execute_choice(int choice)
{
    switch (choice)
    {
    case 1:
        menu_file();
        break;
    case 2:
        actions();
        break;
    case 3:
        times();
        break;
    case 4:
    {
        char city[50];
        printf("Введите город: ");
        scanf("%49s", city);
        while (getchar() != '\n')
            ; // Очистка буфера
        get_weather_win(city);
    }
    break;
    case 5:
        python_help();
        break;
    case 6:
        notich();
        getchar();
        break;
    case 7:
        listfile();
        break;
    case 8:
        info_system();
        break;
    default:
        printf("Неизвестное действие!\n");
        printf("\nНажмите Enter для продолжения...");
        getchar();
        break;
    }
}

int starts(void)
{
    int choice;

    while (1)
    {
        CLEAR;
        printf(F_WHITE "Главное меню" F_CYAN RESET "\n");
        printf(F_BLUE "------------------------------------------" RESET "\n");
        const char *vibor[] = {
            "Работа над файлом", "Математика", "Время сейчас", "Погода",
            "Справка (Help)", "Заметка", "Все файлы", "Инфо о системе"};

        for (int i = 0; i < ARRAYSIZE(vibor); i++)
        {
            // [ 1 ] - Текст пункта
            printf(F_BLUE "[" F_WHITE "%d" F_BLUE "]" RESET " %s\n", i + 1, vibor[i]);
        }
        printf(F_BLUE "------------------------------------------" RESET "\n");
        printf(F_WHITE "0." RESET " Выход\n\n");
        printf(F_BOLD "nolerr@user" RESET ":" F_BLUE "~" RESET "$ "); // Имитация строки ввода bash

        if (scanf("%d", &choice) != 1)
        {
            while (getchar() != '\n')
                ;
            continue;
        }
        while (getchar() != '\n')
            ;

        if (choice == 0)
            exit(0);

        if (choice < 1 || choice > 8)
        {
            printf(F_BLUE "[" F_WHITE "!" F_BLUE "]" RESET " Ошибка: Выберите 1-8\n");
            getchar();
            continue;
        }

        execute_choice(choice);
    }
}

int main(void)
{

    int first_choice = start();
    execute_choice(first_choice);
    starts();
    return 0;
}