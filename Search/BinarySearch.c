#include <stdio.h>

//二分搜索的前提：有序数组
//常规做法对数组进行遍历时间复杂度为O(n),二分搜索将时间复杂度降到O(lgn),非常常用。


//迭代法实现二分搜索
int BinSearch_iteration(int *array, int low, int high, int x)
{
    while(low <= high)
    {
        int mid = (low + high )/2;
        if(array[mid] < x)
            low = mid + 1;
        else if(array[mid] > x)
            high = mid - 1;
        else
            return mid;
    }
    return -1; //没找到
}

//递归法实现二分搜索
int BinSearch_recurse(int *array, int low, int high, int x)
{
    while(low <= high)
    {
        int mid = (low + high)/2;
        if(array[mid] < x)
            return BinSearch_recurse(array, mid + 1, high, x);
        if(array[mid] > x)
            return BinSearch_recurse(array, low, mid - 1,x);
        else
            return mid;
    }
    return -1; //没找到
}

int main()
{
    int array[] = {1,4,8,12,14,25,56,99};
    int s;
   // s = BinSearch_iteration(array, 0, 5, 14);  //迭代法验证
    s = BinSearch_recurse(array, 2, 6, 56);  //递归法验证
    printf("%d\n%d\n", s, array[s]);
    return 0;
}
