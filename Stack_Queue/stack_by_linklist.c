#include<stdio.h>
#define LEN sizeof(struct Node)

//创建节点，值为i，指针为NULL，返回该节点的指针为p
PStack MakeNode(int i)
{
    PStack p = NULL;
    p = PStack malloc(LEN);
    if (p == NULL)
        printf("Memory allocation failure");
    p->next = NULL;
    p->data = i;
    return p;


//创建一个空栈,返回head的指针。使用时：stack1 = CreatEmptyStack(),即获得一个含一个头节点head=NULL的链表（栈）。
//stack1为该栈头结点的指针，可表示这个栈！
//栈顶元素top即为头结点后的第一行元素！
PStack CreatEmptyStack()
{
    PNode head = NULL;
    return head;
}

s = CreatEmptyList(); //创建一个空栈，名称为s，该栈的第一个有效节点结点指针也为s。

//输入栈名，即该栈头节点的指针，头结点head=NULL返回1，若不为空返回0
int IsEmptyStack(PStack s)
{
    return s == NULL;
}

//输入MakeNode创建节点返后回的该节点的指针。在链表前插入，即在第一个有效节点前插入，新节点的指针赋值给头结点（s）。

void Push(PStack s,PStack p)
{
    p->next = s;
    s = p;
}

//输入栈名（栈头结点指针），先检查是否为空，不为空的话将头结点后的第一个节点删除,s = s->next。
void Pop(PStack s)
{
    if(IsEmpty(s))
        printf("Failure: this stack is empty!");
    PNode top = s;
    s = s->next;
    free(top);
    top = NULL;
}

//输入栈名（栈头结点指针）.取得栈顶元素top
int GetTopEle(PStack s)
{
    if(IsEmpty(s))
        printf("Failure: this stack is empty!");
    PStack top = s;
    return top->data;
}

//打印栈内所有元素,从栈顶打印到栈底,此处循环即为链表从头到尾的循环
void ScreenAllEle(PStack s)
{
    if(IsEmpty(s))
        printf("Failure: this stack is empty!");
    PStack tmp = NULL;
    for(tmp = s; tmp != NULL; tmp = tmp->next)
        printf("%d", tmp->data);
}

//把栈置空,先将各节点pop出去，内存释放，直到s = NULL。 若要将栈销毁，再free(s)即可。
//最简单的方法是s=NULL;但是没有释放有效节点，浪费内存。
void SetEmpty(PStack s)
{
    while(s != NULL)
        pop(s);
}


