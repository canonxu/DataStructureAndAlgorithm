//二叉堆是一种特殊的堆，二叉堆是完全二叉树或者是近似完全二叉树。优先队列的实现。
//二叉堆有两种：最大堆和最小堆。最大堆：父结点的键值总是大于或等于任何一个子节点的键值；最小堆：父结点的键值总是小于或等于任何一个子节点的键值。(堆序性)

//本例程中使用最小堆


//对对结构进行初始化（创建一个堆结构）
PHeap Creat_HeapStructure(int max_ele)
{
    PHeap H;
    H = PHeap malloc(sizeof(PHeap));
    if(H == NULL) printf("memory allocation failure!");  //给该队结构分别配内存

    H->array = int *malloc(sizeof(int)*capcacity);
    if(H->array == NULL) printf("memory allocation failure!");    //给对结构内的数组非配内存
    //该数组中，我们在0号位放一个极小值（小于堆中任何可能的值），保证最小值放到对顶后得以终止。也就是说，堆中正式元素是从1号位开始的。

    H->size = 0;
    H->capacity = max_ele;

    return H;
}


//对已存在的二叉树进行调整成二叉堆
PHeap Initialize_MinHeap(PHheap H)
{
    int i;
    for(i = (H->size)/2; i >= 1; i--)
    {
        int key = H->array[i]  //寻找放i的位置
        int child = 2 * i;                                          //H->size/2节点只有一个孩子时，不需要比较左右孩子，此时child == H->size;
        if(child != H->size && H->array[child] > H->array[child])  //child != H->size已经说明不是“H->size/2节点只有一个孩子的情形”
            child++          //获取子节点的较小者
        if(H->array[child] < key)
            H->array[i] = H->array[child];
        H->array[child] = key;
    }
}




//二叉堆插入（上滤：末尾新建空位，空位（带着待插入的值）往上走，新插入值不断与空位的父节点比较，找到合适位置）
void insert(PHeap H, int data)
{
    if(isFull(H)) return ;  //若当前堆已满，则不能插入，退出

    int i = ++H->size;  //数组中往后新建一个空位
    for(i; H->array[i/2] > data; i /= 2)  //此处i标注空穴的位置，不断往上浮
        H->array[i] = H->array[i/2];       //若新建节点的父节点比data大，则用该父节点值填充新建节点
    H->array[i] = data;   //直到合适的位置，该位置比父节点大，比子节点都小，则插入data
}


//删除最小元素（下滤：删除首元素后形成空位，空位（带着末元素）往下走，该末元素不断与空位的两个儿子较小者比较，找到合适位置）
//删除最小元素，并返回该最小元素的值
void delete_min(PHeap H)
{
    if(isEmpty(H)) return ;  //若当前堆为空，无法删除吗，退出

    int del_min_ele = H->array[1];
    int last_ele = H->array[H->size--]; //去除最后一个值，然后size--
    int child;
    for(i = 1; i <= (H->size)/2; i = child)  //此处i标注空穴的位置，不断下沉
    {
        child = 2*i;  //当i    每个节点都有两个儿子（即末节点一定有兄弟节点）
        if(child != H->size && H->array[child] > H->array[child+1]) //比较两孩子节点大小，取其小
            child++;
        if (H->array[child] < last_ele)
            H->array[i] = H->array[child];
        else  break;
    }
    H->array[i] = last_ele;
    return del_min_ele;
}
