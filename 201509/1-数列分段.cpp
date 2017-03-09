#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int a[1010];
int main()
{
    memset(a,0,sizeof(a));
    int n;
    int sum=1;
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<n;i++)
    {
        if(a[i]!=a[i-1])
            sum++;
    }
    cout<<sum;
    return 0;
}
