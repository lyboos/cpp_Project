#define  _CRT_SECURE_NO_WARNINGS 
#include <stdio.h>
#include <math.h>
//int zhishujc(int n)
//{
//	int i;
//	for (i = 2; i <= n / 2; i++)
//	{
//		if (!(n % i))
//			break;
//	}
//	if (i > n / i)
//		return 1;
//	else
//		return 0;
//}
//int main()
//{
//	int i, num;
//	int arr[5];
//	for (i = 0, num = 2; i < 5; num++)
//	{
//		if (zhishujc(num) &&zhishujc(pow(2, num) - 1))
//		{
//			arr[i] = pow(2, num) - 1;
//			i++;
//		}
//	}
//	for (i = 0; i < 5; i++)
//		printf("%d ", arr[i]);
//	return 0;
//}
//int main() {
//    int count = 0, j, M, P, k;
//    for (P = 2; count < 5; P++) {
//        for (j = 2; j <= P; j++) {
//            if (P % j == 0 && P != j)
//                break;
//            if (P == j)
//                M = pow(2, P) - 1;
//            else continue;
//            for (k = 2; k <= M; k++) {
//                if (M % k == 0 && M != k)
//                    break;
//                if (M == k) {
//                    printf("%d\n", M); 
//                    count++;
//                }
//            }
//        }
//    }
//    return 0;
//}
//int main()
//{
//	char a = 127, b = 3, c; 
//		c = a + b;
//	printf("%d\n%d\n%d%c", a, b, c,c);
//	return 0;
//}
int main()
{
	int n = 1;
	float x;
	double sum, term;
	printf("input x:");
	scanf("%f", &x);
	sum = x;
	term = x;
	do
	{
		term = -term * x * x / ((n + 1) * (n + 2));
		sum = sum + term;
		n = n + 2;
	} while (fabs(term) >= 1e-5);
	printf("sin(x)=%f\n", sum);
}
	double fact(int n)
	{
		if (n == 0)
			return 1;
		return fact(n - 1) * n;
	}
//	int main()
//	{
//		double x, sum = 0, term = 1;
//		int n = 1, t = 1;
//		scanf("%lf", &x);
//		while (term >= 1e-8) {
//			term = pow(x, 2 * n - 1) / fact(2 * n - 1);
//			sum += t * term;
//			t = -t;
//			n++;
//		}
//		printf("%.1lf", sum);
//		return 0;
//	}
//int main() {
//    double x,y,sign=-1,n=2,eps=1e-8,sum=0;
//    scanf("%lf",&x);
//    y=x;
//    while(fabs(y)>=eps){
//        sum=sum+y;
//        y=sign*y*x*x/((2*n-2)*(2*n-1));
//        n=n+1;
//    }
//    printf("%.1lf",sum);
//    return 0;
//}
////#include<stdio.h>
//int main()
//{
//	int n;
//	scanf("%d", &n);
//	for (int i = 31; i >=0; i--)
//	{
//		if (n & (1 << i))
//			printf("%d", 1);
//		else printf("%d", 0);
//	}
//	return 0;
//}
//int main()
//{
//	char a;
//	do
//	{
//		scanf("%c", &a);
//		if ((a >= 'a') && (a <= 'z'))
//			a = a - ' ';
//		printf("%c", a);
//	} while (a!='\n');
//	return 0;
//}
//int main()
//{
//	char a;
//	do {
//		scanf("%c", &a);
//		if (a != 32)
//			printf("%c", a);
//	} while (a != '\n');
//	return 0;
//}
//int main()
//{
//	int a,b;
//	scanf("%d %d", &a,&b);
//	int c = a | b;
//	int d = a & b;
//	int e = a ^ b;
//	printf("%d\n%d\n%d", c,d,e);
//	/*printf("%d\n%x\n",a,a);
//	int b=a >> 2;
//	int c = a << 2;
//	printf("%d\n%d",b,c);*/
//	return 0;
//}
//int main()
//{
//	int a,n=0;
//	scanf("%d", &a);
//	for(int b=1;b<=32;b++)
//	{
//		if ((1 & a >> b) % 2 == 1)
//			n++;
//	}
//	printf("%d", n);
//	return 0;
//}
//int main()
//{
//	int n=0, a;
//	scanf("%d", &a);
//	while (a) {
//		n++;
//		a = a & (a - 1);
//	}
//	printf("��������1�ĸ���Ϊ%d\n", n);
//	return 0;
//}
