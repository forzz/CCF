#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
int mp[110][110];
using namespace std;
int main()
{
        memset(mp,0,sizeof(mp));
        int n;
        cin>>n;
        int x,y,a,b;
        int sum=0;
        while(n--)
        {
                cin>>x>>y>>a>>b;
                for(int i=x;i<a;i++)
                        for(int j=y;j<b;j++)
                        if(mp[i][j]==0)
                        {
                                mp[i][j]++;
                                sum++;
                        }


        }
        cout<<sum;
        return 0;
}
