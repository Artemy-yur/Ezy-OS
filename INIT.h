#pragma once

void creatfile(const char *name);
void readfile(const char *name);
void writefile(const char *name);
void deletefile(const char *name);
void copyfile(const char *from, const char *to);

//calculator
static void power(void);
static void sqtr(void);
static void match_actions(void);

//time
void times(void);

//wearth
void get_weather_win(const char *city);