#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
//int main()
//{
//	int A = 0; int B = 0;
//    scanf("%d\n",&A);
//	scanf("%d",&B);
//	if (A > B) printf("\n�ϴ�ֵ��%d", A)
//		; else if (B > A) printf("\n�ϴ�ֵ��%d", B)
//		; else if (A = B) printf("\nEQUAL");
//		else printf("\nERROR");
//	return 0;
//}
//int main()
//{
//	int a = 10
//		; int b = a++;
//	printf("%d\n%d", a, b);
//	return 0;
//}
//int main()
//{
//	int A = 0; int B = 0; int DATA = 0;
//	scanf("%d\n", &A);
//	scanf("%d", &B);
//	DATA = (A > B ? A : B);
//	printf("\n�ϴ�ֵ��%d", DATA);
//		return 0;
//}
#define ABC(X,Y) (X>Y?Y:X)
int main()
{
	int a,b; a = 0; b = 0;
	scanf("%d\n", &a);
	scanf("%d", &b);
	int X = ABC(a, b);
	printf("��Сֵ��%d", X);
	int* p=&X;
	printf("\n%p", p);
	printf("\n%d", sizeof p);
	return 0;
}