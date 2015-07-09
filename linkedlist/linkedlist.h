/* linkedlist.h */

#ifndef LINKEDLIST_H
#define LINKEDLIST_H



//����ڵ�
struct Node
{
    int data;
    struct Node *next;
};

typedef struct Node *PNode;

//�����б�
PNode CreatEmptyList();//������������ͷָ��head
PNode MakeNode(int data); //����ֵΪdata�Ľڵ�

PNode push(int data);  //��βpush
void pop(void);  //��βpop

PNode SearchNodeByData(int data);  //ͨ���ṹ������ݲ�ڵ�
PNode SearchNodeByCount(int count);  //ͨ���ṹ������кŲ�ڵ�
int CountNode(PNode p); //ͨ���ڵ�����к�
PNode PreNode(PNode p); //��ǰ��
PNode ModifyNode(PNode p, int data); //��
PNode DeleteNode(PNode p);  //ɾ
PNode InsertNode(int count, PNode p); //��

#endif

