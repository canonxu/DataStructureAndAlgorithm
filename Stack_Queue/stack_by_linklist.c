#include<stdio.h>
#define LEN sizeof(struct Node)

//�����ڵ㣬ֵΪi��ָ��ΪNULL�����ظýڵ��ָ��Ϊp
PStack MakeNode(int i)
{
    PStack p = NULL;
    p = PStack malloc(LEN);
    if (p == NULL)
        printf("Memory allocation failure");
    p->next = NULL;
    p->data = i;
    return p;


//����һ����ջ,����head��ָ�롣ʹ��ʱ��stack1 = CreatEmptyStack(),�����һ����һ��ͷ�ڵ�head=NULL������ջ����
//stack1Ϊ��ջͷ����ָ�룬�ɱ�ʾ���ջ��
//ջ��Ԫ��top��Ϊͷ����ĵ�һ��Ԫ�أ�
PStack CreatEmptyStack()
{
    PNode head = NULL;
    return head;
}

s = CreatEmptyList(); //����һ����ջ������Ϊs����ջ�ĵ�һ����Ч�ڵ���ָ��ҲΪs��

//����ջ��������ջͷ�ڵ��ָ�룬ͷ���head=NULL����1������Ϊ�շ���0
int IsEmptyStack(PStack s)
{
    return s == NULL;
}

//����MakeNode�����ڵ㷵��صĸýڵ��ָ�롣������ǰ���룬���ڵ�һ����Ч�ڵ�ǰ���룬�½ڵ��ָ�븳ֵ��ͷ��㣨s����

void Push(PStack s,PStack p)
{
    p->next = s;
    s = p;
}

//����ջ����ջͷ���ָ�룩���ȼ���Ƿ�Ϊ�գ���Ϊ�յĻ���ͷ����ĵ�һ���ڵ�ɾ��,s = s->next��
void Pop(PStack s)
{
    if(IsEmpty(s))
        printf("Failure: this stack is empty!");
    PNode top = s;
    s = s->next;
    free(top);
    top = NULL;
}

//����ջ����ջͷ���ָ�룩.ȡ��ջ��Ԫ��top
int GetTopEle(PStack s)
{
    if(IsEmpty(s))
        printf("Failure: this stack is empty!");
    PStack top = s;
    return top->data;
}

//��ӡջ������Ԫ��,��ջ����ӡ��ջ��,�˴�ѭ����Ϊ�����ͷ��β��ѭ��
void ScreenAllEle(PStack s)
{
    if(IsEmpty(s))
        printf("Failure: this stack is empty!");
    PStack tmp = NULL;
    for(tmp = s; tmp != NULL; tmp = tmp->next)
        printf("%d", tmp->data);
}

//��ջ�ÿ�,�Ƚ����ڵ�pop��ȥ���ڴ��ͷţ�ֱ��s = NULL�� ��Ҫ��ջ���٣���free(s)���ɡ�
//��򵥵ķ�����s=NULL;����û���ͷ���Ч�ڵ㣬�˷��ڴ档
void SetEmpty(PStack s)
{
    while(s != NULL)
        pop(s);
}


