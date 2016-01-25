#include <stdio.h>

#define LEN 8  //宏定义慎用sizeof(array)/sizeof(int)，array作为参数退化为数组首元素的指针，所以sizeof(array)/sizeof(int) == 1而不是数组长度



// 插入排序：将一个新数据（key）插入到已经排好序的有序数据中，从而得到一个新的、个数加一的有序数据。（类似于玩牌时，插入新的牌）
// 从数组的第二个数开始，作为要插入的key，跟前面已经排好序的数组中的每个数进行比较，若符合插入条件（key<a[i]），则插入

//两层嵌套，时间平均复杂度为O（n2）,适用于少量数据的排序。 //最坏的情况：O（n2）， 最好的情况（前面已排好，while这层嵌套用不上）：O（n）

//插入排序是稳定的排序
//排序稳定就是指: 如果2个数相等的时候，排序后不会影响它们原来的顺序
//选择排序、快速排序、希尔排序、堆排序不是稳定的排序算法，而冒泡排序、插入排序、归并排序和基数排序是稳定的排序算法

void insertion_sort(int *array);  //返回值为void类型函数 insertion_sort，若置于main（）前则不需声明该函数，若之后则需要先这样声明该函数

void insertion_sort1(int *a);

int main()
{
    int array[] = {1, 3, 2, 6, 5, 7, 4, 9};
    insertion_sort(array);     //此处调用insertion_sort后，a中内存顺序并未改变，所以主函数中打印输出仍然是乱序。 解决办法是在insertion_sort中打印出来
    int k;
    for(k = 0; k < LEN; k++)
        printf("%d ", array[k]);
    return 0;
}


void insertion_sort(int *a)
{
    int i, j, key;
    for (i = 1; i < LEN; i++)   //从数组的第二个数开始，往前插
    {
        key = a[i];
        for(j = i - 1; j >= 0 && a[j] > key; j--) //跟前面的依次比较。 若要求从小到大排：若比key大，则后移一位，直到不大于key的！
            a[j + 1] = a[j];                      //若要求从大到小排，若比key小，则后移一位，直到不小于key的!
        a[j+1] = key;
    }
}


