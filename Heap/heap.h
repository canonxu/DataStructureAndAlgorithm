#ifndef HEAP_H
#define HEAP_H

struct Heap{
    int capacity;  //�ѵ��������
    int size;  //��ǰ�ѵĴ�С
    int *array; //������ʵ��heap
};

typedef struct Heap* PHeap;

#endif

