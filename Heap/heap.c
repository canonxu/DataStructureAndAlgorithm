//�������һ������Ķѣ����������ȫ�����������ǽ�����ȫ�����������ȶ��е�ʵ�֡�
//����������֣����Ѻ���С�ѡ����ѣ������ļ�ֵ���Ǵ��ڻ�����κ�һ���ӽڵ�ļ�ֵ����С�ѣ������ļ�ֵ����С�ڻ�����κ�һ���ӽڵ�ļ�ֵ��(������)

//��������ʹ����С��


//�ԶԽṹ���г�ʼ��������һ���ѽṹ��
PHeap Creat_HeapStructure(int max_ele)
{
    PHeap H;
    H = PHeap malloc(sizeof(PHeap));
    if(H == NULL) printf("memory allocation failure!");  //���öӽṹ�ֱ����ڴ�

    H->array = int *malloc(sizeof(int)*capcacity);
    if(H->array == NULL) printf("memory allocation failure!");    //���Խṹ�ڵ���������ڴ�
    //�������У�������0��λ��һ����Сֵ��С�ڶ����κο��ܵ�ֵ������֤��Сֵ�ŵ��Զ��������ֹ��Ҳ����˵��������ʽԪ���Ǵ�1��λ��ʼ�ġ�

    H->size = 0;
    H->capacity = max_ele;

    return H;
}


//���Ѵ��ڵĶ��������е����ɶ����
PHeap Initialize_MinHeap(PHheap H)
{
    int i;
    for(i = (H->size)/2; i >= 1; i--)
    {
        int key = H->array[i]  //Ѱ�ҷ�i��λ��
        int child = 2 * i;                                          //H->size/2�ڵ�ֻ��һ������ʱ������Ҫ�Ƚ����Һ��ӣ���ʱchild == H->size;
        if(child != H->size && H->array[child] > H->array[child])  //child != H->size�Ѿ�˵�����ǡ�H->size/2�ڵ�ֻ��һ�����ӵ����Ρ�
            child++          //��ȡ�ӽڵ�Ľ�С��
        if(H->array[child] < key)
            H->array[i] = H->array[child];
        H->array[child] = key;
    }
}




//����Ѳ��루���ˣ�ĩβ�½���λ����λ�����Ŵ������ֵ�������ߣ��²���ֵ�������λ�ĸ��ڵ�Ƚϣ��ҵ�����λ�ã�
void insert(PHeap H, int data)
{
    if(isFull(H)) return ;  //����ǰ�����������ܲ��룬�˳�

    int i = ++H->size;  //�����������½�һ����λ
    for(i; H->array[i/2] > data; i /= 2)  //�˴�i��ע��Ѩ��λ�ã��������ϸ�
        H->array[i] = H->array[i/2];       //���½��ڵ�ĸ��ڵ��data�����øø��ڵ�ֵ����½��ڵ�
    H->array[i] = data;   //ֱ�����ʵ�λ�ã���λ�ñȸ��ڵ�󣬱��ӽڵ㶼С�������data
}


//ɾ����СԪ�أ����ˣ�ɾ����Ԫ�غ��γɿ�λ����λ������ĩԪ�أ������ߣ���ĩԪ�ز������λ���������ӽ�С�߱Ƚϣ��ҵ�����λ�ã�
//ɾ����СԪ�أ������ظ���СԪ�ص�ֵ
void delete_min(PHeap H)
{
    if(isEmpty(H)) return ;  //����ǰ��Ϊ�գ��޷�ɾ�����˳�

    int del_min_ele = H->array[1];
    int last_ele = H->array[H->size--]; //ȥ�����һ��ֵ��Ȼ��size--
    int child;
    for(i = 1; i <= (H->size)/2; i = child)  //�˴�i��ע��Ѩ��λ�ã������³�
    {
        child = 2*i;  //��i    ÿ���ڵ㶼���������ӣ���ĩ�ڵ�һ�����ֵܽڵ㣩
        if(child != H->size && H->array[child] > H->array[child+1]) //�Ƚ������ӽڵ��С��ȡ��С
            child++;
        if (H->array[child] < last_ele)
            H->array[i] = H->array[child];
        else  break;
    }
    H->array[i] = last_ele;
    return del_min_ele;
}
