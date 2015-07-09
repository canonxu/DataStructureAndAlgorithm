#include <stdio.h>
#define LEN sizeof(struct Node)
#define MinQueueSize 5



//����һ�����У���ʼ����
//���봴�����е��������������ָ��ö��е�ָ�롣
PQueue CreatEmptyQueue(int MaxQueueSize)
{
    //Ϊ���з����ڴ�
    PQueue q = PQueue malloc(sizeof(struct Queue));
    if (PQueue == Null)
        printf("Memory allocation failure!");

    if (MaxQueueSize < MinQueueSize)
        printf("The size is too small!")
    q->capacity = MaxQueueSize;
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q��
}

q = CreateEmptyQueue(20);  //�˴�q��Ϊ�ö������ƣ���Ϊָ��ö��е�ָ�롣

//�������ÿ�
PQueue MakeEmpty(PQueue q)
{
    q->front = NULL;
    q->rear = NULL;
    q->size = 0;
    return q;
}


//�������е�����ڵ㣬�봴����ͨ����Ľڵ����졣
//��������data������ָ��ýڵ��ָ�롣
PNode MakeNode(int data)
{
    PNode p = PNode malloc(LEN);
    if (p == NULL)
        printf("Memory allocation failure!")

    p->data = data;
    p->next = NULL;
}



//�ж϶����Ƿ�Ϊ��
int IsEmptyQueue()
{
    return q->size == 0;
}

//�ж϶����Ƿ�Ϊ��
int IsFullQueue()
{
    return q-size == q-capacity;
}


/**********����ͨ����**********/

//���ӣ����ж��˶����Ƿ�Ϊ�ա�
//����Ϊ�գ�����front�α�����һλ��
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

//��ӣ����ж��˶����Ƿ�Ϊ����
//����Ϊ�������ж��Ƿ�Ϊ�գ�����Ҫ��ӵ�Ϊ��һ����Ч�ڵ㣩��������q->rear = newnode;q->front = newnode;
//���rear������һλ����ֵ�����������У�rearָ��ָ�����һ����Ч�ڵ㣬������queue_by_array��rearָ�����һ����Ч�ڵ����һλ��
void EnQueue(PQueue q, int data)
{
    if (IsFullQueue(q))
    {
        printf("This queue is full!");
        return ;
    }
    //����Ҫ��ӵĽڵ㣬�õ���ָ��newnode
    PNode newnode = MakeNode(data);

    //�������Ϊ�գ����������Ϊ��һ����Ч�ڵ㣬ֱ����q-rear = newnode;q->front = newnode;
    if (IsEmptyQueue(q))
    {
        q->rear = newnode;
        q->front = newnode;
        newnode->next = NULL;
        q->size++;
        return ;
    }

    //������в�Ϊ�գ����½ڵ����ӵ�ԭrear�ڵ��ϣ�����q->rear = newnode��
    q->rear->next = newnode;
    q->rear = newnode;
    q->size++;
}


void ScreenAllEle(PQueue p)
{
    if (IsFullQueue(q))
        printf("This queue is full!");

    PNode tmp = NULL;
    for (tmp = p->front; tmp != NULL; tmp = tmp-next)  //��������
        printf("%d\n", tmp->data);

}

/**********ѭ������***********/
//����ʵ�ֵĶ��У�����һ���ڵ��free�����������ʵ�ֵĶ��в������˷��ڴ棬��������νѭ����

