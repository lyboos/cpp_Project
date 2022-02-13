#define  _CRT_SECURE_NO_WARNINGS 
#define _CRT_NONSTDC_NO_DEPRECATE
#include<stdio.h>
#include<string.h>

int fun(int n)
{
	int i = 1;
	while (n)
	{
		i = i * n;
		n--;
	}
	return i;
}

int trans(int arr[], int n, int d)
{
	int i, j,k,count=0,tem;
	for (i = 1; i <n; i++)
	{
		for (j=n-1,k=i;k>0;k--)
		{
			count++;
			tem = arr[j];
			arr[j] = arr[j - k];
			arr[j - k] = tem;
			if (count == d)
				return 0;
		}
	}
}
int main()
{
	int a, b, c;
	scanf("%d",&a);
	scanf("%d", &b);
	int arr[1000] = { 0 };
	for ( c = 0; c < a; c++)
	{
		scanf("%d", &arr[c]);
	}
	trans(arr, a, b-1);
	for (c = 0; c < a; c++)
	{
		printf("%d ", arr[c]);
	}
	return 0;
}
////int fun(int n)
////{
////	if (n <= 1) return n;
////	else return n * fun(n-1);
////}
//
////void Permutation(int m, int n, int a[])
////{
////    int i, temp;
////    //递归到底层
////    if (m == n - 1)
////    {
////        for (i = 0; i < n - 1; i++)
////            printf("%d ", a[i]);
////        printf("%d\n", a[i]);
////    }
////    else
////    {
////        for (i = m; i < n; i++)
////        {
////            temp = a[m];
////            a[m] = a[i];
////            a[i] = temp;
////            //递归到下一层
////            Permutation(m + 1, n, a);
////            //保证递归后保持上一层的顺序
////            temp = a[m];
////            a[m] = a[i];
////            a[i] = temp;
////        }
////    }
////}
//void swap(int* p1, int* p2)
//{
//	int t = *p1;
//	*p1 = *p2;
//	*p2 = t;
//}
//
//void permutation(int a[], int index, int size)
//{
//	if (index == size)
//	{
//		for (int i = 0; i < size; i++)
//			printf("%d ", a[i]);
//	}
//	else
//	{
//		for (int j = index; j < size; j++)
//		{
//			swap(&a[j], &a[index]);
//			permutation(a, index + 1, size);//此处用到递归思想
//			swap(&a[j], &a[index]);
//		}
//
//	}
//}
//int main()
//{
//	int a, b,c;
//	scanf("%d", &a);
//	scanf("%d", &c);
//	int arr[120];
//	for ( b = 0; b <a; b++)
//	{
//		scanf("%d",&arr[b]);
//	}
//    permutation(arr,c,a);
//	return 0;
//}
//int del(char* a, char* b)
//{
//	int i = 0,j,flag=0;
//	while (*a!='\0')
//	{
//		if (*(a + i) == *(b + 2))
//		{
//			flag = 1;
//			break;
//		}
//		i++;
//	}
//	if(flag)
//	for ( j = i; j <strlen(a) ; j++)
//	{
//		*(a + j) = *(a + j + 1);
//	}
//	return flag;
//}
//
//int ins(char* a, char* b)
//{
//	int i=0, j = 0,flag=0;
//	int tem = strlen(a);
//	for ( j = tem-1; j >=0; j++)
//	{
//		if (*(a + j) == *(b + 2))
//		{
//			flag = 1;
//			break;
//		}
//	}
//	if (flag)
//	{
//		*(a + tem + 1) = '\0';
//		*(a + tem) = *(a + tem - 1);
//		for (i = tem - 1; i > j; i++)
//		{
//			*(a + i) = *(a + i - 1);
//		}
//		*(a + j) = *(b + 4);
//	}
//	return flag;
//}
//
//int rep(char* a, char* b)
//{
//	int i = strlen(a),j=0, flag=0;
//	int arr[101] = {0};
//	while (*(a+j)!='\0')
//	{
//		if (*(a + j) == *(b + 2))
//		{
//			flag = 1;
//			arr[j] = -1;
//		}
//		j++;
//	}
//	if(flag)
//	for ( j = 0; j < i; j++)
//	{
//		if (arr[j]==-1)
//			*(a + j) = *(b+4);
//	}
//	return flag;
//}
//int main()
//{
//	int check = 0;
//	char a[101],b[10];
//	gets(a);
//	gets(b);
//	if (*b == 'D') check=del(a, b);
//	if (*b == 'I') check = ins(a, b);
//	if (*b == 'R')  check = rep(a, b);
//	if (check)
//		printf("%s", a);
//	else
//		printf("Not exist");
//	return 0;
//}
//char* my_itoa(int num, char* str, int radix)
//
//{
//	const char table[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
//	char* ptr = str;
//	bool negative = false;
//	if (num == 0) {   //num=0
//		*ptr++ = '0';
//		*ptr = '\0';                // don`t forget the end of the string is '\0'!!!!!!!!!
//		return str;
//	}
//	if (num < 0) {               //if num is negative ,the add '-'and change num to positive
//		*ptr++ = '-';
//		num *= -1;
//		negative = true;
//	}
//	while (num) {
//		*ptr++ = table[num % radix];
//		num /= radix;
//	}
//	*ptr = '\0';            //if num is negative ,the add '-'and change num to positive
//	// in the below, we have to converse the string
//	char* start = (negative ? str + 1 : str); //now start points the head of the string
//	ptr--;                           //now prt points the end of the string
//	while (start < ptr) {
//		char temp = *start;
//		*start = *ptr;
//		*ptr = temp;
//		start++;
//		ptr--;
//	}
//	return str;
//}
//int more(int before, char num[])
//
//{
//	int i = 0;
//	double result = 0.0;
//	int length = strlen(num);
//	for (i = length - 1; i >= 0; i--)
//	{
//		if ('A' <= num[i] && num[i] <= 'Z')
//			result += pow(before, length - i - 1) * (num[i] - 55);
//		else if ('a' <= num[i] && num[i] <= 'z')
//			result += pow(before, length - i - 1) * (num[i] - 87);
//		else if ('0' <= num[i] && num[i] <= '9')
//			result += pow(before, length - i - 1) * (num[i] - 48);
//	}
//	return (int)result;
//}
//
//int less(int before, int num) 
//{
//	double result = 0.0;
//	int i = 0;
//	for (i = 0; num != 0; i++) 
//	{
//		result += pow(before, i) * (num % 10);
//		num /= 10;
//	}
//	return (int)result; 
//}
//char* fan(char* a)
//{
//	char tem;
//	char* b = a;
//	int i = 0,j=strlen(b);
//	for ( i = 0; i < j/2; i++)
//	{
//		tem = b[i];
//		b[i] = b[j - i - 1];
//		b[j - i - 1] = tem;
//	}
//	return b;
//}
//
//int ishui(char* a)
//{
//	int i =0,j=strlen(a);
//	for ( i = 0; i <j/2; i++)
//	{
//		if (a[i] != a[j - i - 1])
//			return 1;
//	}
//	return 0;
//}
//
//int change(int *m, int n)
//{
//	int count = 0,x,y,z;
//	char a[11],b[11];
//	itoa(*m,a,n);
//	while (ishui(a)!=0)
//	{
//		strcpy(b,a);
//        fan(b);
//		if (n <= 10)
//		{
//			x =less(n,atoi(a));
//			y =less(n,atoi(b));
//		}
//		else
//		{
//			x = more(n, a);
//			y = more(n, b);
//		}
//		z = x + y;
//		itoa(z, a, n);
//		count++;
//	}
//	return count;
//}
//int main()
//{
//	int n, m, k = 0;
//	scanf("%d", &n);
//	if (n == 16)
//		scanf("%x", &m);
//	else
//	{
//		scanf("%d", &m);
//		m = less(n, m);
//	}
//	k=change(&m,n);
//	if (k < 30&&k>0) printf("STEP=%d", k);
//	else printf("Impossible!");
//	return 0;
//}

