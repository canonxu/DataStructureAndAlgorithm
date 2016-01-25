//C��������ֵ����(value)��ָ�봫��(address)���ַ�ʽ��
//C++�У���������(reference)���Ρ�


//ֵ����/ָ�봫���迪�����ڴ棬��ſ����õ���ԭ�����ֵ/ԭ����ĵ�ַ�����ô��β���Ҫ�������ڴ棬��ԭ����ġ���������ֱ�Ӷ�ԭ������в���
//ֵ����ֻ�ı��βΣ����ı�ʵ�Σ�ָ�봫�θı��βΣ�ͨ����Ӳ����ı�ʵ�Σ����ô��θı��βΣ�ͨ��ֱ�Ӳ����ı�ʵ��

//ֵ���ݣ�swap�����ڲ�a��b���βΣ�����һ��ʵ�Σ��ж����ڴ��ַ���β�a��b��ֵ���β�ȷʵ�����ˣ�ʵ��a��b��δ�ı䡣
//ֵ�����ǵ���ģ�ʵ��-���βΣ�������ֵ��ֻ�ܴ��룬���ܴ����������ı䲻��main�е�ʵ�Σ�����
void swap1(int a, int b)
{
    int t = a;
    a = b;
    b = t;
}

//ָ�봫�ݣ�swap�����ڲ��õ�ָ��a��b��ָ�루�βΣ���ʵ����Ҳ��ֵ���ݣ����ݵ��ǵ�ַ�����ж����ڴ��ַ�濽������a��b�ĵ�ַ�����ݵ�ַ��ԭ������С���Ӳ�������
//�β�ȷʵ�����ˣ������ⲿ��ʵ��a��bҲ�����˽���
void swap2(int *a, int *b)
{
    int t = *a;
    *a = *b;
    *b = t;
}

//C++�е����ô���(��׼C������û�����ã�C++�������ã�������һ��������һ�����������������ý��в�������ͬ��ԭ�������в���һ��)
//���ô��ݣ�����Ҫ������ڴ��ַ�����ݵ���ʵ�α������βε��ڴ��ַ��ʵ���ڴ��ַһ�����βν�����ʵ��Ҳ������
//���ƣ�����Ҫ����ռ䣬ֱ�Ӷ�ԭ������в���������Ч�ʸߣ�
//���ú�ָ��ĵ�����ָ���Ǳ����ĵ�ַ�����õı����ı�����ָ�����ָ��ĳһ����󣬶�ָ��Ķ����Ǽ�Ӳ��������õĲ����Ƕ�Ŀ�������ֱ�Ӳ�����
void swap3(int &a, int &b)  //�˴�&������ȡ��ַ���������õı�־����swap3��x�� y�������൱��a��x�����ã���a�Ĳ������Ƕ�x�Ĳ�����a��x�ڴ��ַҲһ����
{
    int t = a;
    a = b;
    b = t;
}




//��������Ԫ�ػ�����������д��
//�������ⲿ�ռ䣬����Ԫ��
void swap4(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a
}

void swap(int *a, int *b)
{
    *a = *a + *b - (*b = *a);
}



int main()
{
    int x = 1, y = 2;

    swap1(1, 2);  //ֵ���ݣ�swap�ں����β�a��b������main������a��b����Ӱ�졣
    printf("%d %d", x, y);  //������Ϊ1,2

    swap2(1, 2); //ָ�봫��
    printf("%d %d", x, y);  //������Ϊ2,1

    swap3(1, 2);  //���ô���
    printf("%d %d", x, y);  //������Ϊ2,1

    return 0;
}