#include <stdio.h>
#define LEN 8

//�ο���http://blog.csdn.net/insistgogo/article/details/7785038

//��������(QuickSort)���ʱ�临�Ӷ�ӦΪ0(n2)�����ʱ�临�Ӷ�ΪO(nlgn)��ƽ��ʱ�临�Ӷ�ΪO(nlgn)
//����������Ҳ����ʵ������õ�һ�������㷨���ٶȿ죬Ч�ʸ�!!!

//���������ʱ����Ҫ�ķ��ڻ��ֲ���(find_pivoit)�ϣ��Գ���Ϊk��������л��֣�����k-1�ιؼ��ֵıȽϡ�

//��ŦԪPivot��ѡȡ�ǳ���Ҫ��
//�����������ѡȡ��һ��Ԫ����ΪPivot��������������ѡ��һ��Ԫ�ؿ��Խ��ܣ�����������������/����/����ȫ���ʱ��ʹ�ø��Ӷȱ�ΪO��n^2��
//��ȫ�����������ѡȡ��ŦԪ�������������ȡa[ran]��a[low]��������������������ɱ�ʡ�а�������
/*
#include <time.h>
void(int *a, int low, int high)
{
    srand((unsigned int) time(0));
    swap(a[low],a[rand()%LEN]
}
*/
//������ֵ�ָ��ѡȡ��һ����a[0]�м����a[n/2]���һ����a[n]��������������ֵ���������ֵ������[0]������
/*
void MediaOfThree(int *a, int low, int high)  //������ʵ�ֽ���ֵ��ֵ��a[low]
{
    int mid = low + (high - mid)/2;
    if(a[mid] > a[high]) swap(a[mid], a[high]);  //a[mid] < a[high]
    if(a[low] > a[high]) swap(a[low], a[high]);  //a[low] < a[high];
    if(a[low] < a[mid]) swap(a[low], a[high])    //a[low] > a[low]           //����,a[mid] < a[low] < a[high]��������Ԫ��a[low]Ϊ��ֵ
}
*/


/*�ڲ�ѭ���е�while�������á��ϸ����/С�ڡ����ǡ����ڵ���/С�ڵ��ڡ����������ϸ����/С��
һ����뷨���ô��ڵ���/С�ڵ��ڣ���������ŦԪ��ͬ��Ԫ�أ��������Լ��ٲ���Ҫ�Ľ�������Ϊ��ЩԪ�����۷�����һ�߶���һ���ġ�
���������������Ԫ�ض�һ������������ַ���ÿ�ζ��������Ļ���,Ҳ����һ��1��Ԫ�أ���һ��n��1��Ԫ�أ�ʹ��ʱ�临�Ӷȱ��O(N^2)��
��������ϸ����/С �ڣ���Ȼ����ָ��ÿ��ֻŲ��1λ���������ǻ������м�����������һ����õĻ��֣�ʱ�临�Ӷ�Ϊlog(2n)
*/

//-------------------------------------------------------------------------------------------------------------------

//�������������ͷlowβhigh���õ��ָ���������ĵ�low��λ�ã���ʱlow��߾���a[low]С��low�ұ߾���a[low]��
//�Ե�һ��Ԫ��ΪPivot������

//����д��
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

//Ѱ�һ�׼��Ҳ������swapʵ�֡�����swapһ����3�θ�ֵ���ڴ��д�����϶࣡
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


//��ѭ���ϸ����/С�ڡ�
//��������£�a[low++] = a[high]���ƺ�low������a[high--] = a[low]��ֵ��high�Լ�����Ϊ��ʱlow/high��pivot��ֵ���ƶ������ܶ�����ֵͬ����������
int find_pivot_strict(int *a, int low, int high)
{
    int pivot = a[low];  //�������һ������Ϊ��׼������
    while(low < high)
    {
        while(low < high && a[high] > pivot) high--;      //�Ӻ���ǰ�������ҵ���һ��С�ڵ���key��ֵ���������a[low]�����
        if(low < high) a[low++] = a[high];
        while(low < high && a[low] < pivot) low++;    //��ǰ�����������ҵ���һ�����ڵ���key��ֵ�������������ڵ�a[high]�����
        if(low < high) a[high--] = a[low];
    }
        a[low] = pivot;  //�õ�һ���ڳ���pivot�ǰa[low]����ӣ��˵���λ����ȷλ�ã���������Ҫ�ҵĻ�׼��
        return low;
}



//���ģ�����Ԫ����ΪPivot�Ŀ���
int quick_sort(int *a, int low, int high)
{
    if(low >= high) return; //ֻ��һ��Ԫ�ص�ʱ��
    //�ҵ���׼��󣬲��÷��β��ԣ����߷ֱ�ݹ鼴��

    int pivot = find_pivot(a, low, high);
    quick_sort(a, low, pivot - 1);
    quick_sort(a, pivot + 1, high);

    return 0;
}



