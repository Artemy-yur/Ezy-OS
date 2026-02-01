#include <stdio.h>
#include "INIT.h"
#include "clearwin.h"

void actions();
void python_help();
int main(void)
{

    int v = start();
    //creatfile("nolerr.txt");
    switch(v) {
        case 2:
            actions();
            break;
        case 3:
            times();
            break;
        case 4:
            char city[10];
            scanf("%s\n", city);
            get_weather_win(city);
            break;
        case 5:
            python_help();
            break;
        default:
            printf("Не известное действия!");
            CLEAR;
            break;
        start();
        
    }
    return 0;
}

