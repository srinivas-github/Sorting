#include <cstdio>
#include <cstdlib>

int binarySearch(int arr[], int l, int r, int x)
{
    if ( r >= l)
    {
        int mid = l + (r-1)/2;
	if (arr[mid] == x)
	    return mid;
	if (arr[mid] > x)
	    return binarySearch(arr, l, mid-1, x);
	return binarySearch(arr, mid+1, r, x);
    }
    return -1;
}

int main()
{
    int arr[] = {1,2,3,5,8,13,21,34,55};
    int sz = sizeof(arr)/sizeof(arr[0]);
    int res = binarySearch(arr, 0, sz-1, 3);
    (res == -1)?printf("Not found..\n"):printf("Found at indx: %d\n", res);
    return 0;
}
