#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>

int main()
{
	int arr[3][4] = { {0,1} };
	//printf("%d\n", sizeof(arr));//48
	//printf("%d\n", sizeof(arr[0]));//16
	//printf("%d\n", sizeof(arr[0][1]));//4
	//printf("%d\n", sizeof(arr[0]+1));//4
	//printf("%d\n", sizeof(*(arr[0]+1)));//4
	/*printf("%d\n", sizeof(arr+1));
	printf("%d\n", sizeof(*(arr+1)));*/
	/*int* p;
	p = arr[0];
	printf("%d", p[0]);*/
	int a[5][5];
	int(*p)[4];
	p = a;
	printf("%p\n%d", &p[4][2] - &a[4][2], &p[4][2] - &a[4][2]);
	return 0;
}
//void bubblesort(int a[], int n)
//{
//    int i,j,t;
//    for (i = 0; i < n - 1; i++) {
//        for (j = i + 1; j < n; j++) {
//            if (a[i] > a[j]) {
//                t = a[i];
//                a[i] = a[j];
//                a[j] = t;
//            }
//        }
//    }
//}
//int main()
//{
//    int i, j,x;
//    int n = 0;
//    int arr[100];
//    int checkarr[1000] = { 0 };
//    while (scanf("%d",&n)!=EOF)
//    {
//        for ( i = 0,j=0; i <n; i++)
//        {
//            scanf("%d", &x);
//            if (checkarr[x]==0)
//            {
//                arr[j++] = x;
//                checkarr[x] = 1;
//            }
//        }
//        bubblesort(arr, j);
//        printf("%d\n", j);
//            for (i=0; i < j-1; i++)
//            {
//                printf("%d ", arr[i]);
//        }
//            printf("%d\n", arr[i]);
//    }
//    return 0;
//}
//int main() {
//    int a[101] = { 0 }, n, x, i=0, k;
//        scanf("%d%d", &n, &x);
//        int flag = 1;
//        while (flag)
//        {
//            scanf("%d",a + i);
//            if (*(a + i) == 0&&*(a+i-1)==0)
//                flag--;
//            i++;
//       }
//        for (i = 0; i < n - 1; i++) {
//            if (x < a[0]) {
//                for (k = n; k > 0; k--)
//                    a[k] = a[k - 1];
//                a[0] = x;
//                break;
//            }
//            if (x > a[n - 1]) {
//                a[n] = x;
//                break;
//            }
//            if (a[i] <= x && a[i + 1] >= x) {
//                for (k = n; k > i + 1; k--) {
//                    a[k] = a[k - 1];
//                }
//                a[i + 1] = x;
//                break;
//            }
//        }
//        for (i = 0; i < n + 1; i++)
//            printf("%d ", *(a + i));
//        printf("\n");
//    
//    return 0;
//}

//int main()
//{
//	int n, x;
//	do
//	{
//		scanf("%d %d", &n, &x);
//		if (n == 0 && x == 0)
//			break;
//		if (n > 100)
//		{
//			printf("ERROR!\n");
//			break;
//		}
//		int i = 0;
//		for ( i = 0; i < n; i++)
//		{
//			scanf("%d",&arr[i])
//		}
//	} while (1);
//}
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>
//int count = 0;
//int(*allarr[99])[101];
//int num = 0;
//void arrstore(int (*arr)[101])
//{
//	allarr[num] = arr;
//	num++;
//}
//void print(int (*arr)[101])
//{
//	int n = strlen(arr);
//	int i = 0;
//	for (i = 0; i < n; i++)
//	{
//		printf("%d ", *arr[i]);
//	}
//	printf("\n");
//}
//void arrprint()
//{
//	int i = 0;
//	for ( i = 0; i < num; i++)
//		print(allarr[i]);
//}
//
//int cmp(const void* p1, const void* p2)
//{
//	return *(int*)p1 - *(int*)p2;
//}
//int main()
//{
//	int n, x, i;
//	while (scanf("%d%d", &n, &x) != EOF)
//	{
//		int arr[101];
//		if (x == 0 && n == 0)break;
//		arr[n] = 0;
//		for (i = 0; i < n; i++)
//			scanf("%d", &arr[i]);
//		arr[n] = x;
//		qsort(arr, n + 1, sizeof(arr[0]), cmp);
//		arrstore(&arr);
//		count++;
//	}
//	arrprint();
//	return 0;
//}

//#define  _CRT_SECURE_NO_WARNINGS 
//#include<stdio.h>
//
//void intersection(int* pa, int* pb, int a, int b)
//{
//	int i = 0, j = 0;
//	int arr[200] = { 0 };
//	for (i = 0; i <= b; i++)
//	{
//		for (j = 0; j <= a; j++)
//		{
//			if (*(pb + i) == *(pa + j))
//			{
//				if (arr[*(pb + i)] == 1) continue;
//				printf("%d ", *(pb + i));
//				arr[*(pb + i)] = 1;
//			}
//		}
//	}
//}
//
//int main()
//{
//	int a[100] = { 0 };
//	int b[100] = { 0 };
//	int i = 0, j = 0;
//	do {
//		scanf("%d", &a[i]);
//		i++;
//	} while (getchar() != '\n');
//	do {
//		scanf("%d", &b[j]);
//		j++;
//	} while (getchar() != '\n');
//	intersection(a, b, i - 1, j - 1);
//	return 0;
//}
