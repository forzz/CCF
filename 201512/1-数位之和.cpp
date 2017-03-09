#include<iostream>
#include<cstdio>
using namespace std;
int main()//2*10^9是int最大值
{
    int n,sum = 0;
    cin >> n;
    while(n)
    {
        sum += n%10;
        n /= 10;
    }
    cout << sum << endl;
    return 0;
}
