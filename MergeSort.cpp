#include <cstdio>
#include <cstdlib>

void Merge(int *A, int *L, int leftCnt, int *R, int rightCnt)
{
    int i, j, k;
    i=j=k=0;
    while( i < leftCnt && j < rightCnt)
    {
        if (L[i] < R[j])
	    A[k++] = L[i++];
	else
	    A[k++] = R[j++];
    }

    while ( i < leftCnt)
        A[k++] = L[i++];
    while ( j < rightCnt)
        A[k++] = R[j++];
}

void MergeSort(int *A, int n)
{
    int i;
    int mid;
    int *L, *R;

    if ( n  < 2)
        return ;

    mid = n/2;
    L = (int*)malloc(mid * sizeof(int));
    R = (int*)malloc( (n-mid)*sizeof(int));

    for (i = 0; i < mid; i++)
        L[i] = A[i];
    for (i = mid; i < n; i++)
        R[i-mid] = A[i];

    MergeSort(L, mid);
    MergeSort(R, n-mid);
    Merge(A, L, mid, R, n-mid);
}

int main()
{
    int A[] = {65, 34, 2, 12, 4, 90, 88, 3, 25};
    int sz = sizeof(A)/sizeof(A[0]);
    printf("Before Merge Sort:\n");
    for(int i = 0; i < sz; i++)
        printf("%d ", A[i]);
   
    MergeSort(A, sz);
    printf("\n\nAfter MergeSort:\n");
    for(int i = 0; i < sz ; i++)
        printf("%d ", A[i]);
	
    return 0;
}