//long add(char* a, char* b, char* s)
//{
//	int count = 0;
//
//	return 0;
//}
//
//int main()
//{
//	long a, b = 0,flag=0;
//	char al[11], bl[11],result[11];
//	scanf("%ld %ld", &a, &b);
//	itoa(a,al,10);
//	itoa(b, bl, 10);
//	add(al, bl,result);
//	printf("%s", result);
//	return 0;
//}
//int select(int group[],int delete[],int k, int w,int n)
//{
//	int counter = 0;
//	while (1)
//	{
//		while(group[k] == 0)
//			k++;
//		while (group[n-w-1] == 0)
//			w--;
//		if (group[k] !=group[n - w - 1])
//		{
//			delete[counter]=group[k];
//			group[k] = 0;
//			counter++;
//			delete[counter]=group[n - w - 1];
//			group[n - w - 1] = 0;
//			counter++;
//		}
//		else
//		{
//			group[counter] = k;
//			return counter+1;
//		}
//	}
//	return 0;
//}
//
//int main()
//{
//	int group[3000] = { 0 };
//	int delete[3000] = { 0 };
//	int n, k, w;
//	int i;
//	scanf("%d", &n);
//	scanf("%d %d", &k, &w);
//	k--; w--;
//	for ( i = 0; i < n; i++)
//	{
//		group[i] = i+1;
//	}
//	int l = select(group, delete, k, w, n);
//	free(group);
//	for(i=0;i<l;i++)
//	printf("%d ",delete[i]);
//	return 0;
//}