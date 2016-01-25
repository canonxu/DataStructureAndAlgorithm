#include <stdio.h>
#define LEN 8

//注：为了叙述方便，本文以及源代码中均不考虑a[0],默认下标从1开始。

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
/*** 堆排序的核心 ***/
//递归法
void Heap_Adjust1(int *a, int i, int size)  //i表示从第i个节点开始调整，size表示数组大小即调整的终止节点
{
    int child = 2 * i;
    if(child != size && a[child] < a[child+1])  //节点有两个儿子的情况，找到儿子中的较大值
        child++;
    while(child <= size && a[child] > a[i])  //构建最大堆，先限定child范围，若儿子比父亲大，则互换位置，对换位后的儿子节点递归
    {
        swap(&a[i], &a[child]);
        Heap_Adjust1(a, child, size);  //若有交换，那么还需对child节点进行维护
    }
}


//迭代法
void Heap_Adjust(int *a, int i, int size)  //i表示从第1个节点开始调整，size表示数组大小即重点节点
{
    int key = a[i];
    int child;
    for(i; i <= size/2; i = child)
    {
        child = 2 * i;
        if(child != size && a[child] < a[child+1])  //节点有两个儿子的情况，找到儿子中的较大值
            child++;
        if(a[child] > key)
            a[i] = a[child];
        else  break;
    }
    a[i] = key;
}

//输入一个数字，将其建成最大堆
void Initial_MaxHeap(int *a, int size)
{
    int i;
    for(i = size/2; i >= 1; i--)  //将建立的堆结构调整成最大堆，从(H->size)/2节点开始往上，调整成最大堆
        Heap_Adjust1(a, i,size);
}


void heap_sort(int *a, int size)
{
    Initial_MaxHeap(a, size);  //将需要排序的数组创建成堆结构，并建立成最大堆
    int i;
    for(i = size; i > 1; i--)
    {
        swap(&a[1], &a[i]);   //将数组首元素依次交换到后面（越往后值越大），前面部分继续调整成最大堆
        Heap_Adjust1(a, 1, i-1);
    }

}


//本例程中，从数组的第二个数a[1]开始进行排序
int main()
{
    int a[] = {5, 7, 2, 3, 8, 5,6, 9};
    heap_sort(a,LEN-1);
    int k;
    for(k = 1; k < LEN; k++)
    printf("%d  ", a[k]);
    return 0;
}
