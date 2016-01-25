#include <stdio.h>

//二叉搜索树查找，即BST中的Search函数

//递归法
PNode BST_Search(PNode T, int data)
{
    while(T)
    {
        if(T->data > data)
            return BST_Search(T->lchild,data);
        else if(T->data < data)
            return BST_Search(T->rchild,data);
        else
            return T;
    }
    return ; //没找到返回NULL，或者T为空树返回NULL；
}


//迭代法
PNode BST_Search(PNode T, int data)
{
    while(T)
    {
        if(T->data > data)
            T = T->lchild;
        else if(T->data < data)
            T = T->rchild;
        else
            return T;
    }
    return ; //没找到返回NULL，或者T为空树返回NULL；
}
