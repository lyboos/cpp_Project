#define  _CRT_SECURE_NO_WARNINGS 
#include<iostream>
#include<limits>
#include <sstream>
#include<stdlib.h>

using namespace std;

int main() {
    string pszSource;
    char temp;
    while (cin.get(temp)) {
        pszSource = pszSource + temp;
    }
    string output;
    int nByteSrc = pszSource.size();
    const char* enkey = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz0123456789+/";
    std::string pszEncode(nByteSrc * 4 / 3 + 4, '\0');
    int nLoop = nByteSrc % 3 == 0 ? nByteSrc : nByteSrc - 3;
    int n = 0;
    int i = 0;
    for ( i = 0; i < nLoop; i += 3)
    {
           pszEncode[n] = enkey[pszSource[i] >> 2];
               pszEncode[n + 1] = enkey[((pszSource[i] & 3) << 4) | ((pszSource[i + 1] & 0xF0) >> 4)];
                pszEncode[n + 2] = enkey[((pszSource[i + 1] & 0x0f) << 2) | ((pszSource[i + 2] & 0xc0) >> 6)];
                 pszEncode[n + 3] = enkey[pszSource[i + 2] & 0x3F];
              n += 4;
    }
   
    switch (nByteSrc % 3)
    {
            case 0:
                     pszEncode[n] = '\0';
                     break;
            
             case 1:
                     pszEncode[n] = enkey[pszSource[i] >> 2];
                     pszEncode[n + 1] = enkey[((pszSource[i] & 3) << 4) | ((0 & 0xf0) >> 4)];
                     pszEncode[n + 2] = '=';
                   pszEncode[n + 3] = '=';
                    pszEncode[n + 4] = '\0';
                     break;
            
             case 2:
                     pszEncode[n] = enkey[pszSource[i] >> 2];
                     pszEncode[n + 1] = enkey[((pszSource[i] & 3) << 4) | ((pszSource[i + 1] & 0xf0) >> 4)];
                   pszEncode[n + 2] = enkey[((pszSource[i + 1] & 0xf) << 2) | ((0 & 0xc0) >> 6)];
                     pszEncode[n + 3] = '=';
                     pszEncode[n + 4] = '\0';
                     break;
                 }
    
       cout<<pszEncode;
   
    return 0;
}
    string output;
    /*string input;
    char temp;
    int num = 0, line = 0;
    while (cin.get(temp)) {
        input = input + temp;
    }
    int flag = 0;
    for (int i = 0; i < input.size(); i++)
    {
        switch (input.at(i))
        {
        case ' ':
            if (flag == 1) num++;
            flag = 0;
            break;
        case '\n':
            if (flag == 1) num++;
            flag = 0;
            line++;
            break;
        default:
            flag = 1;
            break;
        }
    }
    if (input.size() == 0) num = 0, line = 0;
    cout << input.size() << ' ' << num << ' ' << line;*/
    
/*int n;
    cin >> n;
    cin >> ws;
    string* dict=new string[5000];
    char* tmp = new char[100];
    int f = 0, m = 0;
    for (int i = 0; i < n; i++)
    {
        cin.getline(tmp, 100);
        int num = atoi(tmp);
        char* gender1 = strstr(tmp," ");
        char gender = *(gender1 + 1);
        if (gender == 'f') {
            f += num;
        }
        else if (gender == 'm') {
            m += num;
        }
    }
    cout << "f: " << f << endl;
    cout << "m: " << m << endl;*/
    /*int num = 0;
    int line = 0;
    int words = 0;
    string* dict[5000];
    int i = 0;
    while (cin.get()!='\n') {
        dict[i] = new string();
        getline(cin, *dict[i]);
        cout << *dict[i];
        i++;
    }*/
    /*int n = 0, count = 0;
    int tmp;
    int arr[10000];
    while (cin >> tmp) {
        arr[count] = tmp;
        n = arr[count] ^ n;
        count++;
    }
    cout << n;*/
    //cin >> n;
    //for (int i = 0; i < n; i++) {
    //    cin >> arr[i];
    //}
    //long long sum=1;
    //for (int i = 0; i < n; i++)
    //{
    //    sum *= arr[i];
    //    //int64_t tmp = (int64_t)sum * (int64_t)arr[i];
    //    //if ((int32_t)((int32_t)tmp) != tmp)
    //        // overflow occurred
    //    if(sum > numeric_limits<int>::max()||sum< numeric_limits<int>::min())
    //    //if(arr[i]!=0&&sum==0)
    //    {
    //        cout << -1;
    //        break;
    //    }
    //    else {
    //        cout << sum;
    //    }
    //    if (i != n - 1) cout << ' ';
    //}
        /*string numstr; long num;
        stringstream aa;
        cin >> numstr;
        aa << numstr;
        aa >> num;
        if (num >= 0) {

            num = rev(num);
            cout << num << endl;
        }
        else
        {
            num = -num;
            num = rev(num);
            if(num==0)  cout << -1<< endl;
            else cout << '-'<<num << endl;
        }*/
 /*       return 0;
}*/


int rev(long m)
{
    if (m > numeric_limits<int>::max())
        return -1;
    long t = 0;
    while (m > 0)
    {
        t = t * 10 + m % 10;
        m = m / 10;
    }
    return t;
}