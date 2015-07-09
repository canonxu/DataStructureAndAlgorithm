//队列的链表实现与链表实现Stack类似。区别是Stake头节点中只有一个指针，从链表头PUSH且从链表头POP。
//Queue头结点中设置队头指针和队尾指针（capcacity和size可选），从队尾rear端PUSH队头front端POP。

#ifndef QUEUE_H
#define QUEUE_H


//定义链表节点，与普通链表无异
typedef struct Node *PNode;
struct Node
{
    int data;
    PNode next;
};

//定义表示队列的结构体，包含队列容量capcacity，实际大小size，游标front和rear四个参数。
typedef stru Queue *PQueue;
struct Queue
{
    int capcacity;
    PNode front;
    PNode rear;
    int size;
};

PQueue CreatEmptyQueue(int MaxQueueSize);
PQueue MakeEmpty(PQueue q);
PNode MakeNode(int data);
int IsEmptyQueue()；
int IsFullQueue()；
void DeQueue (PQueue q)；
void EnQueue(PQueue q, int data)；
void ScreenAllEle(PQueue q)；

#enif
