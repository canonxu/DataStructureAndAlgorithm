#include <stdio.h>

#define LEN sizeof(a)/4

int a[] = {1,3,2,9,7,5,4,6};

// 插入排序：将一个新数据（key）插入到已经排好序的有序数据中，从而得到一个新的、个数加一的有序数据。（类似于玩牌时，插入新的牌）
// 从数组的第二个数开始，作为要插入的key，跟前面已经排好序的数组中的每个数进行比较，若符合插入条件（key<a[i]），则插入
//时间复杂度为O（n2）,适用于少量数据的排序

void insertion_sort(int a[])
{
    int i,j,key;
    for (j=1; j < LEN; j++)   //从数组的第二个数开始，往前插
    {
        key =a[j];
        for(i = j-1; i>=0; i--)
        {
            if(a[i] > key)
                a[i+1] = a[i];
            else break;
        }
    //跟前面的依次比较，
    //若要求从小到大排：若比key大，则后移一位，直到不大于key的，break！
    //若要求从大到小排，若比key小，则后移一位，直到不小于key的，break!
        a[i+1]=key;
    }
}



int main(void)
{
    insertion_sort(a);
    int i=0;
    for (i=0; i < LEN; i++)
        printf("%d", a[i]);
    return 0;
}
