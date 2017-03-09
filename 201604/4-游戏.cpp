#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;

struct point{
    int x,y,time;//队列中保存当前结点的坐标和时间
    point(int _x,int _y,int _time):x(_x),y(_y),time(_time) { }
};
queue<point> q;
int vis[105][105][305] = {0},a[105][105][2] = {0},dir[][2] = {{-1,0},{1,0},{0,-1},{0,1}};//四种方向
//根据分析，同一个坐标会因为时间不同而产生不同的状态（时间不同），所以vis数组需要增加一个维度
int main()
{
    int n,m,t;
    scanf("%d%d%d",&n,&m,&t);
    while(t--)
    {
        int x,y,start,stop;
        scanf("%d%d%d%d",&x,&y,&start,&stop);
        a[x][y][0] = start;//第三维表示危险时间范围
        a[x][y][1] = stop;
    }
    q.push(point(1,1,0));//将起点放入队列
    while(!q.empty())
    {
        int x = q.front().x,y = q.front().y,time = q.front().time;
        q.pop();
        if(x == n && y == m)//结果求出，BFS可知，这就是当前最短时间
        {
            printf("%d",time);
            return 0;
        }
        for(int i = 0;i < 4;i++)//四种方向
        {
            int xx = x+dir[i][0],yy = y+dir[i][1],timee = time+1;
            if(xx < 1 || xx > n || yy < 1 || yy > m || timee>=a[xx][yy][0]&&timee<=a[xx][yy][1] || vis[xx][yy][timee])
                        continue;//不符合条件，就不放入队列
            q.push(point(xx,yy,timee));
            vis[xx][yy][timee] = 1;//标记访问数组
        }
    }
}
