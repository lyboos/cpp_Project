#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>
#include<stdlib.h>
#include<errno.h>
#include<math.h>
#include<string.h>
int main()
{
	FILE* pf = fopen("test.txt", "r");
	if (pf == NULL)
	{
		printf("%s\n", strerror(errno));
	}
	else
	{
		fseek(pf, 1,SEEK_CUR);
		char ly = fgetc(pf);
		printf("%c", ly);
		rewind(pf);
	    ly = fgetc(pf);
		printf("%c", ly);
	}
	fclose(pf);
	pf == NULL;
	return 0;
}
//int main()
//{
//	double flag = 1, pi = 0, item = 1;
//	int demo = 1;
//	while (fabs(item) >= 0.0001)
//	{
//		pi += item;
//		flag = -flag;
//		demo += 2;
//		item = flag * 1.0 / demo;
//	}
//	pi += item;
//	pi = pi * 4;
//	printf("%lf", pi);
//	return 0;
//}
//int main()
//{
//	double flag = 1,pi=0,item=1;
//	int demo = 1;
//	while (fabs(item)>=0.0001)
//	{
//		item = flag * 1.0 / demo;
//		pi += item;
//		flag = -flag;
//		demo += 2;
//	}
//	pi = pi * 4;
//	printf("%lf", pi);
//	return 0;
//}
//typedef struct S {
//	char name[20];
//	int age;
//	int level;
//}S;
//
//int main()
//{
//	/*S man = { "lyboos",45,12 };
//	FILE* pf = fopen("test.txt","wb");
//	fwrite(&man,sizeof(man),1,pf);*/
//	S man = { 0 };
//	FILE* pf = fopen("test.txt","r");
//	fread(&man, sizeof(S), 1, pf);
//	printf("%s,%d,%d",man.name,man.age,man.level);
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//int main()
//{
//	int ch = fgetc(stdin);
//	fputc(ch,stdout);
//	//FILE* ps=fopen("test.doc", "r");
//	//fclose(ps);
//	//ps = NULL;
//	////FILE* ly = fopen("C:\\Users\\ASUS\\Desktop\\¿Î±í.xlsx","r");
//	//FILE* ly = fopen("..//text.txt", "w");
//	//if (ly == NULL)
//	//	printf("%s\n",strerror(errno));
//	//else {
//	//	printf("%p\n", ly);
//	//	printf("%s\n",puts("lyboos\n",ly));
//	//	fputs("modoka\tly", ly);
//	//	fclose(ly);
//	//}
//	//ly = NULL;
//	return 0;
//}
//int main()
//{
//	int i = 1, j = 2, k = 3;
//	if (i++ == j && k-- == j)
//		printf("%d,%d,%d", i++, j, k);
//	else
//		printf("%d,%d,%d", ++i, ++j, k--);
//	return 0;
//}
//int main()
//{
//	int a = 10000;
//	FILE* pf = fopen("test.txt", "wb");
//	fwrite(&a, 4, 1,pf);
//	;
//	fclose(pf);
//	pf = NULL;
//	return 0;
//}
//typedef struct S {
//	int a;
//	int* arr;
//}S;
//
//int main()
//{
//	int n,i;
//	scanf("%d", &n);
//	S* ps = malloc(sizeof(struct S));
//	ps->arr = (int*)malloc(sizeof(int) * n);
//	for ( i = 0; i < n; i++)
//	{
//		scanf("%d",ps->arr+i);
//	}
//	for ( i = 0; i < n; i++)
//	{
//		printf("%d ", ps->arr[i]);
//	}
//	free(ps->arr);
//	free(ps);
//	ps->arr = NULL;
//	ps = NULL;
//	return 0;
//}
//struct B
//{
//	int b;
//	int* p;
//};
//int main()
//{
//	int n;
//	struct B* test = malloc(sizeof(struct B));
//	test->p = malloc(10 * sizeof(int));
//	scanf("%d", &n);
//	int* ptr = realloc(test->p,n*sizeof(int));
//	if (ptr != NULL)
//	{
//		test->p = ptr;
//	}
//	/*scanf("%d", &n);	
//	struct S* ps = malloc(sizeof(struct S) + n * sizeof(int));
//	printf("%d\n", sizeof(ps));
//	free(ps);
//	ps = NULL;*/
//	free(test);
//	test = NULL;
//	free(ptr);
//	ptr = NULL;
//	return 0;
//}