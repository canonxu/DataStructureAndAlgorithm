#ifndef STACK_H
#define STACK_H

 //ͨ������ʵ��ջ������ڵ�������ݺ�ָ����һ���ڵ��ָ��next
struct Node{
    int data;
    struct Node *next;
};

typedef struct Node *PNode;
typedef PNode PStack;  //PStackΪָ��ջԪ�أ������нڵ㣩��ָ��


PStack MakeNode(int i);
PStack CreatEmptyStack();
int IsEmptyStack(PStack s);
int Push(PStack s,PStack p);
int Pop(PStack s);
int GetTopEle(PStack s);
void ScreenAllEle(PStack s);
void SetEmpty(PStack s);

#endif
