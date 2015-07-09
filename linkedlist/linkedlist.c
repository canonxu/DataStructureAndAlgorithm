#include <stdio.h>
#include "linkedlist.h"
#define LEN sizeof(struct Node)


/*
������ѧϰ���ؼ��ļ��㣺
1. �����ڵ� struct Node{}�� ����typedef  struct *PNode������ָ��strcut Node{}����ָ�롱��ΪPNode��ʹ�����ࡣ
   �ýṹ���ڲ�����Ҫ���õ������⣬�����һ��ָ����һ���ڵ��nextָ�루��δ�����þ�ʹ�ã���ݹ�һ����C�����е�����δ������ʹ��֮һ����
   ͨ��malloc������ڵ�Ŀռ䣬���صõ��ڵ��ָ�롣
2. ʹ��ͷ���head������£�������head = NULL����ʱΪһ��ֻ��ͷ�ڵ�Ŀ������ж������Ƿ�Ϊ�գ�Ҳ������head->next ==NULL���жϡ�
3. ������������ for(p = head; p != NULL ; p = p->next)��PΪָ����Ч�ڵ��ָ�룬�ӵ�һ����Ч�ڵ��ָ�����´��ݣ�ֱ�����һ����Ч�ڵ㡣
   �õ���һ��Ԫ�ص�ָ�� p->next
4. ��������ͷ���Ϊhead��ֻ���ָ���һ����Ч�ڵ��ָ�룬����������ݡ�
   �������ʱ���������ͷ�������ݣ���Weiss�飬ͷ���ͬʱ�������ݺ�ָ�룬����ͨ��Ч�ڵ����죩��Ҳ������Ʋ��š�
   �������ڱ�����ʱ��ͷ��������ݴ�head��ʼ��ͷ��������ݴ�head->next��ʼ����ͷ��������ݻ����Ч�ڵ��е����ݻ�����һ���ͷ�ڵ㲻�����ݡ�

�������ϼ��㣬��úܼ�!!!

*/



//�����ڵ�(��ͷ���),�������Ϊ�ڵ�ֵint data�����ΪNULL������ָ��ýڵ��ָ��
//malloc(LEN)����LEN���ڴ�ռ䣬���ر������ڴ��ָ�롣 malloc��������ʧ���򷵻�NULL������ɹ�����ͨ��ָ��void *���͵�ָ�룬һ����������ת����
//��Ϊtypedef struct Node *link������link malloc(LEN)˵����Ϊָ��struct Node���͵�ָ�롣д�� PNode head = malloc(LEN) ����Ч��һ����
PNode MakeNode(int data)
{
    PNode p = Null;
    p = PNode malloc(LEN);
    if (p == NULL)
        printf("Memory allocation failure");
    p->data = data;
    p->next = NULL;
    return p;
}

//����ͷ��������Ϊ��,��ʼ��ΪNULL��ʾ������
//��������ͷ�������ͨ�ڵ㲻һ����ͷ�����ֻ��ָ���һ�������ݽڵ��ָ�룬��������ݡ�ֻ��ͷ���Ŀ�����head=NULL��
//ʹ��ʱ����Linklist1  = CreatEmptyList();����������һ��������������Ϊ��Linklist1�������ظ������ͷ�ڵ㡣
PNode CreatEmptyList()
{
    PNode head = NULL;
    return head;
}

head = CreatEmptyList(); //��������������Ϊhead������ͷ����ָ��head������Ĳ�����head��ָ�����������



//�ж��Ƿ�Ϊ������������ֻ��һ��ͷ��㣬ͷ���ΪNULL���ǿ�����ͷ���Ϊָ���һ����Ч�ڵ��ָ�롣
int IsEmptyLinkedlist(PNode head)
{
    return head == NULL;
}


//�����ڵ�,�������Ϊ�ڵ�ֵint data������ָ��ýڵ��ָ��
//�и�Bug��ֻ���ѳ���һ������data������data�����ظ�����
//�������������printf������ӡ���������߷�װ��ָ�����飬����ָ�����飨���ָ�������ʼ��Ϊ����Ǹ����⣬С���²����������˷ѿռ䣩��
PNode SearchNodeByData(int data)
{
    PNode p = NULL;
    for(p = head; p != NULL; p = p->next)
        if(p->data == data)
            return p;
}

//�����кţ�����ڵ�ָ�룬���ظýڵ�����кţ��ڼ����ڵ㣩����һ����Ч�ڵ����к�Ϊ0��
int CountNode(PNode p)
{
    PNode tmp = NULL;
    int i = 0;
    for(tmp = head; tmp != NULL; tmp = tmp->next)
    {
        if(tmp == p)
            break;
        i++;
    }
    return i;
}

//�����ڵ�,�������Ϊ�ڵ����ţ�����ָ��ýڵ��ָ��
PNode SearchNodeByCount(int count)
{
    PNode tmp = NULL;
    for(tmp = head; tmp; tmp = tmp->next)
        if(CountNode(tmp) == count)
            return tmp��
}


