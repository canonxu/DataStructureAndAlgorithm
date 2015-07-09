#include<stdio.h>
#define LEN sizeof(struct Stack)
#define EmptyTopCount -1
#define MinStackSize 5

//�����鴴��ջ��һ��ʼ�������MaxSizeָ��ʵ��ջ�������С��������linkedlistʵ��ջ��һ������
//�Կ�ջ��POP�Ͷ���ջ��PUSH����������Խ�硣�����׷�����

//��ʼ��һ��ջ���ֱ��ʼ��ָ���ջ��ָ��͸�ջ���ṹ�壩�е�ջ������ջ���α꣬ջ����
PStack CreatStack(int MaxStackSize)
{
    if (MaxStackSize < MinStackSize)
        printf("Stack size is too small!");
    //��ʼ��ָ��ջ��ָ��
    PStack s = NULL;
    s = PStack malloc(LEN);  //Ϊָ��ջ��ָ�����ռ䡣
    if (s == NULL)
        printf("Memory allocation failure!");

    //��ʼ��ջ�Ĵ�С
    s->capacity = MaxStackSize;

    //��ʼ��ջ���α�
    s->topcount = EmptyTopCount;

    //��ʼ��ջ�е����飬arrayΪָ��������Ԫ�ص�ָ�롣
    s->array = int *malloc(sizeof(int)*MaxStackSize);
    if (s->array == NULL)
        printf("Memory allocation failure!");

    return s;
}


s = CreatStack(20)  //����,sΪջ����ҲΪָ���ջ�ṹ���ָ��


// ����ջ��������ջ�����飬������ջ�ṹ��
void DisposeStack(PStack s)
{
    if(s->topcount != EmptyTopCount)  //�ж��Ƿ�Ϊ��ջ
    {
        free(s->array);
        free(s);
    }
}

//��ջ�ÿգ�ջ���α�topcountΪ-1. �ɴˣ���ջ��һ��Ԫ�أ�ջ��topcountΪ0��
void MakeEmpty(PStack s)
{
    s->topcount = EmptyTopCount;
}

//�ж�ջ�Ƿ�Ϊ��
int IsEmptyStack()
{
    return s->topcount == EmptyTopCount;
}

//�ж�ջ�Ƿ�Ϊ��
int IsFullStack()
{
    return s->topcount == s->capacity-1;
}

//ѹջʱ������ռ�ռ��Ƿ�������
//s->array[++s->topcount] = x; �α�topcount����1��ͬʱ����Ҫѹ���ֵ��ֵ��ջ��
void push(int x, PStack s)
{
    if(s->topcount = MaxStackSize-1) //�ж�ջ�Ƿ�����
        printf("This stack is full!");
    s->array[++s->topcount] = x;
}


//��ջʱ�������Ƿ�Ϊ��ջ
//free(s->array[topcount]); �ͷ�ջ��Ԫ�� s->topcount--;�α�topcount�Լ�1
void pop(PStack s)
{
    if(s->topcount == EmptyTopCount)  //�ж��Ƿ�Ϊ��ջ
        printf("This stack is empty");
    free(s->array[topcount]);
    s->topcount--;
}

//���ջ��Ԫ�أ������ж��Ƿ�Ϊ��ջ
//ջ��Ԫ�� s->array[s->topcount];
int GetTopEle(PStack s)
{
    if (s->topcount == EmptyTopCount)
    {
        printf("This stack is empty");
        return 0;
    }
    return s->array[s->topcount];
}

//ɨ������ջ�������ж��Ƿ�Ϊ��ջ��
//ͨ��s->topcount--�ķ�ʽʵ��ջ�ڵı���
void ScreenAllEle(PStack s)
{
    if(s->topcount == EmptyTopCount)  //�ж��Ƿ�Ϊ��ջ
        printf("This stack is empty");

    for(s->topcount; s->topcount > EmptyTopCount; s->topcount--)
        printf("%d", s->array[s->topcount]);
}

