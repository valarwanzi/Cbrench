#include "insert.h"

void sort(int* arr, int len )
{
    for( int j = 1; j < len; j++ )
    {
        int key = *(arr + j);
        int i = j -1;
        for( ;i >= 0 && *(arr+i) > key; i-- )
        {
            *(arr+i+1) = *(arr+i);
        }
        *(arr+i +1) = key;
    }
}

void inv_sort(int* arr, int len )
{
    for( int j = 1; j < len; j++ )
    {
        int key = *(arr + j);
        int i = j -1;
        for( ;i >= 0 && *(arr+i) < key; i-- )
        {
            *(arr+i+1) = *(arr+i);
        }
        *(arr+i +1) = key;
    }
}
