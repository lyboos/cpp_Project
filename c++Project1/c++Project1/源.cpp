#define  _CRT_SECURE_NO_WARNINGS 
#include <iostream>
using namespace std;
int main()
{
    int a, b;
    char ch;
    cin >> a >> ch >> b;
    if ((ch == '+') || (ch == '-') || (ch == '*') || (ch == '/'))
    {
        switch (ch)
        {
        case '+':
            cout << a + b << endl;
            break;
        case '-':
            cout << a - b << endl;
            break;
        case '*':
            cout << a * b << endl;
            break;
        case '/':
        {
            if (b == 0) cout << "Divided by zero!" << endl;
            else cout << a / b << endl;
        }
        }
    }
    else cout << "Invalid operator!" << endl;
    return 0;
}
//#include <iostream>
//using namespace std;
//int main()
//{
//    double x, y;
//    for (;;)
//    {
//        cin >> x >> y;
//        if (x >= -1 && y >= -1 && x <= 1 && y <= 1)
//        {
//            cout << "yes" << endl;
//            break;
//        }
//        else {
//            cout << "no" << endl;
//            break;
//        }
//    }
//    return 0;
//}