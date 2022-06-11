#include "default.h"

unsigned long long int *input(unsigned long long int *sizeOfArray)
{
    unsigned long long int *stream = NULL, entrada, position = 0;
    while (scanf("%llu\n", &entrada) != EOF)
    {
        if (stream == NULL)
        {
            stream = (unsigned long long int *)malloc(sizeof(unsigned long long int));
        }
        else
        {
            stream = (unsigned long long int *)realloc(stream, (position + 1) * sizeof(unsigned long long int));
        }
        stream[position] = entrada;
        position++;
    }
    *sizeOfArray = position;
    return stream;
}

void printArray(unsigned long long int *array, unsigned long long int sizeOfArray, int type)
{
    if (type == 1)
    {
        for (unsigned long long int i = 0; i < sizeOfArray; i++)
        {
            if (i == sizeOfArray - 1)
            {
                printf("%llu\n", array[i]);
            }
            else
            {
                printf("%llu ", array[i]);
            }
        }
    }
    else
    {
        for (unsigned long long int i = 0; i < sizeOfArray; i++)
        {
            if (i == sizeOfArray - 1)
            {
                printf("%llu", array[i]);
            }
            else
            {
                printf("%llu\n", array[i]);
            }
        }
    }
}