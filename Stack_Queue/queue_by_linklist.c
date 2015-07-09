#include <stdio.h>
#define LEN sizeof(struct Node)
#define MinQueueSize 5



//创建一个队列，初始化。
//输入创建队列的最大容量，返回指向该队列的指针。
PQueue CreatEmptyQueue(int MaxQueueSize)
{
    //为队列分配内存
    PQueue q = PQueue malloc(sizeof(struct Queue));
    if (PQueue == Null)
        printf("Memory allocation failure!");

    if (MaxQueueSize < MinQueueSize)
        printf("The size is too small!")
    q->capacity = MaxQueueSize;
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q；
}

q = CreateEmptyQueue(20);  //此处q既为该队列名称，又为指向该队列的指针。

//将队列置空
PQueue MakeEmpty(PQueue q)
{
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}


//创建队列的链表节点，与创建普通链表的节点无异。
//输入数据data，返回指向该节点的指针。
PNode MakeNode(int data)
{
    PNode p = PNode malloc(LEN);
    if (p == NULL)
        printf("Memory allocation failure!")

    p->data = data;
    p->next = NULL;
}



//判断队列是否为空
int IsEmptyQueue()
{
    return q->size == 0;
}

//判断队列是否为满
int IsFullQueue()
{
    return q-size == q-capacity;
}


/**********最普通队列**********/

//出队，先判定此队列是否为空。
//若不为空，则在front游标往后一位。
void DeQueue (PQueue q)
{
    if (IsEmptyQueue(q))
        printf("This queue is empty!");

    PNode tmp = q->front;
    q->front = q->front->next;
    free(tmp);
    tmp = NULL;

    p->size--;

}

//入队，先判定此队列是否为满。
//若不为满，再判定是否为空（即将要入队的为第一个有效节点），若是则q->rear = newnode;q->front = newnode;
//最后，rear往后移一位并赋值。（此例程中，rear指针指向最后一个有效节点，区别于queue_by_array中rear指向最后一个有效节点的下一位）
void EnQueue(PQueue q, int data)
{
    if (IsFullQueue(q))
    {
        printf("This queue is full!");
        return ;
    }
    //创建要入队的节点，得到其指针newnode
    PNode newnode = MakeNode(data);

    //如果队列为空，即将插入的为第一个有效节点，直接置q-rear = newnode;q->front = newnode;
    if (IsEmptyQueue(q))
    {
        q->rear = newnode;
        q->front = newnode;
        newnode->next = NULL;
        q->size++;
        return ;
    }

    //如果队列不为空，将新节点连接到原rear节点上，且置q->rear = newnode。
    q->rear->next = newnode;
    q->rear = newnode;
    q->size++;
}


void ScreenAllEle(PQueue p)
{
    if (IsFullQueue(q))
        printf("This queue is full!");

    PNode tmp = NULL;
    for (tmp = p->front; tmp != NULL; tmp = tmp-next)  //遍历链表
        printf("%d\n", tmp->data);

}

/**********循环队列***********/
//链表实现的队列，出队一个节点就free掉，相比数组实现的队列不存在浪费内存，所以无所谓循环。

