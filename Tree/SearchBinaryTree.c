#include <stdio.h>
#define LEN sizeof(struct Node)




PNode MakeNode(int data)
{
    PNode p = (PNode)malloc(LEN);
    if(P == NULL)
        printf("Memory allocation failure!");

    p->data = data;
//    p->parent = NULL;  //parent������Ҳ�ɲ����ã����õĻ�����˫�򣬽ڵ�仯ʱҪ˫��仯
    p->lchild = NUll;
    p->rchild = NULL;
}


//����һ�ſ����������ڿ�������ͷָ��Tָ����ڵ㣬ͬʱͷָ��TҲ����������ơ�
PTree CreatEmptyTree()
{
    PTree T = NULL;
    return T;
}

// ����һ������������ΪT�����ڵ�ΪNULL����������
PTree T = CrearEmptyTree();

//�����ÿգ��ݹ�ķ���
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

//�ж����Ƿ�Ϊ�գ�T==NULL��
int IsEmptyTree(PTree T)
{
    return T = NULL;
}

//���Ҳ���,���������ƺ�Ҫ���ҵ�ֵ���������ֵ���ڽڵ��ָ��
//�ݹ鷽��
PNode Search(PTree T, int data)
{
    if(T == NULL)
        return NULL;

    if(data == T->data)  //��Ϊbase case�������������������������
        return T;
    else if(data < T->data)
        return Search(T->lchild, data);
    else if(data > T->data)
        return Search(T->rchild, data);
}

//��������
PNode Search(PTree T, int data)
{
    if(T == NULL)
        return NULL;

    while(T)
    {
        if(data == T->data)  //���ϴ˿����������õ����
            return T;
        else if(data < T->data)//��������������䣬ʵ����������Ѱ��
            T = T->lchild;
        else if(data > T->data)
            T = T->rchild;
    }

}


//���������ֵ,�������ֵ�Ľڵ�ָ��
//������Сֵ���ƣ�rchild�ĳ�lchild���ɡ�

//�Ǳ�������-һֱ������
PNode SearchMax(PTree T)
{
    if(T == NULL)
        return NULL;
/* //һ������д���ȼ�
    while(T->rchild != NULL)  //һֱ�����ң�ֱ��������while������T->rchild==NULL��
        T = T->rchild;
    return T;
*/
    while(T)
    {
        if(T->rchild == NULL)  //�յ�����
            return T;
        else
            T = T->rchild;  //һֱ������
    }

}

//trick:�ݹ���if��������return ;һ���������ߡ�ѭ��ʹ��while�������������䣨��ֵ�ȣ���һ���������ߡ�

//��������-���ҽڵ�ݹ�
PNode SearchMax(PTree T)
{
    if(T == NULL)
        return NULL;
    if(T->rchil!= NULL)   //���ұ���
        return SearchMax(T->rchild);
    else            //else��T->echild == NULL;
        return T;
}


//������������������ƺ�Ҫ����ڵ��ָ�룬����ָ���²���ڵ��ָ�롣ǰ���Ǹò���ֵ���ܵ���ԭ���е�ֵ��
//һ������ֻ��һ������/û�ж��ӵĽڵ��ϲ��룬�ҵ�Ҫ����Ľڵ���½��ڵ�Ⱥ����жϲ����������������������ɡ�
PNode Insert(PTree T,int data)
{
    //��Ϊ�գ������Ľڵ�Ϊ��һ���ڵ㣬ͷָ��ָ�����һ���ڵ㡣
    //�����ֿ��ܡ�һ�ֿ����Ǹ���ȷʵΪ�գ��²���Ϊ��һ���ڵ�
    //��һ�ֿ����ǣ�������������if���ҵ�Ӧ�ò����λ�ã�Insert(T->lchild, data)/Insert(T->rchild, data)�����T->lchild/T->rchildҲΪ�գ���ʱ��Ϊ�ݹ��base case��
    if(T == NULL)
    {
        PNode newnode = MakeNode(data);    //ͷָ��ָ��ýڵ�  // ���и��ڵ������ p->parent = T; �²���ָ���parentָ��ͷָ��
        T = newnode;
    }

    //�������Ԫ��ֵС�ڸ��ڵ�ֵ����Ԫ�ز��뵽�������С��������Ԫ��ֵ��С�ڸ��ڵ�ֵ����Ԫ�ز��뵽�������С�
    //�ݹ����Insert(T->lchild/T->rchild, data)��T->lchild/T->rchild�����������ߣ�ֱ��Ӧ�ò����λ��T,T��T->rchild/T->lchild==NULL��
    // ����if��T == NULL�����½��ڵ㷵�ظýڵ�ָ�룬��ֵ��rchild/lchild���в��롣
    if(data < T->data)
        T->lchild =  Insert(T->lchild, data)
    else if(data > T->data)
        T->rchild =  Insert(T->rchild, data)

    retuen T;  //��T����if(T == NULL)�е�T��Ϊ�²���ڵ��ָ��
}


//�����ķ����ҵ�Ҫ������½ڵ�ĸ��ڵ㣬������
PNode Insert(PTree T, int data)
{
    PNode newnode = MakeNode(data);

    //�����Ϊ�գ���ͷָ��ָ��ýڵ㣬���ظýڵ�ָ��
    if(T == NULL)
        return T = newnode;

    //Ѱ�ҵ��½ڵ�����ӵ��ĸ��ڵ�aimnode����������ȥ�������½ڵ�ָ��
    PNdde aimnode = SearchToInsert(T, data);
    if(data < aimnode->data)
        aimnode->lchild = newnode;
    else
        aimnode->rchild = newnode;
    return newnode
}