//����ǰ���ڵ㣬�������Ϊ�ڵ�ָ�룬����ָ��ýڵ�ǰһ���ڵ��ָ��pre��
//�������ڵ��Ƿ�Ϊ��һ����Ч��㣬���ǵ�һ����Ч�ڵ㣬��ʾ��
PNode PreNode(PNode p)
{
    if (p == head)
        printf("This is first node, no PreNode!");
    PNode pre = NULL;
    for(pre = head; pre != NULL; pre = pre->next)
        if(pre->next == p)
            return pre;
}

//����β����push����,����ҪPUSH��ȥ�Ľڵ��ָ�룬����push��ȥ�Ľڵ��ָ��
//�ȼ���Ƿ�Ϊ��������Ϊ��(head==NULL;)����Ҫpush��ȥ�Ľڵ��ָ�븳ֵ��head������Ϊ�գ�������ҵ�β�ڵ�tmp,tmp->next=p;p->next=NULL;
PNode push(PNode p)
{
    if (IsEmptyLinkedlist)
    {
        head = p;
        return p;
    }

    PNode tmp = NULL;
    for(tmp = head; tmp != NULL; tmp = tmp->next)
        if(tmp->next == NULL)
        {
            tmp->next = p;
            p->next = NULL;
            return p;
        }
}


//����β����pop����,�ҵ����ڵ�tmp��ɾ����������ǰ���ڵ��next����ΪNULL��ע�����Ƿ�Ϊ������
//�ȼ���Ƿ�Ϊ��������Ϊ�գ���ʾ��
//�ڼ���Ƿ�Ϊֻ��һ����Ч�ڵ������(������޷��ҵ�ǰ��)�����ǣ���head == NULL��free
//���һ��������ҵ�β�ڵ㣬ɾ����

void pop(void)
{
    if(IsEmptyLinkedlist)
        printf("This linklist is empty");

    //ֻ��һ����Ч�ڵ�����
    if(head->next == NULL)
    {
        free(head);
        head = NULL;    //Ӧ����free(head)��head=NULL;����head=NULL��head��ΪҰָ�룬����ܶ����Ҫ����Ϊ�䣡free֮��Ҫ�ÿգ������Ƶģ�����ʱҪ�ÿջ�ֵ����
        return ;        //����head=NULL��free(head)���ͷŵ���NULLָ��(��׼�ϴ��﷨�ǶԵģ�NUllָ��ɷ����ͷţ���ʲô������)��malloc���ڴ�û�ͷţ��ڴ�й¶��
    }

    PNode tmp = NULL;
    for(tmp = head; tmp; tmp = tmp->next)
        if(tmp->next == NULL)
        {
            pre = PreNode(tmp);
            pre->next = NULL;
            free(tmp);
            tmp = NULL;
        }

}



//�޸Ľڵ��е����ݣ�����ڵ�ָ���Ҫ�޸ĳɵ�data�����ظýڵ�ָ�롣
PNode ModifyNode(PNode p, int data)
{
    PNode tmp = NULL;
    for(tmp = head; tmp != NULL; tmp = tmp->next)
    {
        if(tmp == p)
            tmp->data = data;
        return tmp;
    }
}


//ɾ���ڵ�,�������ΪҪɾ���Ľڵ�ָ�룬���ظ�����ͷָ�롣
//ע����Ҫɾ�����Ƿ�Ϊ��һ����Ч��㣬��Ҫɾ����һ����Ч�ڵ㣬��ԭ�ڶ�����Ч�ڵ���Ϊ�µĵ�һ����Ч��㡣
PNode DeleteNode(PNode p)
{
    if (p == head) //����Ϊͷ���,��ͷ������һ���ڵ���Ϊͷ���
    {
        head = p->next;
        free(p);
        p = NULL;
        return head;    //������ʵ��ջ��push����һ��
    }

    PNode pre = PreNode(p);  //������ͷ��㣬���ҵ��Ľڵ��ǰ��PrePtr������PrePtr->next = p->next����
    pre->next = p->next;
    free(p);
    p = NULL;
    return head;
}



//����ڵ�(�����к�i�Ľڵ�ǰ��)��
// �������ΪҪ����Ľڵ��λ��Ϊ��i��λ�ã��ýڵ������������Ѵ��ڵĽڵ㣩���Լ�����ڵ��ָ�룬����ָ��ò���ڵ��ָ�롣ԭ��λ�õĽڵ���ơ�
//ע�����ǲ���Ҫ�ڵ�һ����Ч�ڵ�֮ǰ���롣
PNode InsertNode(int i, PNode p)
{

    if(p == head)
    {
        p-next = head;
        head = p;
        return p;        //������ʵ��ջ��pop����һ��
    }

    PNode ori = SearchNodeByCount(i);
    PNode pre = PreNode(ori);
    p->next = ori;
    pre->next = p;  // ������˳������ν
    return p;
}


//����������������ָ�뷨
PNode ReverseLinkedlist(PNode head)
{
    if (head == NULL || head->next == NULL)
        return head;

    PNode CurrentNode = NULL;
    for (CurrentNode = head->next; CurrentNode != NULL; CurrentNode = CurrentNode->next)
    {
        PNode NextNode = CurrentNode->next;
        head->


    }

}

