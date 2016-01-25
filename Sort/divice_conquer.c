#include <stdio.h>
#define LEN 8

 // �鲢�����ʱ�临�Ӷ�O��nlogn����������O��nlogn�����㷨�����ţ�ϣ�����򣬶�������ȣ�Ч���ǱȽϸߵġ�




void merge(int *a, int start, int mid, int end)
{
    int n1 = mid - start + 1;
    int n2 = end - mid;
    int left[n1], right[n2];
    int i, j;
    for (i = 0; i < n1; i++)
        left[i] = a[start+i];
    for (j = 0; j < n2; j++)
        right[j] = a[mid + 1 + j];  //�ȱ�ʾ��������������飬�½�������������䵽ԭ����a��

    i = j= 0;
    int k = start;
    while (i < n1 && j < n2)  //���������鶼��Ԫ�أ��ȽϺ�С������䵽a������1
        if (left[i] < right[j])
            a[k++] = left[i++];  //a[k++]��++�ں�����ִ��������������a[k]��k����1  //i++��ִ����������++i�������ٸ�ֵ
        else
            a[k++] = right[j++];
    while(i < n1)          //����/������һ�����ˣ���δ��������ȫ����䵽a
        a[k++] = left[i++];
    while(j < n2)
        a[k++] = right[j++];
}


// �鲢����ġ����򲿷֡������õݹ鷽ʽ�����Ӷ�logn
void sort(int *a, int start, int end)
{
    int mid;
    if (start < end) {
        mid=(start + end) / 2;
        sort(a, start, mid);  // start - mid����
        sort(a, mid+1, end);  //mid+1 - end����
        merge(a, start, mid, end);  //������������ϲ�
    }

}

int main(void)
{
    int a[LEN]={1,4,6,7,8,0,9,3};
    sort(a, 0, 7);
    int m;
    for (m=0; m<LEN; m++)
        printf("%d ", a[m]);
    return 0;
}
