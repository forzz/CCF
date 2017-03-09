#include<iostream>
#include<algorithm>
#include<cstdio>
#include<cstring>
using namespace std;
int has[10010];
int main()
{
        int n;
        cin>>n;
        int mx=0;
        int mxn=-1;
        memset(has,0,sizeof(has));
        while(n--)
        {
                int x;
                cin>>x;
                has[x]++;
                if(has[x]>mx||(has[x]==mx&&x<mxn))
                   {
                           mxn=x;
                           mx=has[x];
                   }
        }
        cout<<mxn<<endl;
}
