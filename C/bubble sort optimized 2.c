#include "default.h"
#include <unistd.h>

int main(int argc, char const *argv[])
{
    unsigned long long int sizeOfArray;
    unsigned long long int *array = input(&sizeOfArray), temp;
    double start,end;
    start = omp_get_wtime();
    for (unsigned long long int i = sizeOfArray-1; i > 0; i--)
    {
        for (unsigned long long int j = 0; j < i; j++)
        {
            if (array[j]>array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1]=temp;
            }
        }
    }
    end = omp_get_wtime();
    printf("Application runtime: %f seconds.\n", end - start);
    // printArray(array, sizeOfArray);
    return 0;
}