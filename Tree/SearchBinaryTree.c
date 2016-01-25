#include <stdio.h>
#define LEN sizeof(struct Node)


//新建节点：先创建该节点的指针p，再给结构体内元素赋值。
PNode MakeNode(int data)
{
    PNode p = (PNode)malloc(LEN);
    if(P == NULL)
        printf("Memory allocation failure!");

    p->data = data;
//    p->parent = NULL;  //parent可设置也可不设置，设置的话就是双向，节点变化时要双向变化
    p->lchild = NUll;
    p->rchild = NULL;
}


//建立一颗空树（类似于空链表），头指针T指向根节点，同时头指针T也代表该树名称。
PTree CreatEmptyTree()
{
    PTree T = NULL;
    return T;
}

// 建立一个空树，名称为T，根节点为NULL（空树）。
PTree T = CrearEmptyTree();

//将树置空，递归的方法
PTree MakeEmpty(PTree T)
{
    if(T !== NULL)
    {
        MakeEmpty(T->lchild);
        MakeEmpty(T->rchild);
        free(T);
    }
    return NULL;
}

//判断树是否为空，T==NULL；
int IsEmptyTree(PTree T)
{
    return T = NULL;
}

//查找操作,输入树名称和要查找的值，输出查找值所在节点的指针
//递归方法
PNode Search(PTree T, int data)
{
    if(T == NULL)
        return NULL;

    if(data == T->data)  //作为base case，下面两个控制语句左右游走
        return T;
    else if(data < T->data)
        return Search(T->lchild, data);
    else if(data > T->data)
        return Search(T->rchild, data);
}

//迭代方法
PNode Search(PTree T, int data)
{
    if(T == NULL)
        return NULL;

    while(T)
    {
        if(data == T->data)  //符合此控制条件，得到输出
            return T;
        else if(data < T->data)//以下两个控制语句，实现左右游走寻找
            T = T->lchild;
        else if(data > T->data)
            T = T->rchild;
    }

}


//寻找已存在节点的父节点
PNode SearchFather(PTree T, int data)
{
    if(T == NULL || (T->lchild == NULL && T->rchild == NULL)) //T为空树或者T只有一个节点为根节点(根节点是没有父节点的)
    {
        printf("This tree is empty / only one root node!");
        return NULL;
    }

    while(T)
    {
        if( T->rchild == data || T->lchild ==data )  //终点条件
            return T;
        else if(data < T->data)//以下两个控制语句，实现左右游走寻找
            T = T->lchild;
        else if(data > T->data)
            T = T->rchild;
    }
}

//查找做最大值,返回最大值的节点指针
//查找最小值类似，rchild改成lchild即可。

//非遍历方法-一直往右找
PNode SearchMax(PTree T)
{
    if(T == NULL)
        return NULL;
//以下两种写法等价
    while(T->rchild != NULL)  //一直往右找，直到不满足while条件即T->rchild==NULL；
        T = T->rchild;
    return T;
/*
    while(T)
    {
        if(T->rchild == NULL)  //终点条件
            return T;
        else
            T = T->rchild;  //一直往右走
    }
*/
}

//trick:递归用if（）搭配return ;一步步往下走。循环使用while（）搭配控制语句（赋值等）；一步步往下走。

//遍历方法-往右节点递归
PNode SearchMax(PTree T)
{
    if(T == NULL)
        return NULL;

    if(T->rchil!= NULL)   //往右遍历
        return SearchMax(T->rchild);

    return T;        //else即T->echild == NULL;

}


//插入操作，输入数名称和要插入节点的指针，返回指向新插入节点的指针的父指针。前提是该插入值不能等于原树中的值。
//一定是在只有一个儿子/没有儿子的节点上插入，找到要插入的节点后，新建节点比韩国判断插在左子树还是右子树即可。
PNode Insert(PTree T,int data)
{
    //若为空，则插入的节点为第一个节点，头指针指向这第一个节点。
    //有两种可能。一种可能是该树确实为空，新插入为第一个节点
    //另一种可能是，经过下面两个if后，找到应该插入的位置，Insert(T->lchild, data)/Insert(T->rchild, data)传入的T->lchild/T->rchild也为空，此时作为递归的base case。
    if(T == NULL)
    {
        PNode newnode = MakeNode(data);    //头指针指向该节点  // 若有父节点则添加 p->parent = T; 新插入指针的parent指向头指针
        T = newnode;
    }

    //若插入的元素值小于根节点值，则将元素插入到左子树中。若插入的元素值不小于根节点值，则将元素插入到右子树中。
    //递归语句Insert(T->lchild/T->rchild, data)中T->lchild/T->rchild不断左右游走，直到应该插入的位置T,T中T->rchild/T->lchild==NULL，
    // 进入if（T == NULL）中新建节点返回该节点指针，赋值给rchild/lchild进行插入。
    if(data < T->data)
        T->lchild =  Insert(T->lchild, data)
    else if(data > T->data)
        T->rchild =  Insert(T->rchild, data)

    retuen T;  // T->lchild/rchild为Insert()返回的新建节点指针，所以此返回到的T为新插入节点的指针的父指针
}


