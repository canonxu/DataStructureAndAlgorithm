#include <stdio.h>
#define LEN 8


//ϣ�������ʵ�ʾ��Ƿ����������,�ֳơ���С��������
//����������Ԫ�����зָ�����ɸ������зֱ����ֱ�Ӳ�������Ȼ�����μ�С������������
// �����������е�Ԫ�ػ������������㹻С��ʱ���ٶ�ȫ��Ԫ�ؽ���һ��ֱ�Ӳ�������(�൱������Ϊ1�Ĳ�������)��
//��Ϊֱ�Ӳ���������Ԫ�ػ������������£��ӽ�����������Ч���Ǻܸߵ�O(n)�����ϣ��������ʱ��Ч���ϱ�ǰ���ַ����нϴ���ߡ�

//ϣ������ƽ��ʱ�临�Ӷ� O(nlogn)-O(n^2)/O(n^1.3)�����ʱ�临�Ӷ�O(n^2)�����ʱ�临�Ӷ�O(n)�����彲���ӶȲ���˵������ѡȡ�ܹؼ������ջ���ø��Ӷȣ�
//����ѡ���Ǵ�n/2��ʼ��ÿ���ټ��룬ֱ�����Ϊ1

//ϣ�������ȶ�


int shell_sort1(int *a)
{
    int i, j, gap, key;
    for(gap = LEN/2; gap > 0; gap /= 2)
    {
        for(i = gap; i < LEN; i++)
        {
            key = a[i];
            for(j = i - gap; j >= 0 && a[j] > key;j -= gap)
                a[j + gap] = a[j];
            a[j + gap ] = key;
        }
    }
    return 0;
}


void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int  shell_sort(int *a)
{
    int i, j,gap;
    for(gap = LEN/2; gap > 0; gap /= 2)  //�磺gapΪ5���Ϊ���飬ÿ���ڲ��������� ��Ҫһֱѭ����gap=1��gap>0����
        for(i = gap; i < LEN; i++)  //����Ӧ��gap�����в�������
            for(j = i - gap; j >= 0; j -= gap)
            {
                if(a[j] > a[j + gap])
                    swap(&a[j], &a[j + gap]);
            }
    return 0;
}


int main()
{
    int array[] = {5, 7, 2, 3, 8, 4, 1, 9};
    shell_sort1(array);
    int k;
    for(k = 0; k < LEN; k++)
        printf("%d ", array[k]);
    return 0;
}
