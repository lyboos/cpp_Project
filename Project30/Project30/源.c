#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//1.��������
int count = 0;
void print(int tar[], int k)
{
	int i;
	for (i = 0; i < k; i++)
	{
		printf("%d ", tar[i]);
	}
	printf("\n");
}

void pailie(int arr[], int n, int k,int tar[],void(*print)(int* tar, int k))
{
	int i = n;
	for ( ; i >= k; i--)
	{
		tar[k - 1] = arr[i - 1];
		count++;
		if (k > 1)
		{
			pailie(arr, i - 1, k - 1,tar,print);
		}
		else
		{
			print(tar, count);
			count = 0;
		}
	}
}
int main()
{
	int n, k,i;
	scanf("%d %d", &n, &k);
	int arr[1000],tar[1000];
	for ( i = 0; i < n; i++)
	{
		arr[i] = i + 1;
	}
	pailie(arr,n,k,tar,print);
	return 0;
}




//2.�����ͣ����ᣩ
//void print(int tar[], int k)
//{
//	int i;
//	for (i = 0; i < k; i++)
//	{
//		printf("%d ", tar[i]);
//	}
//	printf("\n");
//}
//
//int add(int tar[], int k)
//{
//	int i = 0,sum=0;
//	for ( i = 0; i < k; i++)
//	{
//		sum += tar[i];
//	}
//	return sum;
//}
//
//void constit(int arr[],int tar[], int n,int sum, void(*print)(int* tar, int k), int(*add)(int tar[], int k),int len)
//{
//
//}
//
//int main()
//{
//	int n, sum,i;
//	scanf("%d %d", &n, &sum);
//	int* p = malloc(n*sizeof(int));
//	int* tar = malloc(n * sizeof(int));
//	for ( i = 0; i < n; i++)
//	{
//		scanf("%d", p+i);
//	}
//	constit(p,tar, n, sum,print,add,0);
//	return 0;
//}


//3.ѭ����ݹ�
//��һЩ�򵥵ݹ���ѭ���У�ѭ����ȫ����ȡ���ݹ飬��strlen��ʵ�֣�
int mystrlen1(const char* s)
{
	int i = 0;
	while (*(s + i) != '\0')
		i++;
	return i;
}

int mystrlen2(char* s)
{
	if (*(s + 1) == '\0')
	{
		return 1;
	}
	else
	{
		return 1 + mystrlen2(s + 1);
	}
}
//�������߽ṹ��ͬ���ֱ�Ϊ��״�ṹ�뻷�λ�·������Ŀ1�м��ڱ��������޷�ʹ�õ������н��⡣
//�������߱����˼·/�ṹ��ͬ����ת��ʱ����ںܴ��������
//��˿����Ʋ⣬��Ȼ�����������߿��Խ����໥ת��������ʵ�ʲ�����Ӧ�ô��ڲ�С���Ѷȡ�
