//�����Ƚ��������ջһ������ʹ��������������ַ�ʽʵ�֡�
//���е�����ʵ�ֽ�����ʵ�ּ򵥡�������������front��rear����rear��push��front��pop��

#ifndef QUEUE_H
#define QUEUE_H


// ����Queue�Ľṹ�壬����Queue��������Queue��front��rear��Queue��ʵ�ʴ�С��Quueue�����顣
struct Queue
{
    int capacity;
    int front;
    int rear;
    int size;
    int *array;
};

typedef struct Queue *PQueue; //PQueueΪָ����е�ָ��


void CreateQueue(int MaxQueueSize)
void MakeEmpty(PQueue q)
int IsEmptyQueue(PQueue q)
int IsFullQueue(PQueue q)
void DeQueue(PQueue q)
void EnQueue(PQueue q, int x)
int GetQueueSize(PQueue q)
void ScreenAllEle(PQueue q)
#enfif
