#include <stdio.h>
#define LEN 8

 // 归并排序的时间复杂度O（nlogn），与其他O（nlogn）的算法（快排，希尔排序，堆排序）相比，效率是比较高的。




void merge(int *a, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int left[n1], right[n2];
    int i, j;
    for (i = 0; i < n1; i++)
        left[i] = a[start+i];
    for (j = 0; j < n2; j++)
        right[j] = a[mid + 1 + j];  //先表示出左数组和右数组，下将这两个数组填充到原数组a中

    i = j= 0;
    int k = start;
    while (i < n1 && j < n2)  //若左右数组都有元素，比较后小的先填充到a，自增1
        if (left[i] < right[j])
            a[k++] = left[i++];  //a[k++]，++在后则先执行在自增，即先a[k]后k自增1  //i++先执行载自增，++i先自增再赋值
        else
            a[k++] = right[j++];
    while(i < n1)          //若左/右数组一个满了，则将未满的数组全部填充到a
        a[k++] = left[i++];
    while(j < n2)
        a[k++] = right[j++];
}


// 归并排序的“排序部分”，采用递归方式，复杂度logn
void sort(int *a, int start, int end)
{
    int mid;
    if (start < end) {
        mid=(start + end) / 2;
        sort(a, start, mid);  // start - mid排序
        sort(a, mid+1, end);  //mid+1 - end排序
        merge(a, start, mid, end);  //将两部分排序合并
    }

}

int main(void)
{
    int a[LEN]={1,4,6,7,8,0,9,3};
    sort(a, 0, 7);
    int m;
    for (m=0; m<LEN; m++)
        printf("%d ", a[m]);
    return 0;
}
