#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    char a[105],b[105];
    cin >> a;
    strcpy(b,a);
    strlwr(b);//将字符串中的S转换为小写形式。
    int flag,n;
    cin >> flag >> n;
    while(n--)
    {
        char temp[105],temp2[105];
        cin >> temp;
        strcpy(temp2,temp);
        if(!flag)
        {
            strlwr(temp2);//将字符串中的S转换为小写形式。
//strlwr()和strupr()不是标准库函数，只能在windows下（VC、MinGW等）使用，Linux GCC中需要自己定义。
            if(strstr(temp2,b)) cout << temp << endl;
        }
        else
        {
            if(strstr(temp,a)) cout << temp << endl;
        }
    }
    return 0;
}
