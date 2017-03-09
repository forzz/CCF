#include<cstdio>
#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int has[1010];
int main()
{
        int n;
        cin>>n;
        int t=0;
        memset(has,0,sizeof(has));
        while(n--)
        {
                int x;
                cin>>x;
                x=abs(x);
                if(has[x]==0)
                        has[x]++;
                else
                    t++;
        }
        cout<<t<<endl;
}
