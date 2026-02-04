/*
 * Nolerr-OS - Copyright (c) 2025 Артемий Юров
 * Лицензия MIT: свободное использование с сохранением авторства
 */


#include "../libraru/initlibery.h"

#include "../clearwin.h"
#include "../INIT.h"

static void math_actions(void);

void actions(void) {
    short v;

    while (1) {
        CLEAR;
        printf("Выберите действие:\n1. Корень\n2. Степень\n3. Калькулятор\n4. Назад\nВаш выбор: ");

        int res = scanf("%hd", &v);


        while (getchar() != '\n');

        if (res != 1) {
            printf("Ошибка! Введите число.\n");
            SLEEP(1); // Даем пользователю секунду прочитать ошибку
            continue;
        }

        switch (v) {
            case 1: sqtr(); break;
            case 2: power(); break;
            case 3: math_actions(); break;
            case 4:
                CLEAR;
                system("cls");
                starts();
                return;
            default:
                printf("Такого пункта нет!\n");
                SLEEP(1);
        }
    }
}


static void sqtr(void) {
    double number, result;

    printf("Введите число для вычисления квадратного корня: ");

    if (scanf("%lf", &number) != 1) {
        printf("Ошибка ввода!\n");
        while(getchar() != '\n');
        SLEEP(2);
        return;
    }

    if (number < 0) {
        printf("Ошибка: нельзя извлечь корень из отрицательного числа!\n");
        SLEEP(10);
        return;
    }

    result = sqrt(number);
    printf("√%.2lf = %.4lf\n", number, result);
    SLEEP(10);
}

static void power(void) {
    double base, exponent, result;

    printf("Введите основание и степень: ");

    if (scanf("%lf %lf", &base, &exponent) != 2) {
        printf("Неверный ввод!\n");
        while(getchar() != '\n');
        SLEEP(10);
        return;
    }

    
    if (base == 0 && exponent <= 0) {
        printf("0^0 или 0^(отрицательное) не определено!\n");
        SLEEP(10);
        return;
    }

    if (base < 0 && fmod(exponent, 1.0) != 0.0) {
        printf("Осторожно: извлечение корня из отрицательного числа!\n");
    }

    // Вычисление степени
    result = pow(base, exponent);

 
    printf("%g ^ %g = ", base, exponent);

 
    if (exponent >= 0 && result == floor(result) && result <= 1e6) {
        printf("%.0lf\n", result);
    } else if (fabs(result) < 1e-4 || fabs(result) > 1e6) {
        printf("%.6e\n", result);
    } else {
        printf("%.6lf\n", result);
    }
    SLEEP(10);
}


static void math_actions(void) {
    int num1, num2;
    char action;

    printf("Enter num1: ");
    scanf("%d", &num1);
    printf("Enter num2: ");
    scanf("%d", &num2);

    while (getchar() != '\n');

    printf("Enter action (+, -, *, /): ");
    scanf("%c", &action);


    printf("%d %c %d = ", num1, action, num2);

    switch (action) {
        case '+':
            printf("%d\n", num1 + num2);
            SLEEP(10);
            break;
        case '-':
            printf("%d\n", num1 - num2);
            SLEEP(10);
            break;
        case '*':
            printf("%d\n", num1 * num2);
            SLEEP(10);
            break;
        case '/':
            if (num2 != 0) {
                // Для целочисленного деления
                printf("%d\n", num1 / num2);
                // Или для деления с плавающей точкой:
                // printf("%.2f\n", (double)num1 / num2);
            } else {
                printf("Error: Division by zero!\n");
            }
            SLEEP(10);
            break;
        default:
            printf("Error: Invalid operation!\n");
    }
}