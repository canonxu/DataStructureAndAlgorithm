#include <stdio.h>

//����������ǰ�᣺��������
//����������������б���ʱ�临�Ӷ�ΪO(n),����������ʱ�临�ӶȽ���O(lgn),�ǳ����á�


//������ʵ�ֶ�������
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
    return -1; //û�ҵ�
}

//�ݹ鷨ʵ�ֶ�������
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
    return -1; //û�ҵ�
}

int main()
{
    int array[] = {1,4,8,12,14,25,56,99};
    int s;
   // s = BinSearch_iteration(array, 0, 5, 14);  //��������֤
    s = BinSearch_recurse(array, 2, 6, 56);  //�ݹ鷨��֤
    printf("%d\n%d\n", s, array[s]);
    return 0;
}
