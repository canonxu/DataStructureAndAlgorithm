#ifndef HEAP_H
#define HEAP_H

struct Heap{
    int capacity;  //堆的最大容量
    int size;  //当前堆的大小
    int *array; //用数组实现heap
};

typedef struct Heap* PHeap;

#endif

