#define  _CRT_SECURE_NO_WARNINGS 
#include<stdio.h>

int main()
{
    printf("    竹  石    \n");
    printf("    郑  燮    \n");
    printf("              \n");
    printf("咬定青山不放松，\n");
    printf("立根原在破岩中。\n");
    printf("千磨万击还坚劲，\n");
    printf("任尔东西南北风。\n");
    return 0;
}
//#include<stdio.h>
//#include<stdlib.h>
//#include<string.h>

//char* getmem()
//{
//    static char p[] = "hello world";
//    return p;
//}
//char* getmem()
//{
//    char* p = malloc(100);
//    strcpy(p, "heello");
//    return p;
//}
//
//void test(void)
//{
//    char* str = (char*)malloc(100);
//    strcpy(str, "hello ");
//    printf(str);
//    free(str);
//    //free后继续访问，视为非法访问
////    str = NULL;
//    if (str!=NULL)
//    {
//        strcpy(str,"world");
//        printf(str);
//    }
//}
//
//int main()
//{
//    char* r = NULL;
//    r = getmem();
//    printf("%s\n",r);
//    test();
//    return 0;
//}
//


//struct peo
//{
//    char name[20];
//    int age;
//};
//
//int main()
//{
//    struct peo ly = { 0 };
//    struct peo* p = (struct peo*)malloc(sizeof(ly));
//    int* l= (int *)calloc(10, sizeof(int));//初始化为0
//    if (p == NULL || l == NULL)
//    {
//        printf("%s\n", strerror(errno));
//    }
//    int i = 0;
//    for ( i = 0; i < 6; i++)
//    {
//        *(l + i) = i;
//    }
//    realloc(l, 20);
//    for ( i = 0; i < 6; i++)
//    {
//        printf("%d\n", *(l+i));
//    }
//    free(l);
//    free(p);
//    p = NULL;
//    l = NULL;
//    return 0;
//}

//char* mystrrev(char* s)
//{
//    char* h = s;
//    char* t = s;
//    char ch;
//    while (*t++) {};
//    t--;    
//    t--;    
//    while (h < t)
//    {
//        ch = *h;
//        *h++ = *t;   
//        *t-- = ch;    
//    }
//    return(s);
//}
//
//void  myitoa(int num, char* str, int radix)
//{
//    int i = 0;
//    int sum;
//    unsigned int num1 = num;  //如果是负数求补码，必须将他的绝对值放在无符号位中在进行求反码
//    char str1[33] = { 0 };
//    if (num < 0) {              //求出负数的补码
//        num = -num;
//        num1 = ~num;
//        num1 += 1;
//    }
//    if (num == 0) {
//        str1[i] = '0';
//
//        i++;
//    }
//    while (num1 != 0) {                      //进行进制运算
//        sum = num1 % radix;
//        str1[i] = (sum > 9) ? (sum - 10) + 'a' : sum + '0';
//        num1 = num1 / radix;
//        i++;
//    }
//    i--;
//    int j = 0;
//    for (i; i >= 0; i--) {               //逆序输出 
//        str[i] = str1[j];
//        j++;
//    }
//
//}
//
//void calculate_mul(char* mul_1, char* mul_2, char* result)
//{
//    int i, j, k = 0, off = -1, r = 0;
//    int temp0;
//    for (i = strlen(mul_2) - 1; i >= 0; i--)
//    {
//        r = 0;
//        off++;
//        k = 0;
//        for (j = strlen(mul_1) - 1; j >= 0; j--)
//        {
//            if (result[k + off] == 0)
//            {
//                result[k + off] = ((mul_1[j] - '0') * (mul_2[i] - '0') + r) % 10 + '0';
//                r = ((mul_1[j] - '0') * (mul_2[i] - '0') + r) / 10;
//            }
//            else
//            {
//                temp0 = result[k + off] - '0';
//                result[k + off] = (result[k + off] - '0' + (mul_1[j] - '0') * (mul_2[i] - '0') + r) % 10 + '0';
//                r = (temp0 + (mul_1[j] - '0') * (mul_2[i] - '0') + r) / 10;
//            }
//            k++;
//        }
//        if (r != 0)
//        {
//            result[k + off] = '0' + r;
//        }
//    }
//    mystrrev(result);
//}
//
//void nn(char* str_nn)
//{
//    int i, n;
//    char r[3000] = "1";
//    char tmp[3000] = "1";
//    char tmp2[3000] = "1";
//    n = atoi(str_nn);
//    for (i = 1; i <= n; i++)
//    {
//        memset(tmp, 0, sizeof(tmp));
//        strcpy(tmp, r);
//        memset(r, 0, sizeof(r));
//        memset(tmp2, 0, sizeof(tmp2));
//        myitoa(i, tmp2, 10);
//        calculate_mul(tmp, tmp2, r);
//    }
//    printf("%s\n", r);
//}
//
//int main()
//{
//    char str_n[10] = { 0 };
//    scanf("%s", &str_n);
//    nn(str_n);
//    return 0;
//}


//int mian()
//{
//    int i,n, a[100];
//    char b[100][100];
//    char c[100];
//    scanf("%d", &n);
//    for ( i = 0; i < n; i++)
//    {
//        scanf("%d",&a[i]);
//    }
//    for ( i = 0; i < n; i++)
//    {
//        itoa(a[i],b[i],10);
//    }
//    for ( i = 0; i < n; i++)
//    {
//        
//    }
//    return 0;
//}


/*int main()
{
    int n, a[101], all = 0, ans = 0, i;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
        scanf("%d", &a[i]), all += a[i];
    all /= n;
    for (i = 0; i < n; i++)
        if ((a[i] - all) != 0)
            a[i + 1] += a[i] - all, ans++;
    printf("%d", ans);
    return 0;
}*/
