#include <stdio.h>
#define LEN 8


//希尔排序的实质就是分组插入排序,又称“缩小增量排序”
//将整个待排元素序列分割成若干个子序列分别进行直接插入排序，然后依次减小增量进行排序，
// 待整个序列中的元素基本有序（增量足够小）时，再对全体元素进行一次直接插入排序(相当于增量为1的插入排序)。
//因为直接插入排序在元素基本有序的情况下（接近最好情况），效率是很高的O(n)，因此希尔排序在时间效率上比前两种方法有较大提高。

//希尔排序平均时间复杂度 O(nlogn)-O(n^2)/O(n^1.3)，最差时间复杂度O(n^2)，最差时间复杂度O(n)。具体讲复杂度不好说，步长选取很关键！最终会觉得复杂度！
//步长选择都是从n/2开始，每次再减半，直到最后为1

//希尔排序不稳定


int shell_sort1(int *a)
{
    int i, j, gap, key;
    for(gap = LEN/2; gap > 0; gap /= 2)
    {
        for(i = gap; i < LEN; i++)
        {
            key = a[i];
            for(j = i - gap; j >= 0 && a[j] > key;j -= gap)
                a[j + gap] = a[j];
            a[j + gap ] = key;
        }
    }
    return 0;
}


void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int  shell_sort(int *a)
{
    int i, j,gap;
    for(gap = LEN/2; gap > 0; gap /= 2)  //如：gap为5则分为五组，每组内部拆入排序。 需要一直循环到gap=1（gap>0）。
        for(i = gap; i < LEN; i++)  //对相应的gap，进行插入排序
            for(j = i - gap; j >= 0; j -= gap)
            {
                if(a[j] > a[j + gap])
                    swap(&a[j], &a[j + gap]);
            }
    return 0;
}


int main()
{
    int array[] = {5, 7, 2, 3, 8, 4, 1, 9};
    shell_sort1(array);
    int k;
    for(k = 0; k < LEN; k++)
        printf("%d ", array[k]);
    return 0;
}
