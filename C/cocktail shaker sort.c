#include "default.h"
#include <unistd.h>

int main(int argc, char const *argv[])
{
    unsigned long long int sizeOfArray;
    unsigned long long int *array = input(&sizeOfArray), temp;
    double start,end;
    unsigned long long int n = (sizeOfArray/2)+1;
    start = omp_get_wtime();
    for (unsigned long long int i = 0; i < n; i++)
    {
        for (unsigned long long int j = i; j < sizeOfArray-i-1; j++)
        {
            if (array[j] > array[j+1])
            {
                temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
        for (unsigned long long int j = sizeOfArray-i-1; j > 0+i; j--)
        {
            if (array[j] < array[j-1])
            {
                temp = array[j];
                array[j] = array[j-1];
                array[j-1] = temp;
            }

        }
    }
    end = omp_get_wtime();
    // printArray(array, sizeOfArray, 0);
    printf("Application runtime: %f seconds.\n", end - start);
    return 0;
}