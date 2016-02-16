#include <iostream>

void nextGre(int arr[], int n)
{
    int next, i, j;
    for(i =0; i < n; i++)
    {
        next = -1;
	for(j = i+1; j < n; j++)
	{
	    if (arr[i] < arr[j])
	    {
	        next = arr[j];
		break;
	    }

	}
	printf("%d - %d\n", arr[i], next);
    }
}

int main()
{
    int arr[] = {5,9,1,12,11,14,22,2,1};
    int sz = sizeof(arr)/sizeof(arr[0]);
    nextGre(arr, n);
    return 0;
}
