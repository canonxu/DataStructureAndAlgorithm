//队列先进后出，与栈一样可以使用链表和数组两种方式实现。
//队列的数组实现较链表实现简单。在数组内设置front和rear。从rear端push从front端pop。

#ifndef QUEUE_H
#define QUEUE_H


// 定义Queue的结构体，包含Queue的容量，Queue的front，rear，Queue的实际大小，Quueue内数组。
struct Queue
{
    int capacity;
    int front;
    int rear;
    int size;
    int *array;
};

typedef struct Queue *PQueue; //PQueue为指向队列的指针


void CreateQueue(int MaxQueueSize)
void MakeEmpty(PQueue q)
int IsEmptyQueue(PQueue q)
int IsFullQueue(PQueue q)
void DeQueue(PQueue q)
void EnQueue(PQueue q, int x)
int GetQueueSize(PQueue q)
void ScreenAllEle(PQueue q)
#enfif
