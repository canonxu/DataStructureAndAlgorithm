#include <stdio.h>

//�������������ң���BST�е�Search����

//�ݹ鷨
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
    return ; //û�ҵ�����NULL������TΪ��������NULL��
}


//������
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
    return ; //û�ҵ�����NULL������TΪ��������NULL��
}
