#ifndef LINKEDLIST_H
#define LINKEDLIST_H


//�ýṹ���ʾջ��ջ���԰�����ջ�Ĵ�Сcapacity������ջ���α�topcount���͡����ջԪ�ص�����array����
struct Stack{
    int capacity;  //
    int topcount;
    int array[];  //��ͬ��int *array��array��ʾһ���洢int�����ݵ��������Ԫ�ص�ָ��
};

typedef struct Stack *PStack; //PStack��ʾָ��ջ��ָ��


PStack CreatStack(int MaxStackSize)��
void DisposeStack(PStack s)��
void MakeEmpty(PStack s)��
void push(int x, PStack s)��
void pop(PStack s)��
int GetTopEle(PStack s����
void ScreenAllEle(PStack s)��

#endif
