#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
int s[1010];
int main()
{
    int n;
    int num=0;
    memset(s,0,sizeof(s));
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cin>>s[i];
    }
    for(int i=1;i<n-1;i++)
    {
        if((s[i-1]-s[i])*(s[i]-s[i+1])<0)
            num++;
    }
    cout<<num;
    return 0 ;
}
