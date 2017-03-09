#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;

int a[20];

int main()
{
    for(int i = 0;i < 20;i++)   a[i] = 5;
    int n;
    scanf("%d",&n);
    while(n--)
    {
        int t;
        scanf("%d",&t);
        int pos;
        for(pos = 0;pos < 20;pos++)
        {
            if(a[pos] >= t) break;
        }
        if(pos == 20)
        {
            for(int i = 0;i < 20 && t;i++)
            {
                if(!a[i])   continue;
                while(t-- && a[i]--)    printf("%d ",i*5+5-a[i]);
            }
        }
        else
        {
            for(int i = pos*5+6-a[pos],j = 1;j <= t;j++,i++)    printf("%d ",i);
            printf("\n");
            a[pos] -= t;
        }
    }
}
