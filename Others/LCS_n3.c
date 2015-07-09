#include <stdio.h>


//复杂度为n的三次方,三套循环
int LCS_n3 (int A[], int n )
{
    int MaxSum = A[0];
    int CurSum;
    int i, j, k;
    for (i = 0; i < n;  i++)
    {
        for (j = i; j < n; j++)
        {
            CurSum = 0;
            for (k=i; k <= j; k++)
            {
                CurSum +=A[k];
            }
            if (CurSum > MaxSum)
                MaxSum = CurSum;
        }
    }
    return MaxSum;
}

//复杂度为n的平方，两套循环
int LCS_n2(int A[], int n)
{
    int MaxSum = A[0];
    int CurSum;
    int i, j;
    for (i = 0; i <n; i++)
    {
        CurSum = 0;
        for (j = i; j < n; j++)
        {
            CurSum += A[j];
            if (CurSum > MaxSum)
                MaxSum = CurSum;  //此处比较在第二套循环之内
        }

    }
    return MaxSum;

}

//复杂度为nlogn，分治

int LCS_Div_Con(int A[], int low, int high)
{
    if (low == high) //如果只有一个数字
        return A[low];

    int mid = (low+high)/2;

    int LeftMax = LCS_Div_Con(A, low, mid);  // 对左半支进行递归
    int RightMax = LCS_Div_Con(A, mid+1, high); //对右半支进行递归

    int LeftTmp = A[mid], LeftScan = A[mid], i;
    for (i = mid-1; i >=low; i-- )
    {
        LeftTmp += A[i];
        if (LeftTmp > LeftScan)
            LeftScan = LeftTmp;
    }
    int RightTmp = A[mid+1], RightScan = A[mid+1], j;
    for (j = mid+2; j <= high; j++)
    {
        RightTmp += A[j];
        if (RightTmp > RightScan)
            RightScan = RightTmp;
    }
    int CrossMax = LeftScan + RightScan;   //跨立的情况，中间网左扫的最大和+中间往右扫的最大和


    int MaxSum = RightMax > LeftMax ? RightMax:LeftMax;
    if (CrossMax > MaxSum)
        MaxSum = CrossMax;   //求三者的最大值


    return MaxSum;
}

//复杂度为n，动态规划
int LCS_DP(int A[], int n)
{
    int MaxSum = A[0], CurSum = 0, i;
    for (i = 0; i < n; i++)
    {
        CurSum += A[i];
        if (CurSum > MaxSum)
            MaxSum = CurSum;
        if (CurSum < 0)
            CurSum = 0;    //若为负，则归零
    }
    return MaxSum;
}


int main()
{
    int A[] = {-3, 10, -4, 14, -6, -2};
    //int max = LCS_n3(A, 6);
    int max = LCS_Div_Con(A, 1, 5);
    //int max = LCS_DP(A, 6);
    printf("%d\n", max);
    return 0;
}