//-------------------------------------------------------------------------------------------------------------------------------
//�Ż�1�������������еĳ��ȷָһ����С��ʹ�ò�������(С��Χ�������)����ֹ��Χ�����������г���N = 10�ȽϺ��ʡ����ٵݹ�ջ��ʹ�ã���ϵͳջ��Ƶ����ȡӰ��Ч�ʣ���
void insertion_sort(int *a, int low, int high)
{
    int i, j, key;
    for(i = low; i <= high; i++)
    {
        key = a[i];
        j = i - 1;
        for(j; j >= low && a[j] > key; j--)
            a[j + 1] = a[j];
        a[j + 1] = key;
    }

}
int quick_sort1(int *a, int low, int high)
{
    if(low >= high) return; //ֻ��һ��Ԫ�ص�ʱ��

    if( 0 <(high - low + 1) < 10)              //�� ���ָ���С��10ʱ�����ò�������
            insertion_sort(a, low, high);

    if(low < high)
    {
        int pivot = find_pivot(a, low, high);
        quick_sort(a, low, pivot - 1);
        quick_sort(a, pivot + 1, high);
    }
    return 0;
}

//�Ż�2�����"�������"����ȫ����Ǹ��Ӷ�ΪO��n^2�����⡣��һ�ηָ����pivot��ȵ�ֵ����һ�Σ��´ηָ��ʱ���ڶ�piovt��ȵ�ֵ���зָ
//��һ�����ڻ��ֹ����У�����key���Ԫ�ط������������
//�ڶ��������ֽ����󣬰���key��ȵ�Ԫ���Ƶ�������Χ

int quick_sort(int *a, int low, int high)
{
    if(low >= high) return; //ֻ��һ��Ԫ�ص�ʱ��

    int pivot = a[low];  //�������һ������Ϊ��׼������

    int first = low;
    int last = high;
    int right = high;
    int right_same = 0;  //�ұߵ���pivot��ֵ�ĸ���
    int low = left;
    int lest_same = 0  //��ߵ���pivot��ֵ�ĸ���
    while(low < high)
    {
        while(low < high && a[high] >= pivot)
        {
            if(a[high] == pivot)           //��a[high]����pivot���Ƶ����ұ�
            {
                swap(a[high], a[right]);
                right--;
                right_same++;
            }
        }
        high--;
        a[low] = a[high];

        while(low < high && a[low] <= pivot)
        {
                if(a[low] == pivot)           //��a[low]����pivot���Ƶ������
                {
                swap(a[low], a[left]);
                left++;
                right_same++;
                }
        }
        low++;
        a[high] = a[low];
    }
    a[low] = pivot;  //���ˣ��ҵ���׼��a[low]����ɵ�һ��

    int i = low - 1;            //��������˵���pivot��ֵ�Ƶ�����pivot����
    int j = first;
    while(j < low && a[i] != pivot)
    {
        swap(a[j], a[i]);
        i--;
        j++
    }

    i = low + 1;               //�������Ҷ˵���pivot��ֵ�Ƶ�����pivot����
    j = last;
    while(j > low && a[i] != pivot)
    {
        swap(a[j], a[i]);
        i++;
        j--;                  //���ˣ���ɵڶ���
    }

    quick_sort(a, first , pivot - 1 - left_same );
    quick_sort(a, pivot + 1 + right_same, last);
    }
    return 0;
}






//�Ż�3��β�ݹ��Ż����ݹ������ĩβ�������ź����ں���β�������εݹ���������ǿ��Զ���ʹ��β�ݹ��Ż�������β�ݹ��Ż�һ���ɱ�������ɡ�
//�ŵ㣺�������������л��ּ��˲�ƽ�⣬�ݹ����Ƚ�������n����ջ�Ĵ�С�Ǻ����޵ģ�ÿ�εݹ���ö���ķ�һ����ջ�ռ䣬�����Ĳ���Խ�࣬ÿ�εݹ�ķѵĿռ�ҲԽ������ջ�����
//�Ż��󣬿���������ջ��ȣ���ԭ����O(n)����ΪO(logn)������������ܡ�
int quick_sort2(int *a, int low, int high)
{
    if(low >= high) return; //ֻ��һ��Ԫ�ص�ʱ��

    if( 0 <(high - low + 1) < 10)
            insertion_sort(a, low, high);


    int pivot = find_pivot(a, low, high);
    quick_sort(a, low, pivot - 1);
    low = pivot + 1;   //�ڵ�һ�εݹ��low��û���ˣ���ʱ�ڶ��εݹ����ʹ��ѭ�����档

    return 0;
}

int main()
{

    int array[] = {2, 2, 2, 3, 2, 4, 2, 2};
    quick_sort(array, 0, LEN - 1);
    int k;
    for(k = 0; k < LEN; k++)
        printf("%d ", array[k]);
    return 0;
}

