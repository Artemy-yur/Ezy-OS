/*
 * Nolerr-OS - Copyright (c) 2025 Артемий Юров
 * Лицензия MIT: свободное использование с сохранением авторства
 */

#include "../libraru/initlibery.h"
#include "../clearwin.h"
#include <stdbool.h>
#include <string.h>
#define LEN_ARR(arr) sizeof(arr) / sizeof(*arr)

static int mainmeny_ru(void)
{
  short vibor_s;

  const char *tegs[] = {
      "Здравствуйте, это моя мини-ОС.\n",
      "Вы можете ввести Help, чтобы увидеть все команды.\n",
      "Эта версия позволяет работать с файлами, папками, временем и погодой.\n\n",
  };
  const char *vibor[] = {
      "1. Работа над файлом.\n",
      "2. Математика.\n",
      "3. Время сейчас.\n",
      "4. Погода.\n",
      "5. Help\n",
      "6. Заметка\n",
      "7. Все файлы в директории\n",
      "8. Информация о Системе\n"};
  for (size_t i = 0; i < 3; i++)
  {
    printf("%s", tegs[i]);
    if (i < 2)
    {
      SLEEP(1); // Пауза 1 секунда после каждой строки, кроме последней
    }
  }
  for (int i = 0; i < LEN_ARR(vibor); i++)
  {
    printf("%s", vibor[i]);
  }

  while(1) {
    printf("Введите число от (1-8): ");

    if(scanf("%hd", &vibor_s) != 1) {
    
      while(getchar() != '\n');
      printf("Ошибка введите чило: \n");
      continue;
    }

    if(vibor_s > 8 || vibor_s < 1){
      printf("Error: Чило от 1 до 8\n");
    }
    else {
      break;
    }
  }
  CLEAR;

  return vibor_s;
}
static int mainmeny_en(void) {
  short vibor_s;
  const char *tegs[] = {
    "Hello,it`s my mini os.\n",
    "You can type Help to see all commands.\n",
    "This version allows you to work with files, folders, time and weather.\n\n",
};
  const char *vibor[] = {
    "1.Work for file.\n",
    "2.Math.\n",
    "3.Time now\n",
    "4.Weather.\n",
    "5.Help\n"};


  for (size_t i = 0; i < 3; i++)
  {
    printf("%s", tegs[i]);
    if (i < 2)
    {
      SLEEP(1);
    }
  }
  for (int i = 0; i < LEN_ARR(vibor); i++)
  {
    printf("%s", vibor[i]);
  }


  while(1) {

    printf("Enter choice (1-6): ");

    if(scanf("%hd", &vibor_s) != 1) {
      while(getchar() != '\n');
      printf("Error: Please enter a number\n");
      continue;
    }

    if(vibor_s > 6 || vibor_s < 1){
      printf("Error: Number must be between 1 and 5\n");
    }
    else {
      break;
    }
  }
  
  return vibor_s;
  CLEAR;

}
int start(void)
{
  char *lengch = malloc(10 * sizeof(char));
  if (lengch == NULL) {
    printf("Memory allocation failed!\n");
    return 1;
  }

  //printf("Your language (ru/en)?: ");

  // Временное решение: всегда вызываем RU версию
  //scanf("%9s", lengch);
  int res = mainmeny_ru();


  free(lengch);
  return res;

#if 0
  while (1) {
    if (strcmp(lengch, "ru") == 0) {
      free(lengch);
      int res = mainmeny_ru();

      return mainmeny_ru();
    }
    if (strcmp(lengch, "en") == 0) {
      free(lengch);
      int res = mainmeny_en();

      return mainmeny_en();
    }
  }
#endif
}