#include <stdio.h>
#define LEN 8

//参考：http://blog.csdn.net/insistgogo/article/details/7785038

//快速排序(QuickSort)的最坏时间复杂度应为0(n2)，最好时间复杂度为O(nlgn)，平均时间复杂度为O(nlgn)
//快速排序，这也是在实际中最常用的一种排序算法，速度快，效率高!!!

//快速排序的时间主要耗费在划分操作(find_pivoit)上，对长度为k的区间进行划分，共需k-1次关键字的比较。

//枢纽元Pivot的选取非常重要。
//错误的做法：选取第一个元素作为Pivot。如果数组随机，选第一个元素可以接受，若数组已有序（升序/降序）/数组全相等时将使得复杂度变为O（n^2）
//安全的做法：随机选取枢纽元（产生随机数获取a[ran]与a[low]交换）。但是随机数生成本省有昂贵开销。
/*
#include <time.h>
void(int *a, int low, int high)
{
    srand((unsigned int) time(0));
    swap(a[low],a[rand()%LEN]
}
*/
//三数中值分割法：选取第一个数a[0]中间的数a[n/2]最后一个数a[n]，这三个数的中值（将这个中值调整到[0]处）。
/*
void MediaOfThree(int *a, int low, int high)  //本函数实现将中值赋值给a[low]
{
    int mid = low + (high - mid)/2;
    if(a[mid] > a[high]) swap(a[mid], a[high]);  //a[mid] < a[high]
    if(a[low] > a[high]) swap(a[low], a[high]);  //a[low] < a[high];
    if(a[low] < a[mid]) swap(a[low], a[high])    //a[low] > a[low]           //至此,a[mid] < a[low] < a[high]，数组首元素a[low]为中值
}
*/


/*内层循环中的while测试是用“严格大于/小于”还是”大于等于/小于等于”。答案是用严格大于/小于
一般的想法是用大于等于/小于等于，忽略与枢纽元相同的元素，这样可以减少不必要的交换，因为这些元素无论放在哪一边都是一样的。
但是如果遇到所有元素都一样的情况，这种方法每次都会产生最坏的划分,也就是一边1个元素，令一边n－1个元素，使得时间复杂度变成O(N^2)。
而如果用严格大于/小 于，虽然两边指针每次只挪动1位，但是它们会在正中间相遇，产生一个最好的划分，时间复杂度为log(2n)
*/

//-------------------------------------------------------------------------------------------------------------------

//输入数组和数组头low尾high，得到分割整个数组的点low的位置，此时low左边均比a[low]小，low右边均比a[low]大
//以第一个元素为Pivot的例程

//最经典的写法
int find_pivot(int *a, int low, int high)
{
    int pivot = a[low];  //以数组第一个数作为基准，挖走
    while(low < high)
    {
        while(low < high && a[high] >= pivot) high--;      //从后往前搜索，找到第一个小于key的值，挖走填充a[low]这个坑
        a[low] = a[high];
        while(low < high && a[low] <= pivot) low++;    //从前往后搜索，找到第一个大于key的值，挖走填上面挖的a[high]这个坑
        a[high] = a[low];
    }
        a[low] = pivot;  //用第一次挖出的pivot填当前a[low]这个坑，此点已位于正确位置，就是我们要找的基准点
        return low;
}

//寻找基准点也可以用swap实现。但是swap一次需3次赋值，内存读写次数较多！
void swap(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}
int find_pivot_swap(int *a, int low, int high)
{
    int pivot = a[low];  //以数组第一个数作为基准，挖走。 此处基准可换a[high]/a[median]即可
    while(low < high)
    {
        while(low < high && a[high] >= pivot) high--;      //从后往前搜索，找到第一个小于key的值，挖走填充a[low]这个坑
        swap(&a[high], &a[low]);
        while(low < high && a[low] <= pivot) low++;    //从前往后搜索，找到第一个大于key的值，挖走填上面挖的a[high]这个坑
        swap(&a[high], &a[low]);
    }
        return low;
}


//内循环严格大于/小于。
//这种情况下，a[low++] = a[high]复制后将low自增，a[high--] = a[low]赋值后将high自减。因为此时low/high到pivot等值后不移动，不能对有相同值得数组排序。
int find_pivot_strict(int *a, int low, int high)
{
    int pivot = a[low];  //以数组第一个数作为基准，挖走
    while(low < high)
    {
        while(low < high && a[high] > pivot) high--;      //从后往前搜索，找到第一个小于等于key的值，挖走填充a[low]这个坑
        if(low < high) a[low++] = a[high];
        while(low < high && a[low] < pivot) low++;    //从前往后搜索，找到第一个大于等于key的值，挖走填上面挖的a[high]这个坑
        if(low < high) a[high--] = a[low];
    }
        a[low] = pivot;  //用第一次挖出的pivot填当前a[low]这个坑，此点已位于正确位置，就是我们要找的基准点
        return low;
}



