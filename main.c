#include <stdio.h>
#include "INIT.h"

void actions();
int main(void)
{
    creatfile("nolerr.txt");
    actions();
    times();

    
    get_weather_win("Moscow");
    return 0;
}