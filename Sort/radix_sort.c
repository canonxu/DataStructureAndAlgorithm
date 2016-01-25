#include <stdio.h>
#define LEN 8










int main()
{
    int array[] = {5, 7, 2, 3, 8, 4, 1, 9};
    quick_sort(array, 0, LEN - 1);
    int k;
    for(k = 0; k < LEN; k++)
        printf("%d ", array[k]);
    return 0;
}
