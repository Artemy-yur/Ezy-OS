/*
 * Nolerr-OS - Copyright (c) 2025 Артемий Юров
 * Лицензия MIT: свободное использование с сохранением авторства
 */

#include <stdio.h>
#include "INIT.h"
#include "clearwin.h"

void actions();
void python_help();
int starts(void);
void menu(void);

int main(void)
{
    int v = start();

    menu();

    return 0;
}

int starts(void) {
    short vibor_s;

    const char *vibor[] = {
        "1. Работа над файлом.\n",
        "2. Математика.\n",
        "3. Время сейчас.\n",
        "4. Погода.\n",
        "5. Help\n",
        "6. Заметка\n",
        "7. Все файлы в директории\n",
        "8. Информация о Системе\n",
        "0. Выход\n"};

    for (int i = 0; i < ARRAYSIZE(vibor); i++) {
        printf("%s", vibor[i]);
    }

    while(1) {
        printf("Введите число от (0-8): ");

        if(scanf("%hd", &vibor_s) != 1) {
            while(getchar() != '\n');
            printf("Ошибка введите число: \n");
            continue;
        }

        if(vibor_s > 8 || vibor_s < 0){
            printf("Error: Число от 0 до 8\n");
        }
        else {
            break;
        }
    }

    return vibor_s;
}

void menu(void) {  // Теперь menu не принимает параметр
    int choice;

    while(1) {  // Бесконечный цикл внутри menu
        // Показываем меню и получаем выбор
        printf("\n");
        const char *vibor[] = {
            "1. Работа над файлом.\n",
            "2. Математика.\n",
            "3. Время сейчас.\n",
            "4. Погода.\n",
            "5. Help\n",
            "6. Заметка\n",
            "7. Все файлы в директории\n",
            "8. Информация о Системе\n",
        };

        for (int i = 0; i < ARRAYSIZE(vibor); i++) {
            printf("%s", vibor[i]);
        }

        printf("Введите число от (1-8): ");
        scanf("%d", &choice);

        switch(choice) {
            case 1:
                // Здесь должна быть функция для работы с файлом
                printf("Работа над файлом (функция пока не реализована)\n");
                break;
            case 2:
                actions();
                break;
            case 3:
                times();
                break;
            case 4:
                {
                    char city[10];
                    printf("Введите город: ");
                    scanf("%s", city);
                    get_weather_win(city);
                }
                break;
            case 5:
                python_help();
                break;
            case 6:
                //notich(); Эта функция не работает
                printf("(функция пока не реализована)\n");
                break;
            case 7:
                listfile();
                break;
            case 8:
                info_system();
                break;
            default:
                printf("Неизвестное действие!\n");
                break;
        }

        CLEAR;
    }
}