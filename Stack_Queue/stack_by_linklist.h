#ifndef STACK_H
#define STACK_H

 //通过链表实现栈，链表节点包含数据和指向下一个节点的指针next
struct Node{
    int data;
    struct Node *next;
};

typedef struct Node *PNode;
typedef PNode PStack;  //PStack为指向栈元素（链表中节点）的指针


PStack MakeNode(int i);
PStack CreatEmptyStack();
int IsEmptyStack(PStack s);
int Push(PStack s,PStack p);
int Pop(PStack s);
int GetTopEle(PStack s);
void ScreenAllEle(PStack s);
void SetEmpty(PStack s);

#endif
