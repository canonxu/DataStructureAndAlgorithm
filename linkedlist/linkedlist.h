/* linkedlist.h */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H



//定义节点
struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node *PNode;

//函数列表
PNode CreatEmptyList();//创建链表，包含头指针head
PNode MakeNode(int data); //创建值为data的节点

PNode push(int data);  //表尾push
void pop(void);  //表尾pop

PNode SearchNodeByData(int data);  //通过结构体的数据查节点
PNode SearchNodeByCount(int count);  //通过结构体的序列号查节点
int CountNode(PNode p); //通过节点查序列号
PNode PreNode(PNode p); //查前驱
PNode ModifyNode(PNode p, int data); //改
PNode DeleteNode(PNode p);  //删
PNode InsertNode(int count, PNode p); //增

#endif

