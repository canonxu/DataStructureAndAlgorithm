#include <stdio.h>
#define LEN sizeof(struct Node)




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


//查找做最大值,返回最大值的节点指针
//查找最小值类似，rchild改成lchild即可。

//非遍历方法-一直往右找
PNode SearchMax(PTree T)
{
    if(T == NULL)
        return NULL;
/* //一下两种写法等价
    while(T->rchild != NULL)  //一直往右找，直到不满足while条件即T->rchild==NULL；
        T = T->rchild;
    return T;
*/
    while(T)
    {
        if(T->rchild == NULL)  //终点条件
            return T;
        else
            T = T->rchild;  //一直往右走
    }

}

//trick:递归用if（）搭配return ;一步步往下走。循环使用while（）搭配控制语句（赋值等）；一步步往下走。

//遍历方法-往右节点递归
PNode SearchMax(PTree T)
{
    if(T == NULL)
        return NULL;
    if(T->rchil!= NULL)   //往右遍历
        return SearchMax(T->rchild);
    else            //else即T->echild == NULL;
        return T;
}


//插入操作，输入数名称和要插入节点的指针，返回指向新插入节点的指针。前提是该插入值不能等于原树中的值。
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

    retuen T;  //此T来自if(T == NULL)中的T，为新插入节点的指针
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

//二叉查找树的删除，分三种情况进行处理：

//1. p为叶子节点（0个儿子），直接删除该节点，再修改其父节点的指针（注意分是根节点和不是根节点）a。

//2.p为单支节点（即只有左子树或右子树，1个儿子）。让p的子树与p的父亲节点相连，删除p即可；（注意分是根节点和不是根节点）；如图b。

//3.p的左子树和右子树均不空（两个儿子）。找到p的后继y，因为y一定没有左子树，所以可以删除y，并让y的父亲节点成为y的右子树的父亲节点，并用y的值代替p的值；或者方法二是找到p的前驱x，x一定没有右子树，所以可以删除x，并让x的父亲节点成为y的左子树的父亲节点。如图c。



//寻找已存在节点的父节点
PNode SearchFather(PTree T, int data)
{
    if(T == NULL || (T->lchild == NULL && T->rchild == NULL)) //T为空树或者T只有一个节点为根节点
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

//前提是该树中存在data这个值
void Delete(PTree T, int data)
{
    PNode aim = Search(T, data);  //aim为即将删除的节点的指针
    PNode aimfather = SearchFather(T, data) //aimfather为aim的父节点指针

/*aim为叶子的情况需要考虑。但是写的时候，自然合并到只有一个叶子的情况中去了。
    //aim为叶子，即没有儿子
    if(aim->lchild == NULL && aim->rchild == NULL)
    {
        if(aim == T) //若要删除的为根节点
            T = NULL;

        if(data < aimfather->data)    //判断aim为aimfather的左儿子或右儿子
            aimfather->lchile = NULL;
        else
            aimfather->rchild = NULL;

        free(aim);  //释放节点
        return ;
    }
*/

    //aim为单支节点，即只有一个儿子
    //只存在左叶子
     if(aim->rchild == NULL)
     {
        if(aim == T) //若要删除的为根节点
            T = aim->lchild;
 /*       if(data < aimfather->data)    //判断aim为aimfather的左儿子或右儿子。把要删除节点的儿子接到要删除节点的父节点上。
            aimfather->lchile = aim->lchild;
        else
            aimfather->rchild = aim->lchild;
*/
        aim = aim->lchild;
        free(aim);    // 释放节点
        return ;
     }

    //只存在右叶子
     if(aim->lchild == NULL)
     {
        if(aim == T) //若要删除的为根节点
            T = aim->rchild;
        aim = aim->lchild;
        free(aim);    // 释放节点
        return ;
     }

    //aim左右节点都存在

    //首先找到左子树的最大值(右子树的最小值)作为替代。
    //用rchildmax（rchildmin）的值替代在即将删除的节点值，并删除rchildmax（rchildmin）节点（都只有一个儿子）。
    //本案例以左节点最大值为例
    else
    {

        PNode rchildmax = SearchMax(aim->richild);  //找到aim左子树的最大值的指针RChildMax，该rchildmax一定没有右孩子了。
        aim->data = rchildmax->data;  //用rchildmax的值代替aim的值
        //下删除rchildmax这个节点。 只可能有一个左孩子或者没有孩子。递归调用本函数即可。
        Delete(PTree T, int rchildmax->data);

    }
}


PTree Delete(PTree T, int data)
{
    if( T == NULL)
        printf("This tree is empty!");
    if (data > T->data)
        T->lchild = Delete(T->lchild, data);
    else if (data > T->data)
        T->rchild - Delete(T->rchild ,data);
    else if (T->rchild && T->lchild)
    {


    }



}
