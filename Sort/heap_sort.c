#include <stdio.h>
#define LEN 8

//ע��Ϊ���������㣬�����Լ�Դ�����о�������a[0],Ĭ���±��1��ʼ��

void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
/*** ������ĺ��� ***/
//�ݹ鷨
void Heap_Adjust1(int *a, int i, int size)  //i��ʾ�ӵ�i���ڵ㿪ʼ������size��ʾ�����С����������ֹ�ڵ�
{
    int child = 2 * i;
    if(child != size && a[child] < a[child+1])  //�ڵ����������ӵ�������ҵ������еĽϴ�ֵ
        child++;
    while(child <= size && a[child] > a[i])  //�������ѣ����޶�child��Χ�������ӱȸ��״��򻥻�λ�ã��Ի�λ��Ķ��ӽڵ�ݹ�
    {
        swap(&a[i], &a[child]);
        Heap_Adjust1(a, child, size);  //���н�������ô�����child�ڵ����ά��
    }
}


//������
void Heap_Adjust(int *a, int i, int size)  //i��ʾ�ӵ�1���ڵ㿪ʼ������size��ʾ�����С���ص�ڵ�
{
    int key = a[i];
    int child;
    for(i; i <= size/2; i = child)
    {
        child = 2 * i;
        if(child != size && a[child] < a[child+1])  //�ڵ����������ӵ�������ҵ������еĽϴ�ֵ
            child++;
        if(a[child] > key)
            a[i] = a[child];
        else  break;
    }
    a[i] = key;
}

//����һ�����֣����佨������
void Initial_MaxHeap(int *a, int size)
{
    int i;
    for(i = size/2; i >= 1; i--)  //�������Ķѽṹ���������ѣ���(H->size)/2�ڵ㿪ʼ���ϣ�����������
        Heap_Adjust1(a, i,size);
}


void heap_sort(int *a, int size)
{
    Initial_MaxHeap(a, size);  //����Ҫ��������鴴���ɶѽṹ��������������
    int i;
    for(i = size; i > 1; i--)
    {
        swap(&a[1], &a[i]);   //��������Ԫ�����ν��������棨Խ����ֵԽ�󣩣�ǰ�沿�ּ�������������
        Heap_Adjust1(a, 1, i-1);
    }

}


//�������У�������ĵڶ�����a[1]��ʼ��������
int main()
{
    int a[] = {5, 7, 2, 3, 8, 5,6, 9};
    heap_sort(a,LEN-1);
    int k;
    for(k = 1; k < LEN; k++)
    printf("%d  ", a[k]);
    return 0;
}
