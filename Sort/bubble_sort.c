#include<stdio.h>
#define LEN 8


//ð�������ʱ�临�Ӷ�ΪO��n2��,Ч�ʵ���һ�㲻�ã�
//ð���������ȶ������򣬼�������ȵ�������������ǰ��λ�ò���


//��дswap����ʽ��ֱ��swap��int a�� int b��������ʱ�ᷢ��û�С���Ϊ���ǡ�ֵ���ݡ���
//ֵ�����ڵ��õ�ʱ�򣬽�ʵ�ʲ�������һ�ݴ��ݵ����������У��β���ʵ�εĿ����������ܸú�����ʲô��ʵ�ʵĲ��������䣨�ı��βε�ֵ�����ı��ⲿʵ�ε�ֵ����


//�������ɲ������ⲿ�ռ���н�����ȱ���ǣ����ܽ�����ȵ�ֵ����ȵ�ֵ��������Ϊ0��
void swap_bit(int *a, int *b)
{
    if(*a == *b) return;  //���ֵ��ȣ�ֱ�ӷ��أ�����Ҫswap
    *a = *a ^ *b;
    *b = *b ^ *a;
    *a = *a ^ *b;
}

//�����ⲿ�ռ�t���н���
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}


void bubble_sort(int *array)
{
    int i, j;
    for(i = 0; i < LEN; i++)  //ÿѭ��һ�Σ���С����ð�ݵ�����
    {
        for(j = LEN - 1; j > i; j--)
            if(array[j] < array[j - 1])
                swap(&array[j], &array[j - 1]);  //��array[j]��ǰһ����С������ǰð
    }
}


int main()
{
    int array[] = {5, 7, 2, 3, 8, 4, 1, 9};
    bubble_sort(array);
    int k;
    for(k = 0; k < LEN; k++)
        printf("%d ", array[k]);
    return 0;
}
