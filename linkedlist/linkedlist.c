#include <stdio.h>
#include "linkedlist.h"
#define LEN sizeof(struct Node)


/*
单链表学习，关键的几点：
1. 创建节点 struct Node{}； 并用typedef  struct *PNode来将“指向strcut Node{}；的指针”简化为PNode，使代码简洁。
   该结构体内部除了要放置的数据外，最后还有一个指向下一个节点的next指针（属未声明好就使用，与递归一样是C语言中的两种未声明先使用之一）。
   通过malloc来分配节点的空间，返回得到节点的指针。
2. 使用头结点head的情况下，先声明head = NULL，此时为一个只有头节点的空链表。判断链表是否为空，也可以用head->next ==NULL来判断。
3. 遍历整个链表 for(p = head; p != NULL ; p = p->next)。P为指向有效节点的指针，从第一个有效节点的指针向下传递，直到最后一个有效节点。
   得到下一个元素的指针 p->next
4. 本案例中头结点为head，只存放指向第一个有效节点的指针，而不存放数据。
   设计链表时，可以设计头结点放数据（如Weiss书，头结点同时放置数据和指针，跟普通有效节点无异），也可以设计不放。
   区别在于遍历的时候，头结点无数据从head开始，头结点有数据从head->next开始。且头结点有数据会跟有效节点中的数据混淆。一般表头节点不存数据。

掌握以上几点，变得很简单!!!

*/



//创建节点(非头结点),输入参数为节点值int data，后继为NULL，返回指向该节点的指针
//malloc(LEN)分配LEN的内存空间，返回被分配内存的指针。 malloc，若分配失败则返回NULL，分配成功返回通用指针void *类型的指针，一般需做类型转换。
//因为typedef struct Node *link，所以link malloc(LEN)说明其为指向struct Node类型的指针。写法 PNode head = malloc(LEN) 与其效果一样。
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

//以有头结点的链表为例,初始化为NULL表示空链表。
//创建链表，头结点与普通节点不一样，头结点中只存指向第一个有数据节点的指针，不存放数据。只含头结点的空链表head=NULL。
//使用时，如Linklist1  = CreatEmptyList();这样即创建一个空链表，链表名为“Linklist1”，返回该链表的头节点。
PNode CreatEmptyList()
{
    PNode head = NULL;
    return head;
}

head = CreatEmptyList(); //创建链表，并命名为head，返回头结点的指针head。后面的操作中head均指这个链表名。



//判断是否为空链表。空链表只有一个头结点，头结点为NULL。非空链表头结点为指向第一个有效节点的指针。
int IsEmptyLinkedlist(PNode head)
{
    return head == NULL;
}


//搜索节点,输入参数为节点值int data，返回指向该节点的指针
//有个Bug：只能搜出第一个等于data的数（data不能重复）。
//解决方法，可以printf（）打印出来；或者封装成指针数组，返回指针数组（这个指针数组初始化为多大是个问题，小了怕不够，大了浪费空间）。
PNode SearchNodeByData(int data)
{
    PNode p = NULL;
    for(p = head; p != NULL; p = p->next)
        if(p->data == data)
            return p;
}

//查序列号，输入节点指针，返回该节点的序列号（第几个节点）。第一个有效节点序列号为0。
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

//搜索节点,输入参数为节点的序号，返回指向该节点的指针
PNode SearchNodeByCount(int count)
{
    PNode tmp = NULL;
    for(tmp = head; tmp; tmp = tmp->next)
        if(CountNode(tmp) == count)
            return tmp；
}


//搜索前驱节点，输入参数为节点指针，返回指向该节点前一个节点的指针pre。
//检查输入节点是否为第一个有效结点，若是第一个有效节点，提示。
PNode PreNode(PNode p)
{
    if (p == head)
        printf("This is first node, no PreNode!");
    PNode pre = NULL;
    for(pre = head; pre != NULL; pre = pre->next)
        if(pre->next == p)
            return pre;
}

//链表尾部的push操作,输入要PUSH进去的节点的指针，返回push进去的节点的指针
//先检查是否为空链表，若为空(head==NULL;)，则将要push进去的节点的指针赋值给head。若不为空，则遍历找到尾节点tmp,tmp->next=p;p->next=NULL;
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


//链表尾部的pop操作,找到最后节点tmp后删除，并将其前驱节点的next设置为NULL。注意检查是否为空链表。
//先检查是否为空链表，若为空，提示。
//在检查是否为只有一个有效节点的链表(此情况无法找到前驱)，若是，则head == NULL；free
//最后一般情况，找到尾节点，删除。

void pop(void)
{
    if(IsEmptyLinkedlist)
        printf("This linklist is empty");

    //只有一个有效节点的情况
    if(head->next == NULL)
    {
        free(head);
        head = NULL;    //应该先free(head)再head=NULL;若无head=NULL则head成为野指针，引起很多错误，要引以为戒！free之后要置空！（相似的，声明时要置空或赋值！）
        return ;        //若先head=NULL再free(head)则释放的是NULL指针(标准上此语法是对的，NUll指针可反复释放，但什么都不做)，malloc的内存没释放，内存泄露。
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



//修改节点中的数据，输入节点指针和要修改成的data，返回该节点指针。
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


//删除节点,输入参数为要删除的节点指针，返回该链表头指针。
//注意检查要删除的是否为第一个有效结点，若要删除第一个有效节点，则将原第二个有效节点作为新的第一个有效结点。
PNode DeleteNode(PNode p)
{
    if (p == head) //若该为头结点,将头结点的下一个节点作为头结点
    {
        head = p->next;
        free(p);
        p = NULL;
        return head;    //与链表实现栈的push操作一样
    }

    PNode pre = PreNode(p);  //若不是头结点，先找到改节点的前驱PrePtr，进行PrePtr->next = p->next操作
    pre->next = p->next;
    free(p);
    p = NULL;
    return head;
}



//插入节点(在序列号i的节点前插)。
// 输入参数为要插入的节点的位置为第i个位置（该节点需是链表中已存在的节点），以及插入节点的指针，返回指向该插入节点的指针。原该位置的节点后移。
//注意检查是不是要在第一个有效节点之前插入。
PNode InsertNode(int i, PNode p)
{

    if(p == head)
    {
        p-next = head;
        head = p;
        return p;        //与链表实现栈的pop操作一样
    }

    PNode ori = SearchNodeByCount(i);
    PNode pre = PreNode(ori);
    p->next = ori;
    pre->next = p;  // 这两行顺序无所谓
    return p;
}


//待解决，用最常见的三指针法
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

