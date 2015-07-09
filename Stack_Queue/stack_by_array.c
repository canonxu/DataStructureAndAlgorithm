#include<stdio.h>
#define LEN sizeof(struct Stack)
#define EmptyTopCount -1
#define MinStackSize 5

//用数组创建栈，一开始传入参数MaxSize指定实现栈的数组大小。这是与linkedlist实现栈的一个区别。
//对空栈的POP和对满栈的PUSH将引发数组越界。较容易发生。

//初始化一个栈，分别初始化指向该栈的指针和该栈（结构体）中的栈容量，栈顶游标，栈数组
PStack CreatStack(int MaxStackSize)
{
    if (MaxStackSize < MinStackSize)
        printf("Stack size is too small!");
    //初始化指向栈的指针
    PStack s = NULL;
    s = PStack malloc(LEN);  //为指向栈的指针分配空间。
    if (s == NULL)
        printf("Memory allocation failure!");

    //初始化栈的大小
    s->capacity = MaxStackSize;

    //初始化栈顶游标
    s->topcount = EmptyTopCount;

    //初始化栈中的数组，array为指向数组首元素的指针。
    s->array = int *malloc(sizeof(int)*MaxStackSize);
    if (s->array == NULL)
        printf("Memory allocation failure!");

    return s;
}


s = CreatStack(20)  //创建,s为栈名，也为指向该栈结构体的指针


// 销毁栈，先销毁栈内数组，再销毁栈结构体
void DisposeStack(PStack s)
{
    if(s->topcount != EmptyTopCount)  //判断是否为空栈
    {
        free(s->array);
        free(s);
    }
}

//将栈置空，栈顶游标topcount为-1. 由此，若栈有一个元素，栈顶topcount为0。
void MakeEmpty(PStack s)
{
    s->topcount = EmptyTopCount;
}

//判断栈是否为空
int IsEmptyStack()
{
    return s->topcount == EmptyTopCount;
}

//判断栈是否为满
int IsFullStack()
{
    return s->topcount == s->capacity-1;
}

//压栈时，需检查占空间是否已满。
//s->array[++s->topcount] = x; 游标topcount自增1，同时将需要压入的值赋值给栈顶
void push(int x, PStack s)
{
    if(s->topcount = MaxStackSize-1) //判断栈是否已满
        printf("This stack is full!");
    s->array[++s->topcount] = x;
}


//出栈时，需检查是否为空栈
//free(s->array[topcount]); 释放栈顶元素 s->topcount--;游标topcount自减1
void pop(PStack s)
{
    if(s->topcount == EmptyTopCount)  //判断是否为空栈
        printf("This stack is empty");
    free(s->array[topcount]);
    s->topcount--;
}

//获得栈顶元素，首先判断是否为空栈
//栈顶元素 s->array[s->topcount];
int GetTopEle(PStack s)
{
    if (s->topcount == EmptyTopCount)
    {
        printf("This stack is empty");
        return 0;
    }
    return s->array[s->topcount];
}

//扫描整个栈，首先判断是否为空栈。
//通过s->topcount--的方式实现栈内的遍历
void ScreenAllEle(PStack s)
{
    if(s->topcount == EmptyTopCount)  //判断是否为空栈
        printf("This stack is empty");

    for(s->topcount; s->topcount > EmptyTopCount; s->topcount--)
        printf("%d", s->array[s->topcount]);
}

