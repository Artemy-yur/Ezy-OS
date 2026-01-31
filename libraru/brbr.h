#include <stdio.h>

#define SWAP(a, b)    \
    do                \
    {                 \
        int temp = a; \
        a = b;        \
        b = temp;     \
    } while (0)

#define LEN_ARR(arr) sizeof(arr) / sizeof(*arr)

void error(FILE *file)
{
    if (file == NULL)
    {
        printf("ERR");
        return;
    }
}

int minnum(int arr[], int len)
{
    int min = arr[0];

    for (int i = 0; i < len; i++)
    {
        if (min > arr[i])
            min = arr[i];
    }
    return min;
}

int maxnum(int arr[], int len)
{
    int max = arr[0];

    for (int i = 0; i < len; i++)
    {
        if (max < arr[i])
            max = arr[i];
    }
    return max;
}

int *fstl(int arry[], int len) // Сортировка От меньшего к большеиму
{
    for (int i = 0; i < len - 1; i++)
    {
        for (int j = 0; j < len - i - 1; j++)
        {
            if (arry[j] > arry[j + 1])
            {
                int temp = arry[j];
                arry[j] = arry[j + 1];
                arry[j + 1] = temp;
            }
        }
    }
    for (int i = 0; i < len; i++)
    {
        printf("%d ", arry[i]);
    }
    return arry;
}

void print_arry(int arry[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%3d ", arry[i]);
    }
}