#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include<string.h>
void reverse(char* a)
{
	int len = strlen(a);
	char* r = a + len - 1;
		char* l = a;
	while (l<r)
	{
		char change = *l;
		*r = *l;
		*l = change;
		r--;
		l++;
	}
}

int main()
{
	char a[100] = { 0 };
	scanf("%s", a);
	reverse(a);
	printf("%s", a);
	return 0;
}








//#include <stdio.h>
//
//void  line_sort(int a[][4], int b[], int n)
//{
//    int i, j,c=n;
//    for ( i = 0; i <n; i++)
//    {
//        for ( j = 0; j < 4; j++)
//        {
//            b[i] =b[i]+ a[i][j];
//        }
//    }
//    while (c) {
//        c--;
//        for (i = 0; i < n - 1; i++)
//        {
//            if (b[i] > b[i + 1])
//            {
//                b[i] = b[i] ^ b[i + 1];
//                b[1 + i] = b[i] ^ b[1 + i];
//                b[i] = b[i] ^ b[1 + i];
//                for (j = 0; j < 4; j++)
//                {
//                    a[i][j] = a[i][j] ^ a[i + 1][j];
//                    a[i + 1][j] = a[i][j] ^ a[i + 1][j];
//                    a[i][j] = a[i][j] ^ a[i + 1][j];
//                }
//            }
//        }
//    }
//}
//int main() {
//    int a[5][4] = { 0 }, b[5] = { 0 }, i, j;
//    for (i = 0; i < 5; i++)
//        for (j = 0; j < 4; j++)
//            scanf("%d", &a[i][j]);
//    line_sort(a, b, 5);
//    for (i = 0; i < 5; i++) {
//        for (j = 0; j < 4; j++)
//            printf("%d ", a[i][j]);
//        printf("\n");
//    }
//    printf("sum\n");
//    for (i = 0; i < 5; i++)
//        printf("%d ", b[i]);
//    printf("\n");
//    return 0;
//}
//void  line_sort(int a[][4], int b[], int n) {
//    int i, j, point, g, d;
//    for (i = 0; i < n; i++)
//        for (j = 0; j < 4; j++)
//            b[i] += a[i][j];
//    for (i = 0; i < n; i++) {
//        point = i;
//        for (j = 1; j < n; j++) {
//            if (b[point] > b[j])
//                point = j;
//        }
//        if (point != i) {
//            g = b[point];
//            b[point] = b[i];
//            b[i] = g;
//            for (d = 0; d < 4; d++) {
//                g = a[point][d];
//                a[point][g] = a[i][g];
//                a[i][g] = a[point][g];
//            }
//        }
//    }
//}

//void count(char a[], char w[][10], int n, int b[])
//{
//
//}
//
//int main()
//{
//	char w[][]
//	return 0;
//}
//#include <stdio.h>
//#include <string.h>
//
//void count(char a[], char w[][10], int n, int b[]) {
//    int count = 0, num = 0, j;
//    char* ptr = a;
//    for (j = 0; j < n; j++) {
//        while (*ptr) {
//            if (strncmp(ptr, w[j], strlen(w[j])) == 0) {
//                count++;
//                ptr += strlen(w[j]);
//            }
//            else
//                ptr++;
//        }
//        b[num] = count;
//        num++;
//        count = 0;
//        ptr -= strlen(a);
//    }
//}
//
//int main() {
//    char a[100] = { 0 }, w[10][10] = { 0}, n = 2, b[100] = { 0 };
//    int i, j = -1;
//    gets(a);
//    for (i = 0; i < n; i++)
//    {
//        while ((a[j] != ' ') && (a[j] != '\0'))
//        {
//            j++;
//            w[i][j] = a[j];
//            j = strlen(a + j);
//        }
//        count(a, w, n, b);
//    }
//    for (i = 0, j = 0; i < 2; i++) {
//        printf("%s:%d", a, b[i]);
//        for (; a[j - 1] != '\0';)
//            j++;
//    }
//    return 0;
//}


//
////int main() {
////    void  line_sort(int a[][4], int b[], int n);
////    int a[5][4] = { 0 }, b[5] = { 0 }, i, j;
////    for (i = 0; i < 5; i++)
////    {
////        for (j = 0; j < 4; j++)
////        {
////            scanf("%d", &a[i][j]);
////        }
////    }
////    line_sort(a, b, 5);
////    for (i = 0; i < 5; i++, printf("\n"))
////        for (j = 0; j < 5; j++)
////            printf("%d ", a[5][4]);
////    printf("sum\n");
////    for (i = 0; i < 5; i++)
////        printf("%d", b[i]);
////    return 0;
////}
////void  line_sort(int a[][4], int b[], int n) {
////    int i, j, point, g, d;
////    for (i = 0; i < n; i++)
////        for (j = 0; j < 4; j++)
////            b[i] += a[i][j];
////    for (i = 0; i < n; i++) {
////        point = i;
////        for (j = 1; j < n; j++) {
////            if (b[point] > b[j])
////                point = j;
////        }
////        if (point != i) {
////            g = b[point];
////            b[point] = b[i];
////            b[i] = g;
////        }
////        for (d = 0; d < 4; d++) {
////            g = a[point][d];
////            a[point][g] = a[i][g];
////            a[i][g] = a[point][g];
////        }
////    }
////}
//#include<stdio.h>
//#include<string.h>
//void count(char a[], char w[][10], int n, int b[])
//{
//	int count = 0,i;
//	a = w[n - 1];
//	for ( i = 0; i <100 ; i++)
//	{
//		if (strcmp(a,w[i])==0)
//		{
//			count++;
//		}
//	}
//	b[n - 1] = count;
//}
//int main()
//{
//	int b[2] = { 0 };
//	char a[] = { 0};
//	char w[100][10] = { 0 };
//	int i = 0;
//	do
//	{
//		scanf("%s", w[i]);
//		i++;
//	} while (getchar()!='\n');
//	count(a, w, 1, b);
//	count(a,w,2,b);
//	printf("%s:%d ", w[0], b[0]);
//	printf("%s:%d", w[1],b[1]);
//	return 0;
//}