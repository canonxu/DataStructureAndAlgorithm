#include <stdio.h>
#define LEN sizeof(struct Node)

PNode MakeNode(int data)
{
    PNode p = PNode malloc(LEN);
    if (p == NULL)
        printf("Memory allocation failure!");
    p->data = data;
    p->parent = NULL;
    p->lchild = NULL;
    p->rchild = NULL;
    return p;
}


6
PNode InsertNode(PNode root,PNode p)
{
    if (root = NULL)
        root = p;
    else if (p->data < root->data)
        root->lchild = InsertNode(root->lchild,p);
    else
        root->rchild = InsertNode(root->rchild,p);
    return toot;
}
