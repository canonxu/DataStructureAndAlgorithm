//���е�����ʵ��������ʵ��Stack���ơ�������Stakeͷ�ڵ���ֻ��һ��ָ�룬������ͷPUSH�Ҵ�����ͷPOP��
//Queueͷ��������ö�ͷָ��Ͷ�βָ�루capcacity��size��ѡ�����Ӷ�βrear��PUSH��ͷfront��POP��

#ifndef QUEUE_H
#define QUEUE_H


//��������ڵ㣬����ͨ��������
typedef struct Node *PNode;
struct Node
{
    int data;
    PNode next;
};

//�����ʾ���еĽṹ�壬������������capcacity��ʵ�ʴ�Сsize���α�front��rear�ĸ�������
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
int IsEmptyQueue()��
int IsFullQueue()��
void DeQueue (PQueue q)��
void EnQueue(PQueue q, int data)��
void ScreenAllEle(PQueue q)��

#enif
