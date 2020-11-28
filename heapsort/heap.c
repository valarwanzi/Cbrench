#include "heap.h"

void showHeap(int *arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%d ",*(arr+i));
    }
    printf("\n");
}

void swap( int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void maxHeapify( int * arr, const int index, const int heapsize)
{
    int largest;
    int l = 2 * index;
    int r = 2 * index + 1;
    if( l <= heapsize && *(arr+l-1) > *(arr+index-1))
    {
        largest = l;
    } else{
        largest = index;
    }
    if( r<= heapsize && *(arr+r-1) > *(arr+largest-1))
    {
        largest = r;
    }

    if(largest != index)
    {
        swap( (arr+index-1), (arr+largest-1));
        maxHeapify( arr, largest, heapsize);
    }
}

void buildMaxHeap( int *arr, const int len)
{
    int heapsize = len;
    for( int index = len / 2; index > 0; index--)
    {
        maxHeapify(arr, index, heapsize);
        //showHeap(arr, len);
    }
}

void heapSort( int *arr, int len)
{
    buildMaxHeap( arr, len);
    //showHeap(arr, len);
    int heapsize = len;
    for (int i = len; i > 1 ; i--) {
        swap( (arr+0), (arr + i - 1));
        heapsize--;
        maxHeapify( arr, 1, heapsize);
        //showHeap(arr, len);
    }
}

