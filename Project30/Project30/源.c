#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//1.输出组合数
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




//2.组合求和（不会）
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


//3.循环与递归
//在一些简单递归与循环中，循环完全可以取代递归，如strlen的实现：
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
//但是两者结构不同，分别为树状结构与环形回路，如题目1中鉴于本人能力无法使用迭代进行解题。
//由于两者本身的思路/结构不同，在转换时会存在很大的阻力。
//因此可以推测，虽然在理论上两者可以进行相互转换，但在实际操作中应该存在不小的难度。
