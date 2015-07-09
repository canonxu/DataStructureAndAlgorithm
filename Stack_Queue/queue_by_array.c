#include<stdio.h>
#define LEN sizrof(struct Queue)
#define MinQueueSize 5;
/*
约定：初始化建空队时，令front=rear=0,当队空时：front=rear 当队满时：front=rear 亦成立.因此只凭等式front=rear无法判断队空还是队满。
有两种方法处理上述问题：
（1）另设一个标志位以区别队列是空还是满。front指向第一个有效节点，rear指向最后一个有效节点，用q-size记录实际大小q-size = 0为空，q-size = q->capacity为满 。
（2）牺牲一个元素空间。约定，front指向队首元素，rear指向队尾元素的下一个元素，队空时：front=rear 队满时：(rear+1)%maxsize=front
本例程中，为了练习，两种方法均使用。
*/

void CreateQueue(int MaxQueueSize)
{
    if (MaxQueueSize < MinQueueSize)
        printf("Queue size is too small!");

    //给指向队列的指针分配空间
    PQueue q = NULL;
    q = PQueue malloc(LEN);
    if (q == NULL)
        printf("Pointer to queue: memory allocation failure!");

    //初始化队列中的Element。
    q->capacity = MaxQueueSize;  //capcity为该队列最大容量，例：队列从0开始（0，1, 2， 3）容量为4。
    q->front = 0;  //front指向第一个有效节点
    q->rear = 0;  //rear指向最后一个有效节点的下一个节点。  这样的话，插入一个值位于0号位，front指向0号位，rear指向1号位。
                  //rear这种情况下，当rear指向最后一个节点时已不能继续让新节点入队，即会浪费一个节点空间。
    q->size = 0； //size不一定非要设置，但设置size容易识别队列空或者满。
    q->array = int *malloc(sizeof(int) * MaxQueueSize);
    if (q->array == NULL)
        printf("Array of queue: memoory allocation failure!");
    return q;
}

q = CreatQueue(20);  //q既是该队列的名称，又是指向该队列的指针

void MakeEmpty(PQueue q)
{
    q->size = 0;
    q->front = 0;
    q->rear = 0;
}


/*******以下为最简单（非循环）队列的实现********/

//判断是否为空队列
int IsEmptyQueue(PQueue q)
{
    return q->size == 0;  //若不用size，判断队空：q->front == q->rear;
}

//判断是否为满队列
int IsFullQueue(PQueue q)
{
    return q->size == q->capacity - 1;  //若不用size，判断队满： q->rear+1= q->capacity;
}


//从队列头front出队，先检查是否为空。
//若队列不为空，q->size自减1，q->front自增1
void DeQueue(PQueue q)
{
    if (IsEmptyQueue(q))
        printf("This is a empty queue!");
    q->size--;
    q->front++;
}

//从队列尾rear入队，先检查队列是否已满。
//若队列不是满列，q->size自增1，q->rear自增1并将要入队的值x赋值(q->array[++q->rear])
void EnQueue(PQueue q, int x)
{
    if (IsFullQueue(q))
        printf("This is a full queue!");
    q->array[q->rear] = x;  //应注意此处顺序！本例程中rear指向最后一个有效节点的下一个，所以先给rear赋值在将rear自增。
    q->rear++;   //若其他例程中rear指向最后一个有效节点，则q->array[++q->rear] = x;先自增再赋值。
    q->size++;
}

int GetQueueSize(PQueue q)
{
    return q->zise;
}

void ScreenAllEle(PQueue q)
{
    if (IsEmptyQueue(q))
        printf("This is a empty queue!");
    int tmp;
    for(tmp = p->front; tmp < p->rear; tmp++)  //遍历有效节点
        printf("%d\n", q->array[tmp]);
}

/**********以下为循环队列的实现***********/

// 数组实现的普通队列浪费空间，一般用数组实现循环队列。
//“到达队列尾的回滚“是非循环列表和循环列表最主要的区别。

//可通过Cycle函数实现
//实现序列号增加1，且一旦到队列尾，下一步则跳转队列头
//输入q->front/q->rear作为系列号count和队列q，输出自增1后且考虑到尾部跳转的序列号count
int Cycle(int count, PQueue q)
{
    count++;
    if(count == q->capacity)
        count = 0;     //这两行判定是否已到队列尾，若到队列尾则跳转到队列头
    return count;
}

//除了使用Cycle回滚函数，也可以使用 (q->front+1)%q->capacity或者(q->rear+1)%q->capacity。 更加简单


//判断是否为空队列
int IsEmptyQueue(PQueue q)
{
    return q->size == 0;  //若不用size，判断队空：q->front == q->rear;
}

//判断是否为满队列
int IsFullQueue(PQueue q)
{
    return q->size == q->capacity - 1;  //若不用size，判断队满： (q->rear+1)%q->capacity = q->front
}


//从q->rear入队，先检查是否已满。
//若队列不为满，先赋值，再将rear自增1，size自增1
void EnQueue(int x, PQueue q)
{
    if(IsFullQueue(q))
        printf("This queue is full!");
    q->array[q->rear] = x;
    q->size++;
    q->rear = Cycyle(q->rear,q); //(q->rear+1)%q->capacity
}

//从队列头front出队，先检查是否为空。
//若队列不为空，q->size自减1，q->front自增1
void DeQueue(PQueue q)
{
    if (IsEmptyQueue(q))
        printf("This is a empty queue!");
    q->size--;
    q->front = Cycyle(q->front,q); //(q->front+1)%q->capacity
}

int GetQueueSize(PQueue q)
{
    return q->zise;
}


//遍历发音所有节点
void ScreenAllEle(PQueue q)
{
    if (IsEmptyQueue(q))
        printf("This is a empty queue!")

    int tmp;
    for(tmp = p->front; tmp%q->capacity < q->rear; tmp++)  //遍历有效节点
        printf("%d\n", q->array[tmp]);
}
