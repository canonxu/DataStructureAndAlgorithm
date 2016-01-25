#include<stdio.h>
#define LEN 8


//冒泡排序的时间复杂度为O（n2）,效率低下一般不用！
//冒泡排序是稳定的排序，即对于相等的两个数，排序前后位置不变


//在写swap函数式，直接swap（int a， int b），调用时会发现没有。因为这是“值传递”。
//值传递在调用的时候，将实际参数复制一份传递到函数参数中（形参是实参的拷贝），不管该函数做什么，实际的参数都不变（改变形参的值并不改变外部实参的值）。


//异或运算可不借助外部空间进行交换，缺点是：不能交换相等的值（相等的值交换后结果为0）
void swap_bit(int *a, int *b)
{
    if(*a == *b) return;  //如果值相等，直接返回，不需要swap
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}

//借助外部空间t进行交换
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


void bubble_sort(int *array)
{
    int i, j;
    for(i = 0; i < LEN; i++)  //每循环一次，最小的数冒泡到顶端
    {
        for(j = LEN - 1; j > i; j--)
            if(array[j] < array[j - 1])
                swap(&array[j], &array[j - 1]);  //若array[j]比前一个数小，则往前冒
    }
}


int main()
{
    int array[] = {5, 7, 2, 3, 8, 4, 1, 9};
    bubble_sort(array);
    int k;
    for(k = 0; k < LEN; k++)
        printf("%d ", array[k]);
    return 0;
}