//迭代的方法找到要插入的新节点的父节点，并插入
PNode Insert(PTree T, int data)
{
    PNode newnode = MakeNode(data);

    //如果树为空，树头指针指向该节点，返回该节点指针
    if(T == NULL)
        return T = newnode;

    //寻找到新节点该连接到的父节点aimnode，并链接上去，返回新节点指针
    PNdde aimnode = SearchToInsert(T, data);
    if(data < aimnode->data)
        aimnode->lchild = newnode;
    else
        aimnode->rchild = newnode;
    return newnode
}

//找到新节点的父节点，使得新节点链接在后面。(前提是该节点不存在该书中)
PNode SearchToInsert(PTree T, int data)
{
    if(T == NULL)  //如果链表为空，返回NULL； 在Insert中并未用到，因为Insert时2已结先做了树为空的判断和操作。
    {
        printf("This tree is empty!");
        return NULL;
    }

    while(T)
    {
        //如果寻找到的节点满足如下两个条件之一（左（右）子树为空且要插入的值data小于（大于）该节点的值），则将新节点插在该节点上
        //与Search的区别主要在这个base case上！后面两个if只是在左右的走，
        if( (data < T->data && T->lchild == NULL) || (data > T->data && T->rchild == NULL) )
            return T;
        else if(data < T->data)
            T = T->lchild;
        else if(data > T->data)
            T = T->rchild;
    }

}



//删除操作
//前提是该树中存在data这个值,返回根节点
void Delete(PTree T, int data)
{
    PNode aim = Search(T, data);  //aim为即将删除的节点的指针

/*
    二叉搜索树删除节点较为复杂，分为三种情况。
    1.aim节点为叶子（没有儿子），直接删除即可（包含在第二种情况内）
    2.aim节点只有一个儿子，用aim节点仅有的儿子替代aim节点即可
    3.aim节点有两个儿子，用aim左子树最大值/右子树最小值代替aim中的值，并删除aim左子树最大值/右子树最小值的节点
*/
    //aim为单支节点或叶子，即只有一个儿子或者0个儿子
     PNode Tmp = aim;
    //只存在左叶子
     if(aim->rchild == NULL)
     {
        aim = aim->lchild;
    }
    //只存在右叶子
     if(aim->lchild == NULL)
     {
        aim = aim->lchild;
     }

     free(Tmp);

    //aim左右节点都存在,首先找到左子树的最大值(右子树的最小值)作为替代。
    //用lchildmax（rchildmin）的值替代在即将删除的节点值，并删除lchildmax（rchildmin）节点（都只有一个儿子）。
    //本案例以左节点最大值为例
    else
    {
        PNode lchildmax = SearchMax(aim->lchild);  //找到aim左子树的最大值的指针lchildmax，该lchildmax一定没有右孩子了。
        aim->data = lchildmax->data;  //用rchildmax的值代替aim的值 。
        aim->lchild = Delete(PTree aim->lchild, lchildmax->data); //删除rchildmax这个节点。 只可能有一个左孩子或者没有孩子。递归调用本函数即可
    }

    return T;
}


/*一下为三种遍历方式*/
//例：根节点A，左儿子B，右儿子C
//先序遍历:根节点-》左儿子右儿子 A-B-C
//中序遍历：左儿子-》根节点-》右儿子 B-A-C
//后序遍历：左儿子-》右儿子-》根节点 B-C-A

//创建visit对遍历到的T->data进行处理，如打印、存入数组等。

//递归法
//先序遍历，先对根节点进行处理
int preorder_traversal(PNode T)
{
    if(T == NULL)
        retrn 0;

    visit(T->data);
    Preorder_traversal(T->lchild);
    Preorder_traversal(T->rchild);
    return 0;
}
//中序遍历，中间对根节点进行处理。对于二叉搜索树，中序遍历输出正好是排好序的，最常用，最有用！
int inorder_traversal(PNode T)
{
  if(T == NULL)
        retrn 0;

    Preorder_traversal(T->lchild);
    visit(T->data);
    Preorder_traversal(T->rchild);
    return 0;

}
//后序遍历，后对根节点进行处理
int postorder_traversal(PNode T)
{
    if(T == NULL)
        retrn 0;

    Preorder_traversal(T->lchild);
    Preorder_traversal(T->rchild);
    visit(T->data);
    return 0;
}

//非递归法，以中序遍历为例
/*根据中序遍历的顺序，对于任一结点，优先访问其左孩子，一直遇到左孩子结点为空的结点才进行处理，然后按相同的规则访问其右子树。因此其处理过程如下：

   对于任一结点P，

  1)若其左孩子不为空，则将P入栈并将P的左孩子置为当前的P，然后对当前结点P再进行相同的处理；

  2)若其左孩子为空，则取栈顶元素并进行出栈操作，访问该栈顶结点，然后将当前的P置为栈顶结点的右孩子；

  3)直到P为NULL并且栈为空则遍历结束
*/

