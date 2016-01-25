#include <stdio.h>
#define LEN 10

//内循环严格大于/小于。
//这种情况下，a[low++] = a[high]复制后将low自增，a[high--] = a[low]赋值后将high自减。因为此时low/high到pivot等值后不移动，不能对有相同值得数组排序。
int find_pivot_strict(int *a, int low, int high)
{
    int pivot = a[low];  //以数组第一个数作为基准，挖走
    while(low < high)
    {
        while(low < high && a[high] > pivot) high--;      //从后往前搜索，找到第一个小于等于key的值，挖走填充a[low]这个坑
        if (low < high) a[low++] = a[high];
        while(low < high && a[low] < pivot) low++;    //从前往后搜索，找到第一个大于等于key的值，挖走填上面挖的a[high]这个坑
        if (low < high) a[high--] = a[low];
    }
        a[low] = pivot;  //用第一次挖出的pivot填当前a[low]这个坑，此点已位于正确位置，就是我们要找的基准点
        return low;
}

int find_pivot(int *a, int low, int high)
{
    int pivot = a[low];  //以数组第一个数作为基准，挖走
    while(low < high)
    {
        while(low < high && a[high] >= pivot) high--;      //从后往前搜索，找到第一个小于key的值，挖走填充a[low]这个坑
        a[low] = a[high];
        while(low < high && a[low] <= pivot) low++;    //从前往后搜索，找到第一个大于key的值，挖走填上面挖的a[high]这个坑
        a[high] = a[low];
    }
        a[low] = pivot;  //用第一次挖出的pivot填当前a[low]这个坑，此点已位于正确位置，就是我们要找的基准点
        return low;
}

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int find_pivot_swap(int *a, int low, int high)
{
    int pivot = a[low];  //以数组第一个数作为基准，挖走。 此处基准可换a[high]/a[median]即可
    while(low < high)
    {
        while(low < high && a[high] >= pivot) high--;      //从后往前搜索，找到第一个小于key的值，挖走填充a[low]这个坑
        swap(&a[high], &a[low]);
        while(low < high && a[low] <= pivot) low++;    //从前往后搜索，找到第一个大于key的值，挖走填上面挖的a[high]这个坑
        swap(&a[high], &a[low]);
    }
        return low;
}


int quick_sort(int *a, int low, int high)
{
    if(low >= high) return; //只有一个元素的时候
    //找到基准点后，采用分治策略，两边分别递归即可
    if(low < high)
    {
        int pivot = find_pivot(a, low, high);
        quick_sort(a, low, pivot - 1);
        quick_sort(a, pivot + 1, high);
    }
    return 0;
}

int main()
{

    int array[] = {1, 4, 6, 7, 6, 6, 7, 6,8,6};
    quick_sort(array, 0, LEN - 1);
    int k;
    for(k = 0; k < LEN; k++)
        printf("%d ", array[k]);
    return 0;
}

