#ifndef LINKEDLIST_H
#define LINKEDLIST_H


//用结构体表示栈。栈属性包括“栈的大小capacity”，“栈顶游标topcount”和“存放栈元素的数组array”。
struct Stack{
    int capacity;  //
    int topcount;
    int array[];  //等同于int *array，array表示一个存储int型数据的数组的首元素的指针
};

typedef struct Stack *PStack; //PStack表示指向栈的指针


PStack CreatStack(int MaxStackSize)；
void DisposeStack(PStack s)；
void MakeEmpty(PStack s)；
void push(int x, PStack s)；
void pop(PStack s)；
int GetTopEle(PStack s）；
void ScreenAllEle(PStack s)；

#endif