//前序遍历，非递归
int preorder_traversal(PNode T)
{
    stack s;
    while(T != NULL || !stack.empty(s))
    {
        while(T != NULL)
        {
            Visit(T->data);
            stack.push(s, T->rchild); //左子树全部处理，且将相应的右子树入栈
            T = T->lchild;
        }

        if(!stack.empty(s))  //极端情况下全部左子树，则结束。一般情况下，所有最左子树有右子树，这些右子树都已入栈。下对这些右子树进行操作。
        {
           T = stack.top(s);
           Visit(T->data);
           stack.pop(s, T); //找到右子树，处理后出栈
           T = T->lchild;   //处理完该右子树后，再将该右子树的左子树带入循环
        }
    }
    return 0;
}

//中序遍历，非递归。 区别：1.while(T != NULL)时前序先将所有最左子树处理且不入栈，但将所有最左左子树的右子树全部入栈。中序将所有最左左子树入栈且不处理。
//                         2.if(!stack.empty(s))时前序依次将栈内的右子树访问，出栈（对这些右子树的子辈用T = T->lchild处理）
//                                                中序依次将站内的最左子树访问，出栈（对这些最左子树，每处理完一个应T = T->lchild来处理其右子树）

int inorder_traversal(PNode T)
{
    stack s;
    while(T != NULL || !stack.empty(s)) //当T为非空，且栈内仍有元素时，进行处理。直到T=NULL且栈内无元素时，结束。
    {
        while(T != NULL)
        {
            stack.push(s, T); //若节点左子树不为空，则将此节点压进栈中，暂不处理。即将左子树全部入栈，但不处理。  --stack.pop()函数为压栈函数
            T = T->lchild;
        }

        //一直到节点左子树为空，以上循环结束，进行节点处理
        if(!stack.empty(s))
        {
            T = stack.top(s);  //获取栈顶元素，即以上循环得到的左子树为空的节点 --stack.pop()函数为取得栈顶元素指针的函数
            visit(T->data);  //对该节点进行处理
            stack.pop(s, T);  //将处理过的节点出栈

            T = T->rchild;  //若原T有右子树则必符合while(T != NULL || !stack.empty(s))中T != NULL继续对该节点的右子树进行处理。
                        //若原T没有右子树则此时T=NULL但栈不为空，则直接跳到 if(!stack.empty(s))对栈内元素进行处理。
        }
    }
    return 0;
}

//后序遍历，非递归。前序和中序类似，都可以从最左左子树着手，而后序比较复杂。

//双栈法实现非递归的后序遍历，优美!
int postorder_traversal(PNode T)
{
    stack s, output; //用于控制的栈s和存放输出元素的栈output
    stack.push(s, T);//先将T压入ls栈
    PNode tmp;
    while(T)
    {
        while(!stack.empty(s))
        {
            tmp = stack.top(s);
            stack.pop(s);
            stack.push(output, tmp);  //依次将s中的栈顶元素压入到output这个栈中保存
            if(tmp->rchild)  //若存在左右子树，则压入栈s中
                stack.push(s, tmp->rchild);
            if(tmp->lchild)
                stack.push(s, tmp->lchild);
        }
        while(!stack.empty(output))
        {
            Visit(stack.top(output)->data);  //在output中依次全部出栈，即为后序遍历的结果
            stack.pop(output);
        }
    }
    return 0;
}



//无论是迭代还是递归实现的先/中/后序遍历，均需要使用栈（遍历到节点入栈，处理节点出栈），而层序遍历使用队列。

//层序遍历：依次访问每层从左到右的节点。
//队列实现：各节点依次入队，依次出队。
int level_traversal(PNode T)
{
    queue q;
    Enqueue(T)
    while(!queue.empty(q))
    {
        Visit((q->rear)->data);
        Dequeue(q);  //访问队尾元素，并将队尾元素出队
        if(q->rear->lchild)
            Enqueue(q->rear->lchild);
        if(q->rear->rchild)
            Enqueue(q->rear->rchild);
    }
    return 0;
}


//求树的高度
int Height(PNode T)
{
    while(T)
    {
        if(!T->rchild && !T->lchild)  //如果T为叶子，没有左右子树
            retuen 1；
        else
            return Height(T->lchild) > Height(T->rchild)? Height(T->lchild)+1 : Height(T->rchild)+1;  //递归左右子树，取较高的一边加上1

    }
}

//求树的节点的个数
int CountNode(Node T)
{
    if(!T)
        teturn 0;
    return CountNode(T->lchild) + CountNode(T->rchild) +1;  //递归实现，总结点个数等于左子树节点数+右子树节点数+1；
}
