#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int BinarySearch(int Array[], int x, int top)
{
    int low = 0, mid, high = top-1;
    while(low < high)
    {
        mid = (low + mid )/2;
        if (Array[mid] < x)
            low = mid + 1;
        else if (Array[mid] < x)
            high = mid - 1;
        else
            return mid;
    }
    //printf("NotFound\n");

}

int main(void)
{
    int array[] = {1,4,8,12,14,25,68, 75,78};
    int s = 0;
    s = BinarySearch(array, 25 , 9);
    printf("%d\n", array[s]);
    return 0;

}
