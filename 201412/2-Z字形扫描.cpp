#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int mp[510][510];
int main()
{
        memset(mp,0,sizeof(0));
        int n;
        int tag=-1;
        int b=0;
        cin>>n;
        for(int i=0;i<n;i++)
                for(int j=0;j<n;j++)
                        cin>>mp[i][j];
        int i=0,j=0;
        while(i<n&&j<n&&i>=0&&j>=0)
        {
                cout<<mp[i][j]<<' ';
                if(i==n-1&&j==n-1)
                        break;
                if(i==0&&b==0&&j<n-1)
                {
                        j++;
                        b=1;
                        tag=0;
                        continue;
                }
                if(j==0&&b==0&&i<n-1)
                {
                        i++;
                        b=1;
                        tag=1;
                        continue;
                }
                if(i==n-1&&b==0&&j<n-1)
                {
                        j++;
                        b=1;
                        tag=1;
                        continue;
                }
                if(j==n-1&&b==0&&i<n-1)
                {
                        i++;
                        b=1;
                        tag=0;
                        continue;
                }
                if(tag==0)
                        i++,j--; b=0;
                if(tag==1)
                        j++,i--;b=0;
        }
        return 0;
}
