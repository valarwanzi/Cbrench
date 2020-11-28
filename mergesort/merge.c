#include "merge.h"
#include "stdio.h"
#include "stdlib.h"

void showMerge(int *arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("%d ",*(arr+i));
    }
    printf("\n");
}

/*
 * 两个有序数组：起点分别为 p 和 q
 */
void subMerge(int * arr, const int r, const int q, const int p)
{
    const int n1 = q - p + 1;
    const int n2 = r - q;

    int *larr;
    larr = malloc(n1);
    int *rarr;
    rarr = malloc(n2);

    for(int i = 0; i < n1; i++)
    {
        *(larr+i) = *(arr+p+i-1);
    }
    for(int j = 0; j < n2; j++)
    {
        *(rarr+j) = *(arr+q+j);
    }
    *(larr+n1) = 255;
    *(rarr+n2) = 255;
    for(int i = 0, j = 0, k = (p - 1); k < r; k++)
    {
        if( *(larr+i) == 255 && *(rarr+j) == 255)
        {
            break;
        }
        else if( *(larr+i) == 255 )
        {
            *(arr+k) = *(rarr+j);
            j++;
            free(larr);
            continue;
        }
        else if( *(rarr+j) == 255 )
        {
            *(arr+k) = *(larr+i);
            i++;
            free(rarr);
            continue;
        }
        else
        {
            if( *(larr+i) <= *(rarr+j))
            {
                *(arr+k) = *(larr+i);
                i++;
            }
            else{
                *(arr+k) = *(rarr+j);
                j++;
            }
        }
    }
}

void merge(int * arr, int p, int r )
{
    if( p < r )
    {
        int q = ( p + r ) /2;
        merge( arr, p, q );
        merge( arr, q+1, r);
        subMerge( arr, r, q, p);
        //showMerge(arr, r);
    } else{
        return ;
    }
}
