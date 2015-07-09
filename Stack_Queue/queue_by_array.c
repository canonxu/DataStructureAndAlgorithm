#include<stdio.h>
#define LEN sizrof(struct Queue)
#define MinQueueSize 5;
/*
Լ������ʼ�����ն�ʱ����front=rear=0,���ӿ�ʱ��front=rear ������ʱ��front=rear �����.���ֻƾ��ʽfront=rear�޷��ж϶ӿջ��Ƕ�����
�����ַ��������������⣺
��1������һ����־λ����������ǿջ�������frontָ���һ����Ч�ڵ㣬rearָ�����һ����Ч�ڵ㣬��q-size��¼ʵ�ʴ�Сq-size = 0Ϊ�գ�q-size = q->capacityΪ�� ��
��2������һ��Ԫ�ؿռ䡣Լ����frontָ�����Ԫ�أ�rearָ���βԪ�ص���һ��Ԫ�أ��ӿ�ʱ��front=rear ����ʱ��(rear+1)%maxsize=front
�������У�Ϊ����ϰ�����ַ�����ʹ�á�
*/

void CreateQueue(int MaxQueueSize)
{
    if (MaxQueueSize < MinQueueSize)
        printf("Queue size is too small!");

    //��ָ����е�ָ�����ռ�
    PQueue q = NULL;
    q = PQueue malloc(LEN);
    if (q == NULL)
        printf("Pointer to queue: memory allocation failure!");

    //��ʼ�������е�Element��
    q->capacity = MaxQueueSize;  //capcityΪ�ö�������������������д�0��ʼ��0��1, 2�� 3������Ϊ4��
    q->front = 0;  //frontָ���һ����Ч�ڵ�
    q->rear = 0;  //rearָ�����һ����Ч�ڵ����һ���ڵ㡣  �����Ļ�������һ��ֵλ��0��λ��frontָ��0��λ��rearָ��1��λ��
                  //rear��������£���rearָ�����һ���ڵ�ʱ�Ѳ��ܼ������½ڵ���ӣ������˷�һ���ڵ�ռ䡣
    q->size = 0�� //size��һ����Ҫ���ã�������size����ʶ����пջ�������
    q->array = int *malloc(sizeof(int) * MaxQueueSize);
    if (q->array == NULL)
        printf("Array of queue: memoory allocation failure!");
    return q;
}

q = CreatQueue(20);  //q���Ǹö��е����ƣ�����ָ��ö��е�ָ��

void MakeEmpty(PQueue q)
{
    q->size = 0;
    q->front = 0;
    q->rear = 0;
}


/*******����Ϊ��򵥣���ѭ�������е�ʵ��********/

//�ж��Ƿ�Ϊ�ն���
int IsEmptyQueue(PQueue q)
{
    return q->size == 0;  //������size���ж϶ӿգ�q->front == q->rear;
}

//�ж��Ƿ�Ϊ������
int IsFullQueue(PQueue q)
{
    return q->size == q->capacity - 1;  //������size���ж϶����� q->rear+1= q->capacity;
}


//�Ӷ���ͷfront���ӣ��ȼ���Ƿ�Ϊ�ա�
//�����в�Ϊ�գ�q->size�Լ�1��q->front����1
void DeQueue(PQueue q)
{
    if (IsEmptyQueue(q))
        printf("This is a empty queue!");
    q->size--;
    q->front++;
}

//�Ӷ���βrear��ӣ��ȼ������Ƿ�������
//�����в������У�q->size����1��q->rear����1����Ҫ��ӵ�ֵx��ֵ(q->array[++q->rear])
void EnQueue(PQueue q, int x)
{
    if (IsFullQueue(q))
        printf("This is a full queue!");
    q->array[q->rear] = x;  //Ӧע��˴�˳�򣡱�������rearָ�����һ����Ч�ڵ����һ���������ȸ�rear��ֵ�ڽ�rear������
    q->rear++;   //������������rearָ�����һ����Ч�ڵ㣬��q->array[++q->rear] = x;�������ٸ�ֵ��
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
    for(tmp = p->front; tmp < p->rear; tmp++)  //������Ч�ڵ�
        printf("%d\n", q->array[tmp]);
}

/**********����Ϊѭ�����е�ʵ��***********/

// ����ʵ�ֵ���ͨ�����˷ѿռ䣬һ��������ʵ��ѭ�����С�
//���������β�Ļع����Ƿ�ѭ���б��ѭ���б�����Ҫ������

//��ͨ��Cycle����ʵ��
//ʵ�����к�����1����һ��������β����һ������ת����ͷ
//����q->front/q->rear��Ϊϵ�к�count�Ͷ���q���������1���ҿ��ǵ�β����ת�����к�count
int Cycle(int count, PQueue q)
{
    count++;
    if(count == q->capacity)
        count = 0;     //�������ж��Ƿ��ѵ�����β����������β����ת������ͷ
    return count;
}

//����ʹ��Cycle�ع�������Ҳ����ʹ�� (q->front+1)%q->capacity����(q->rear+1)%q->capacity�� ���Ӽ�


//�ж��Ƿ�Ϊ�ն���
int IsEmptyQueue(PQueue q)
{
    return q->size == 0;  //������size���ж϶ӿգ�q->front == q->rear;
}

//�ж��Ƿ�Ϊ������
int IsFullQueue(PQueue q)
{
    return q->size == q->capacity - 1;  //������size���ж϶����� (q->rear+1)%q->capacity = q->front
}


//��q->rear��ӣ��ȼ���Ƿ�������
//�����в�Ϊ�����ȸ�ֵ���ٽ�rear����1��size����1
void EnQueue(int x, PQueue q)
{
    if(IsFullQueue(q))
        printf("This queue is full!");
    q->array[q->rear] = x;
    q->size++;
    q->rear = Cycyle(q->rear,q); //(q->rear+1)%q->capacity
}

//�Ӷ���ͷfront���ӣ��ȼ���Ƿ�Ϊ�ա�
//�����в�Ϊ�գ�q->size�Լ�1��q->front����1
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


//�����������нڵ�
void ScreenAllEle(PQueue q)
{
    if (IsEmptyQueue(q))
        printf("This is a empty queue!")

    int tmp;
    for(tmp = p->front; tmp%q->capacity < q->rear; tmp++)  //������Ч�ڵ�
        printf("%d\n", q->array[tmp]);
}
