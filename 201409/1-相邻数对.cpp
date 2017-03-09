#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int has[10010];
int main()
{
        memset(has,0,sizeof(has));
        int n;
        cin>>n;
        int num=0;
        while(n--)
        {
                int x;
                cin>>x;
                has[x]++;
        }
        for(int i=0; i<10009;i++)
        {
                if(has[i]&&has[i+1])
                        num++;
        }
        cout<<num<<endl;
}