//�ҵ��½ڵ�ĸ��ڵ㣬ʹ���½ڵ������ں��档(ǰ���Ǹýڵ㲻���ڸ�����)
PNode SearchToInsert(PTree T, int data)
{
    if(T == NULL)  //�������Ϊ�գ�����NULL�� ��Insert�в�δ�õ�����ΪInsertʱ2�ѽ���������Ϊ�յ��жϺͲ�����
    {
        printf("This tree is empty!");
        return NULL;
    }

    while(T)
    {
        //���Ѱ�ҵ��Ľڵ�����������������֮һ�����ң�����Ϊ����Ҫ�����ֵdataС�ڣ����ڣ��ýڵ��ֵ�������½ڵ���ڸýڵ���
        //��Search��������Ҫ�����base case�ϣ���������ifֻ�������ҵ��ߣ�
        if( (data < T->data && T->lchild == NULL) || (data > T->data && T->rchild == NULL) )
            return T;
        else if(data < T->data)
            T = T->lchild;
        else if(data > T->data)
            T = T->rchild;
    }

}



//ɾ������

//�����������ɾ����������������д���

//1. pΪҶ�ӽڵ㣨0�����ӣ���ֱ��ɾ���ýڵ㣬���޸��丸�ڵ��ָ�루ע����Ǹ��ڵ�Ͳ��Ǹ��ڵ㣩a��

//2.pΪ��֧�ڵ㣨��ֻ������������������1�����ӣ�����p��������p�ĸ��׽ڵ�������ɾ��p���ɣ���ע����Ǹ��ڵ�Ͳ��Ǹ��ڵ㣩����ͼb��

//3.p���������������������գ��������ӣ����ҵ�p�ĺ��y����Ϊyһ��û�������������Կ���ɾ��y������y�ĸ��׽ڵ��Ϊy���������ĸ��׽ڵ㣬����y��ֵ����p��ֵ�����߷��������ҵ�p��ǰ��x��xһ��û�������������Կ���ɾ��x������x�ĸ��׽ڵ��Ϊy���������ĸ��׽ڵ㡣��ͼc��



//Ѱ���Ѵ��ڽڵ�ĸ��ڵ�
PNode SearchFather(PTree T, int data)
{
    if(T == NULL || (T->lchild == NULL && T->rchild == NULL)) //TΪ��������Tֻ��һ���ڵ�Ϊ���ڵ�
    {
        printf("This tree is empty / only one root node!");
        return NULL;
    }

    while(T)
    {
        if( T->rchild == data || T->lchild ==data )  //�յ�����
            return T;
        else if(data < T->data)//��������������䣬ʵ����������Ѱ��
            T = T->lchild;
        else if(data > T->data)
            T = T->rchild;
    }
}

//ǰ���Ǹ����д���data���ֵ
void Delete(PTree T, int data)
{
    PNode aim = Search(T, data);  //aimΪ����ɾ���Ľڵ��ָ��
    PNode aimfather = SearchFather(T, data) //aimfatherΪaim�ĸ��ڵ�ָ��

/*aimΪҶ�ӵ������Ҫ���ǡ�����д��ʱ����Ȼ�ϲ���ֻ��һ��Ҷ�ӵ������ȥ�ˡ�
    //aimΪҶ�ӣ���û�ж���
    if(aim->lchild == NULL && aim->rchild == NULL)
    {
        if(aim == T) //��Ҫɾ����Ϊ���ڵ�
            T = NULL;

        if(data < aimfather->data)    //�ж�aimΪaimfather������ӻ��Ҷ���
            aimfather->lchile = NULL;
        else
            aimfather->rchild = NULL;

        free(aim);  //�ͷŽڵ�
        return ;
    }
*/

    //aimΪ��֧�ڵ㣬��ֻ��һ������
    //ֻ������Ҷ��
     if(aim->rchild == NULL)
     {
        if(aim == T) //��Ҫɾ����Ϊ���ڵ�
            T = aim->lchild;
 /*       if(data < aimfather->data)    //�ж�aimΪaimfather������ӻ��Ҷ��ӡ���Ҫɾ���ڵ�Ķ��ӽӵ�Ҫɾ���ڵ�ĸ��ڵ��ϡ�
            aimfather->lchile = aim->lchild;
        else
            aimfather->rchild = aim->lchild;
*/
        aim = aim->lchild;
        free(aim);    // �ͷŽڵ�
        return ;
     }

    //ֻ������Ҷ��
     if(aim->lchild == NULL)
     {
        if(aim == T) //��Ҫɾ����Ϊ���ڵ�
            T = aim->rchild;
        aim = aim->lchild;
        free(aim);    // �ͷŽڵ�
        return ;
     }

    //aim���ҽڵ㶼����

    //�����ҵ������������ֵ(����������Сֵ)��Ϊ�����
    //��rchildmax��rchildmin����ֵ����ڼ���ɾ���Ľڵ�ֵ����ɾ��rchildmax��rchildmin���ڵ㣨��ֻ��һ�����ӣ���
    //����������ڵ����ֵΪ��
    else
    {

        PNode rchildmax = SearchMax(aim->richild);  //�ҵ�aim�����������ֵ��ָ��RChildMax����rchildmaxһ��û���Һ����ˡ�
        aim->data = rchildmax->data;  //��rchildmax��ֵ����aim��ֵ
        //��ɾ��rchildmax����ڵ㡣 ֻ������һ�����ӻ���û�к��ӡ��ݹ���ñ��������ɡ�
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
