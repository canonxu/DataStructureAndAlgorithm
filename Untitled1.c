#include <stdio.h>
#define LEN 10

//��ѭ���ϸ����/С�ڡ�
//��������£�a[low++] = a[high]���ƺ�low������a[high--] = a[low]��ֵ��high�Լ�����Ϊ��ʱlow/high��pivot��ֵ���ƶ������ܶ�����ֵͬ����������
int find_pivot_strict(int *a, int low, int high)
{
    int pivot = a[low];  //�������һ������Ϊ��׼������
    while(low < high)
    {
        while(low < high && a[high] > pivot) high--;      //�Ӻ���ǰ�������ҵ���һ��С�ڵ���key��ֵ���������a[low]�����
        if (low < high) a[low++] = a[high];
        while(low < high && a[low] < pivot) low++;    //��ǰ�����������ҵ���һ�����ڵ���key��ֵ�������������ڵ�a[high]�����
        if (low < high) a[high--] = a[low];
    }
        a[low] = pivot;  //�õ�һ���ڳ���pivot�ǰa[low]����ӣ��˵���λ����ȷλ�ã���������Ҫ�ҵĻ�׼��
        return low;
}

int find_pivot(int *a, int low, int high)
{
    int pivot = a[low];  //�������һ������Ϊ��׼������
    while(low < high)
    {
        while(low < high && a[high] >= pivot) high--;      //�Ӻ���ǰ�������ҵ���һ��С��key��ֵ���������a[low]�����
        a[low] = a[high];
        while(low < high && a[low] <= pivot) low++;    //��ǰ�����������ҵ���һ������key��ֵ�������������ڵ�a[high]�����
        a[high] = a[low];
    }
        a[low] = pivot;  //�õ�һ���ڳ���pivot�ǰa[low]����ӣ��˵���λ����ȷλ�ã���������Ҫ�ҵĻ�׼��
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
    int pivot = a[low];  //�������һ������Ϊ��׼�����ߡ� �˴���׼�ɻ�a[high]/a[median]����
    while(low < high)
    {
        while(low < high && a[high] >= pivot) high--;      //�Ӻ���ǰ�������ҵ���һ��С��key��ֵ���������a[low]�����
        swap(&a[high], &a[low]);
        while(low < high && a[low] <= pivot) low++;    //��ǰ�����������ҵ���һ������key��ֵ�������������ڵ�a[high]�����
        swap(&a[high], &a[low]);
    }
        return low;
}


int quick_sort(int *a, int low, int high)
{
    if(low >= high) return; //ֻ��һ��Ԫ�ص�ʱ��
    //�ҵ���׼��󣬲��÷��β��ԣ����߷ֱ�ݹ鼴��
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

