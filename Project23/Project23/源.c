#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<string.h>
#include<assert.h>
#include<math.h>

//囚犯真假问题
//典中典
int main()
{
	int killer = 0;
	for ( killer = 'a'; killer <='d'; killer++)
	{
		if ((killer != 'a') + (killer == 'c') + (killer == 'd') + (killer != 'd')==3)
			printf("%c", killer);
	}
	return 0;
}

//int main()
//{
//	int arr[10][10] = { 0 };
//	int i,j;
//	for ( i = 0; i < 10; i++)
//	{
//		for ( j = 0; j <=i; j++)
//		{
//			if (j==0||j==i)
//			arr[i][j] = 1;
//			if (j >= 1 && i >= 2)
//				arr[i][j] = arr[i - 1][j-1] + arr[i - 1][j ];
//		}
//	}
//	for ( i = 0; i < 10; i++)
//	{
//		for (j = 0; j <=i; j++)
//		{
//			printf("%d ", arr[i][j]);
//		}
//		printf("\n");
//	}
//	return 0;
//}





//void change(int* p,int n)
//{
//	int l = 0;
//	int r = n - 1;
//	while (l < r)
//	{
//		while (*(p + l) % 2 == 1)
//		{
//			l++;
//		}
//		while (*(p + r) % 2 == 0)
//		{
//			r--;
//		}
//		if (l < r)
//		{
//			*(p + l) = *(p + r) ^ *(p + l);
//			*(p + r) = *(p + r) ^ *(p + l);
//			*(p + l) = *(p + r) ^ *(p + l);
//		}
//	}
//}
//
//int main()
//{
//	int arr[10] = { 1,2,3,4,5,6,7,8,9,0 };
//	change(arr,sizeof(arr)/sizeof(arr[0]));
//	int i;
//	for(i=0;i<10;i++)
//	printf("%d", arr[i]);
//	return 0;
//}
////int cola(int n)
////{
//	if (n == 0) return 0;
//	return n + cola(n / 2);
//}

/*nt main()
{
	int n,empty=0,sum=0;
	scanf("%d", &n);
	empty += n;
	sum += n;
	while (empty>=2)
	{
		sum += empty / 2;
		empty = empty / 2 + empty % 2;
	}
	printf("%d", sum);
	return 0;
}*/
//int main()
//{
//	int line;
//	scanf("%d", &line);
//	int i = 0, j = 0;
//	for ( i = 1; i<=line; i++)
//	{
//		for (j = 0; j < line - i; j++)
//		{
//			printf(" ");
//		}
//		for ( j = 0; j < 2*i-1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	for ( i = 1; i < line; i++)
//	{
//		for (j = 0; j < i; j++)
//		{
//			printf(" ");
//		}
//		for ( j = 0; j < 2*(line-i)-1; j++)
//		{
//			printf("*");
//		}
//		printf("\n");
//	}
//	return 0;
//}



//int main()
//{
//	int a, n=1,sum=0;
//	scanf("%d", &a);
//	int i = a;
//	while (i/=10)
//	{
//		n++;
//	}
//	i = a;
//	int ret = n;
//	for (ret=n;ret>0;ret--)
//	{
//		sum += (int)pow(i%10,n);
//		i /= 10;
//	}
//	if (a==sum)
//		printf("T");
//	else printf("F");
//	return 0;
//}





//void reverse(char* a)
//{
//	assert(a);
//	int len = strlen(a);
//	char* r = a + len - 1;
//	char* l = a;
//	while (l < r)
//	{
//		char change = *r;
//		*r = *l;
//		*l = change;
//		r--;
//		l++;
//	}
//}
//
//int main()
//{
//	char a[100] = { 0 };
////	scanf("%s", a);
//   gets(a);
//	reverse(a);
//	printf("%s", a);
//	return 0;
//}
//long int plusplus(int a, int n)
//{
//	int i = 0, sum = 0,ret=0;
//	for ( i = 0; i <n; i++)
//	{
//		ret = ret*10 + a;
//		sum += ret;
//	}
//	return sum;
//}
//
//int main()
//{
//	int a, n;
//	scanf("%d %d",&a, &n);
//	printf("%ld",plusplus(a, n));
//	return 0;
//}
//#include<math.h>
//int count(int n)
//{
//	int i = 0;
//	while (n/10)
//	{
//		n = n / 10;
//		i++;
//	}
//	return i;
//}
////int detect(int a, int n)
////{
////	int i = 0,sum=0;
////	for ( i = n; i >0; i--)
////	{
////		sum += pow(a / pow(10, n - 1), n);
////	}
////	return (a ==sum?1: 0);
////}
//int main()
//{
//	int a;
//	scanf("%d", &a);
//	int n = count(a);
//	if (detect(a, n) == 1)
//		printf("T");
//	else printf("F");
//	return 0;
//}

//#include <stdio.h>
//#include <string.h>
//int main() {
//    char c[100] = { '\0' }, w[10][10] = { '\0' };
//    int a[100] = { 0 }, i, j, k = 0, max = 0;
//    gets(c);
//    for (i = 0; i < 10; i++, k++)
//        for (j = 0; j < 10; j++) {
//            if (c[k] >= 65 && c[k] <= 90 || c[k] >= 97 && c[k] <= 122)
//                w[i][j] = c[k++];
//            else {
//                if (w[i][0] == '\0')
//                    i--;
//                break;
//            }
//        }
//    for (i = 0; i < 10; i++) {
//        if (strlen(w[i]) > max) {
//            max = strlen(w[i]);
//            k = i;
//        }
//    }
//    puts(w[k]);
//    return 0;
//}