//最经典的，以首元素作为Pivot的快排
int quick_sort(int *a, int low, int high)
{
    if(low >= high) return; //只有一个元素的时候
    //找到基准点后，采用分治策略，两边分别递归即可

    int pivot = find_pivot(a, low, high);
    quick_sort(a, low, pivot - 1);
    quick_sort(a, pivot + 1, high);

    return 0;
}



//-------------------------------------------------------------------------------------------------------------------------------
//优化1、当待排序序列的长度分割到一定大小后，使用插入排序(小范围排序合适)。截止范围：待排序序列长度N = 10比较合适。减少递归栈的使用（对系统栈的频繁存取影响效率）。
void insertion_sort(int *a, int low, int high)
{
    int i, j, key;
    for(i = low; i <= high; i++)
    {
        key = a[i];
        j = i - 1;
        for(j; j >= low && a[j] > key; j--)
            a[j + 1] = a[j];
        a[j + 1] = key;
    }

}
int quick_sort1(int *a, int low, int high)
{
    if(low >= high) return; //只有一个元素的时候

    if( 0 <(high - low + 1) < 10)              //当 数字个数小数10时，采用插入排序。
            insertion_sort(a, low, high);

    if(low < high)
    {
        int pivot = find_pivot(a, low, high);
        quick_sort(a, low, pivot - 1);
        quick_sort(a, pivot + 1, high);
    }
    return 0;
}

//优化2、解决"最经典例程"数组全相等是复杂度为O（n^2）问题。在一次分割后将与pivot相等的值聚在一次，下次分割的时候不在对piovt相等的值进行分割。
//第一步，在划分过程中，把与key相等元素放入数组的两端
//第二步，划分结束后，把与key相等的元素移到枢轴周围

int quick_sort(int *a, int low, int high)
{
    if(low >= high) return; //只有一个元素的时候

    int pivot = a[low];  //以数组第一个数作为基准，挖走

    int first = low;
    int last = high;
    int right = high;
    int right_same = 0;  //右边等于pivot的值的个数
    int low = left;
    int lest_same = 0  //左边等于pivot的值的个数
    while(low < high)
    {
        while(low < high && a[high] >= pivot)
        {
            if(a[high] == pivot)           //若a[high]等于pivot，移到最右边
            {
                swap(a[high], a[right]);
                right--;
                right_same++;
            }
        }
        high--;
        a[low] = a[high];

        while(low < high && a[low] <= pivot)
        {
                if(a[low] == pivot)           //若a[low]等于pivot，移到最左边
                {
                swap(a[low], a[left]);
                left++;
                right_same++;
                }
        }
        low++;
        a[high] = a[low];
    }
    a[low] = pivot;  //至此，找到基准点a[low]，完成第一步

    int i = low - 1;            //将数组左端等于pivot的值移到紧邻pivot最左
    int j = first;
    while(j < low && a[i] != pivot)
    {
        swap(a[j], a[i]);
        i--;
        j++
    }

    i = low + 1;               //将数组右端等于pivot的值移到紧邻pivot最右
    j = last;
    while(j > low && a[i] != pivot)
    {
        swap(a[j], a[i]);
        i++;
        j--;                  //至此，完成第二步
    }

    quick_sort(a, first , pivot - 1 - left_same );
    quick_sort(a, pivot + 1 + right_same, last);
    }
    return 0;
}






//优化3、尾递归优化（递归操作在末尾）。快排函数在函数尾部有两次递归操作，我们可以对其使用尾递归优化。尽管尾递归优化一般由编译器完成。
//优点：如果待排序的序列划分极端不平衡，递归的深度将趋近于n，而栈的大小是很有限的，每次递归调用都会耗费一定的栈空间，函数的参数越多，每次递归耗费的空间也越多甚至栈溢出。
//优化后，可以缩减堆栈深度，由原来的O(n)缩减为O(logn)，将会提高性能。
int quick_sort2(int *a, int low, int high)
{
    if(low >= high) return; //只有一个元素的时候

    if( 0 <(high - low + 1) < 10)
            insertion_sort(a, low, high);


    int pivot = find_pivot(a, low, high);
    quick_sort(a, low, pivot - 1);
    low = pivot + 1;   //在第一次递归后，low就没用了，此时第二次递归可以使用循环代替。

    return 0;
}

int main()
{

    int array[] = {2, 2, 2, 3, 2, 4, 2, 2};
    quick_sort(array, 0, LEN - 1);
    int k;
    for(k = 0; k < LEN; k++)
        printf("%d ", array[k]);
    return 0;
}

