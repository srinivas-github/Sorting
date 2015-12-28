#include <cstdio>

void swap(int* a, int* b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int partition(int arr[], int l, int h)
{
    int x = arr[h];
    int i = (l -1);
    for(int j = l; j <= h-1; j++)
    {
        if (arr[j] <= x)
        {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[h]);
    return (i+1);
}

void quickSort(int arr[], int l, int h)
{
    if ( l < h )
    {
        int p = partition(arr, l, h);
        quickSort(arr, l, p-1);
        quickSort(arr, p+1, h);
    }
}

void printArr(int arr[], int sz)
{
    for(int i = 0; i < sz; i++)
        printf("%d ", arr[i]);
    printf("\n");
}

int main()
{
    int arr[] = {7, 8, 4, 12, 66, 45, 2, 1, 10, 13, 16, 12, 34, 44, 56};
    int sz = sizeof(arr)/sizeof(arr[0]);
    printArr(arr, sz);
    quickSort(arr, 0, sz-1);
    printArr(arr, sz);
    return 0;
}

