#include <stdio.h>
#define LEN sizeof(struct Node)


//�½��ڵ㣺�ȴ����ýڵ��ָ��p���ٸ��ṹ����Ԫ�ظ�ֵ��
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


//Ѱ���Ѵ��ڽڵ�ĸ��ڵ�
PNode SearchFather(PTree T, int data)
{
    if(T == NULL || (T->lchild == NULL && T->rchild == NULL)) //TΪ��������Tֻ��һ���ڵ�Ϊ���ڵ�(���ڵ���û�и��ڵ��)
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

//���������ֵ,�������ֵ�Ľڵ�ָ��
//������Сֵ���ƣ�rchild�ĳ�lchild���ɡ�

//�Ǳ�������-һֱ������
PNode SearchMax(PTree T)
{
    if(T == NULL)
        return NULL;
//��������д���ȼ�
    while(T->rchild != NULL)  //һֱ�����ң�ֱ��������while������T->rchild==NULL��
        T = T->rchild;
    return T;
/*
    while(T)
    {
        if(T->rchild == NULL)  //�յ�����
            return T;
        else
            T = T->rchild;  //һֱ������
    }
*/
}

//trick:�ݹ���if��������return ;һ���������ߡ�ѭ��ʹ��while�������������䣨��ֵ�ȣ���һ���������ߡ�

//��������-���ҽڵ�ݹ�
PNode SearchMax(PTree T)
{
    if(T == NULL)
        return NULL;

    if(T->rchil!= NULL)   //���ұ���
        return SearchMax(T->rchild);

    return T;        //else��T->echild == NULL;

}


//������������������ƺ�Ҫ����ڵ��ָ�룬����ָ���²���ڵ��ָ��ĸ�ָ�롣ǰ���Ǹò���ֵ���ܵ���ԭ���е�ֵ��
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

    retuen T;  // T->lchild/rchildΪInsert()���ص��½��ڵ�ָ�룬���Դ˷��ص���TΪ�²���ڵ��ָ��ĸ�ָ��
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
//ǰ���Ǹ����д���data���ֵ,���ظ��ڵ�
void Delete(PTree T, int data)
{
    PNode aim = Search(T, data);  //aimΪ����ɾ���Ľڵ��ָ��

/*
    ����������ɾ���ڵ��Ϊ���ӣ���Ϊ���������
    1.aim�ڵ�ΪҶ�ӣ�û�ж��ӣ���ֱ��ɾ�����ɣ������ڵڶ�������ڣ�
    2.aim�ڵ�ֻ��һ�����ӣ���aim�ڵ���еĶ������aim�ڵ㼴��
    3.aim�ڵ����������ӣ���aim���������ֵ/��������Сֵ����aim�е�ֵ����ɾ��aim���������ֵ/��������Сֵ�Ľڵ�
*/
    //aimΪ��֧�ڵ��Ҷ�ӣ���ֻ��һ�����ӻ���0������
     PNode Tmp = aim;
    //ֻ������Ҷ��
     if(aim->rchild == NULL)
     {
        aim = aim->lchild;
    }
    //ֻ������Ҷ��
     if(aim->lchild == NULL)
     {
        aim = aim->lchild;
     }

     free(Tmp);

    //aim���ҽڵ㶼����,�����ҵ������������ֵ(����������Сֵ)��Ϊ�����
    //��lchildmax��rchildmin����ֵ����ڼ���ɾ���Ľڵ�ֵ����ɾ��lchildmax��rchildmin���ڵ㣨��ֻ��һ�����ӣ���
    //����������ڵ����ֵΪ��
    else
    {
        PNode lchildmax = SearchMax(aim->lchild);  //�ҵ�aim�����������ֵ��ָ��lchildmax����lchildmaxһ��û���Һ����ˡ�
        aim->data = lchildmax->data;  //��rchildmax��ֵ����aim��ֵ ��
        aim->lchild = Delete(PTree aim->lchild, lchildmax->data); //ɾ��rchildmax����ڵ㡣 ֻ������һ�����ӻ���û�к��ӡ��ݹ���ñ���������
    }

    return T;
}


/*һ��Ϊ���ֱ�����ʽ*/
//�������ڵ�A�������B���Ҷ���C
//�������:���ڵ�-��������Ҷ��� A-B-C
//��������������-�����ڵ�-���Ҷ��� B-A-C
//��������������-���Ҷ���-�����ڵ� B-C-A

//����visit�Ա�������T->data���д������ӡ����������ȡ�

//�ݹ鷨
//����������ȶԸ��ڵ���д���
int preorder_traversal(PNode T)
{
    if(T == NULL)
        retrn 0;

    visit(T->data);
    Preorder_traversal(T->lchild);
    Preorder_traversal(T->rchild);
    return 0;
}
//����������м�Ը��ڵ���д������ڶ����������������������������ź���ģ���ã������ã�
int inorder_traversal(PNode T)
{
  if(T == NULL)
        retrn 0;

    Preorder_traversal(T->lchild);
    visit(T->data);
    Preorder_traversal(T->rchild);
    return 0;

}
//�����������Ը��ڵ���д���
int postorder_traversal(PNode T)
{
    if(T == NULL)
        retrn 0;

    Preorder_traversal(T->lchild);
    Preorder_traversal(T->rchild);
    visit(T->data);
    return 0;
}

//�ǵݹ鷨�����������Ϊ��
/*�������������˳�򣬶�����һ��㣬���ȷ��������ӣ�һֱ�������ӽ��Ϊ�յĽ��Ž��д���Ȼ����ͬ�Ĺ��������������������䴦��������£�

   ������һ���P��

  1)�������Ӳ�Ϊ�գ���P��ջ����P��������Ϊ��ǰ��P��Ȼ��Ե�ǰ���P�ٽ�����ͬ�Ĵ���

  2)��������Ϊ�գ���ȡջ��Ԫ�ز����г�ջ���������ʸ�ջ����㣬Ȼ�󽫵�ǰ��P��Ϊջ�������Һ��ӣ�

  3)ֱ��PΪNULL����ջΪ�����������
*/

//ǰ��������ǵݹ�
int preorder_traversal(PNode T)
{
    stack s;
    while(T != NULL || !stack.empty(s))
    {
        while(T != NULL)
        {
            Visit(T->data);
            stack.push(s, T->rchild); //������ȫ�������ҽ���Ӧ����������ջ
            T = T->lchild;
        }

        if(!stack.empty(s))  //���������ȫ�����������������һ������£�������������������������Щ������������ջ���¶���Щ���������в�����
        {
           T = stack.top(s);
           Visit(T->data);
           stack.pop(s, T); //�ҵ���������������ջ
           T = T->lchild;   //����������������ٽ���������������������ѭ��
        }
    }
    return 0;
}

//����������ǵݹ顣 ����1.while(T != NULL)ʱǰ���Ƚ������������������Ҳ���ջ����������������������������ȫ����ջ����������������������ջ�Ҳ�����
//                         2.if(!stack.empty(s))ʱǰ�����ν�ջ�ڵ����������ʣ���ջ������Щ���������ӱ���T = T->lchild����
//                                                �������ν�վ�ڵ������������ʣ���ջ������Щ����������ÿ������һ��ӦT = T->lchild����������������

int inorder_traversal(PNode T)
{
    stack s;
    while(T != NULL || !stack.empty(s)) //��TΪ�ǿգ���ջ������Ԫ��ʱ�����д���ֱ��T=NULL��ջ����Ԫ��ʱ��������
    {
        while(T != NULL)
        {
            stack.push(s, T); //���ڵ���������Ϊ�գ��򽫴˽ڵ�ѹ��ջ�У��ݲ���������������ȫ����ջ����������  --stack.pop()����Ϊѹջ����
            T = T->lchild;
        }

        //һֱ���ڵ�������Ϊ�գ�����ѭ�����������нڵ㴦��
        if(!stack.empty(s))
        {
            T = stack.top(s);  //��ȡջ��Ԫ�أ�������ѭ���õ���������Ϊ�յĽڵ� --stack.pop()����Ϊȡ��ջ��Ԫ��ָ��ĺ���
            visit(T->data);  //�Ըýڵ���д���
            stack.pop(s, T);  //��������Ľڵ��ջ

            T = T->rchild;  //��ԭT����������ط���while(T != NULL || !stack.empty(s))��T != NULL�����Ըýڵ�����������д���
                        //��ԭTû�����������ʱT=NULL��ջ��Ϊ�գ���ֱ������ if(!stack.empty(s))��ջ��Ԫ�ؽ��д���
        }
    }
    return 0;
}

//����������ǵݹ顣ǰ����������ƣ������Դ��������������֣�������Ƚϸ��ӡ�

//˫ջ��ʵ�ַǵݹ�ĺ������������!
int postorder_traversal(PNode T)
{
    stack s, output; //���ڿ��Ƶ�ջs�ʹ�����Ԫ�ص�ջoutput
    stack.push(s, T);//�Ƚ�Tѹ��lsջ
    PNode tmp;
    while(T)
    {
        while(!stack.empty(s))
        {
            tmp = stack.top(s);
            stack.pop(s);
            stack.push(output, tmp);  //���ν�s�е�ջ��Ԫ��ѹ�뵽output���ջ�б���
            if(tmp->rchild)  //������������������ѹ��ջs��
                stack.push(s, tmp->rchild);
            if(tmp->lchild)
                stack.push(s, tmp->lchild);
        }
        while(!stack.empty(output))
        {
            Visit(stack.top(output)->data);  //��output������ȫ����ջ����Ϊ��������Ľ��
            stack.pop(output);
        }
    }
    return 0;
}



//�����ǵ������ǵݹ�ʵ�ֵ���/��/�������������Ҫʹ��ջ���������ڵ���ջ������ڵ��ջ�������������ʹ�ö��С�

//������������η���ÿ������ҵĽڵ㡣
//����ʵ�֣����ڵ�������ӣ����γ��ӡ�
int level_traversal(PNode T)
{
    queue q;
    Enqueue(T)
    while(!queue.empty(q))
    {
        Visit((q->rear)->data);
        Dequeue(q);  //���ʶ�βԪ�أ�������βԪ�س���
        if(q->rear->lchild)
            Enqueue(q->rear->lchild);
        if(q->rear->rchild)
            Enqueue(q->rear->rchild);
    }
    return 0;
}


//�����ĸ߶�
int Height(PNode T)
{
    while(T)
    {
        if(!T->rchild && !T->lchild)  //���TΪҶ�ӣ�û����������
            retuen 1��
        else
            return Height(T->lchild) > Height(T->rchild)? Height(T->lchild)+1 : Height(T->rchild)+1;  //�ݹ�����������ȡ�ϸߵ�һ�߼���1

    }
}

//�����Ľڵ�ĸ���
int CountNode(Node T)
{
    if(!T)
        teturn 0;
    return CountNode(T->lchild) + CountNode(T->rchild) +1;  //�ݹ�ʵ�֣��ܽ����������������ڵ���+�������ڵ���+1��
}
