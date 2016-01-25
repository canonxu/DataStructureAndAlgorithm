#include <stdio.h>
#define LEN 8

//回顾冒泡排序，每一次内循环都是为了找到一个最小值冒上来，这过程中多次两两swap的代价很大
//在选择排序中，两层循环的循环范围一样的，只是选择排序的内循环直接找到最小值，最多只swap一次即可。
//所以选择排序和冒泡排序的时间复杂度一样的，但选择排序要快

//借助外部空间t进行交换
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int select_sort(int *a)
{
    int i, j;
    for(i = 0; i < LEN; i++)
    {
        int flag = i;
        for(j = i + 1; j < LEN; j++)
        {
            if(a[j] < a[flag])
                flag = j;   //找出i到LEN-1的最小值，记录最小值得位置
        }
        swap(&a[i], &a[flag]);
    }

    return 0;
}


int main()
{
    int array[] = {5, 7, 2, 3, 8, 4, 1, 9};
    select_sort(array);
    int k;
    for(k = 0; k < LEN; k++)
        printf("%d ", array[k]);
    return 0;
}
