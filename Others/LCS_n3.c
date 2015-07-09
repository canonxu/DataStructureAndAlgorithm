#include <stdio.h>


//���Ӷ�Ϊn�����η�,����ѭ��
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

//���Ӷ�Ϊn��ƽ��������ѭ��
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
                MaxSum = CurSum;  //�˴��Ƚ��ڵڶ���ѭ��֮��
        }

    }
    return MaxSum;

}

//���Ӷ�Ϊnlogn������

int LCS_Div_Con(int A[], int low, int high)
{
    if (low == high) //���ֻ��һ������
        return A[low];

    int mid = (low+high)/2;

    int LeftMax = LCS_Div_Con(A, low, mid);  // �����֧���еݹ�
    int RightMax = LCS_Div_Con(A, mid+1, high); //���Ұ�֧���еݹ�

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
    int CrossMax = LeftScan + RightScan;   //������������м�����ɨ������+�м�����ɨ������


    int MaxSum = RightMax > LeftMax ? RightMax:LeftMax;
    if (CrossMax > MaxSum)
        MaxSum = CrossMax;   //�����ߵ����ֵ


    return MaxSum;
}

//���Ӷ�Ϊn����̬�滮
int LCS_DP(int A[], int n)
{
    int MaxSum = A[0], CurSum = 0, i;
    for (i = 0; i < n; i++)
    {
        CurSum += A[i];
        if (CurSum > MaxSum)
            MaxSum = CurSum;
        if (CurSum < 0)
            CurSum = 0;    //��Ϊ���������
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
