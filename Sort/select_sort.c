#include <stdio.h>
#define LEN 8

//�ع�ð������ÿһ����ѭ������Ϊ���ҵ�һ����Сֵð������������ж������swap�Ĵ��ۺܴ�
//��ѡ�������У�����ѭ����ѭ����Χһ���ģ�ֻ��ѡ���������ѭ��ֱ���ҵ���Сֵ�����ֻswapһ�μ��ɡ�
//����ѡ�������ð�������ʱ�临�Ӷ�һ���ģ���ѡ������Ҫ��

//�����ⲿ�ռ�t���н���
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

int select_sort(int *a)
{
    int i, j;
    for(i = 0; i < LEN; i++)
    {
        int flag = i;
        for(j = i + 1; j < LEN; j++)
        {
            if(a[j] < a[flag])
                flag = j;   //�ҳ�i��LEN-1����Сֵ����¼��Сֵ��λ��
        }
        swap(&a[i], &a[flag]);
    }

    return 0;
}


int main()
{
    int array[] = {5, 7, 2, 3, 8, 4, 1, 9};
    select_sort(array);
    int k;
    for(k = 0; k < LEN; k++)
        printf("%d ", array[k]);
    return 0;
}
