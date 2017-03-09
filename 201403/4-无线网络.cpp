#include<cstdio>
#include<iostream>
#include<queue>
using namespace std;
struct point{//放入队列的结构，需要保存当前的坐标和当前路由器编号num，中转路由器个数（步数）counts，安装路由器个数sets
    long long x,y,num,counts,sets;//拿不准就全用long long
}a[205];
int cango[205][205] = {0},vis[205][205] = {0};
//vis[i][j]代表到第i个点，走了j步的状态，注意判断新增路由器数量是否超过K。
//vis目的是为了不走重复路，中转路由个数的加入会使同一点存在不同状态，所以需要增加一个维度
int main()
{
    int n,m,k;//n个路由器，m个可以摆放无线路由器的位置，可以在这些位置中选择至多 k 个增设新的路由器。
    long long r;//后面要r*r，int会越界
    cin >> n >> m >> k >> r;
    for(int i = 1;i <= m+n;i++)//前n个是放好的路由器的位置，后m个是可以选择的新位置
    {
       cin >> a[i].x >> a[i].y;
       a[i].num = i;
    }
    for(int i = 1;i < m+n;i++)
//进行预处理将条件变为一个分散点的BFS，先建立一个互相是否可达的二维数组
    {
        for(int j = i;j <= m+n;j++)
        {
            if((a[i].x-a[j].x)*(a[i].x-a[j].x)+(a[i].y-a[j].y)*(a[i].y-a[j].y) <= r*r)//勾股定理
            {
                cango[i][j] = cango[j][i] = 1;
            }
        }
    }
    a[1].counts = 0;
    a[1].sets = 0;
    vis[1][0] = 1;
    queue<point> q;
    q.push(a[1]);
    while(!q.empty())
    {
        long long num = q.front().num,counts = q.front().counts;
        q.pop();
        if(num == 2)//到达第二个设备
        {
            cout << counts-1 << endl;
            return 0;
        }
        for(int i = 1;i <= m+n;i++)
        {
            long long sets;
            if(i > n)    sets = q.front().sets+1;//在当前位置增加设备
            else        sets = q.front().sets;//当前位置存在设备，直接读取其增加设备数
            if(cango[num][i] && !vis[i][counts+1] && sets <= k)
            {
                a[i].sets = sets;
                a[i].counts = counts+1;
                q.push(a[i]);
                vis[i][counts+1] = 1;
            }
        }
    }
}
