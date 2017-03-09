#include<cstdio>
#include<algorithm>
using namespace std;
int a[1005];
int main()
{
    int n;
    scanf("%d",&n);
    for(int i = 1;i <= n;i++)   scanf("%d",&a[i]);
    int maxx = 0;
    for(int i = 2;i <= n;i++)   maxx = max(maxx,abs(a[i]-a[i-1]));
    printf("%d\n",maxx);
    return 0;
}
