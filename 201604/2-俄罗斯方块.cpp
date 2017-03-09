#include <cstdio>
#include <iostream>
using namespace std;
int a[20][15];
int b[10][10];
int main(){
    for(int i = 1; i <= 15; ++i)//15行10列 原图
        for(int j = 1; j <= 10; ++j)
            scanf("%d", &a[i][j]);
    for(int i = 1; i < 5; ++i)//4行4列   方块图
        for(int j = 1; j < 5; ++j)
            scanf("%d", &b[i][j]);
        int n;
    scanf("%d", &n);
    int cnt = 5;
    while(true){
        bool ok = false;//模拟方块图在原图对应位置下降 cnt表示方块最底层位置
        for(int i = cnt; i > cnt-4; --i){//从下向上
            for(int j = n; j < n+4; ++j)//从左到右
            //如果原图和方块图都有1或者方块已经到原图的最后一行且方块图中有1
            //（方块图的最后一行可能没有1，这时还能再往下一行）
                if((a[i][j] && b[i-cnt+4][j-n+1]) || (i >= 16 && b[i-cnt+4][j-n+1])){ ok = true; break; }
            if(ok)  break;
        }
        if(ok)  break;
        ++cnt;//再往下一行
    }
    --cnt;//当前cnt已经发生冲突，减去一行
    for(int i = cnt; i > cnt-4; --i)
        for(int j = n; j < n+4; ++j)
            a[i][j] |= b[i-cnt+4][j-n+1];//取或求1
    for(int i = 1; i < 16; ++i)//输出新图
        for(int j = 1; j < 11; ++j)
            if(10 == j)  printf("%d\n", a[i][j]);
            else printf("%d ", a[i][j]);

    return 0;
}
