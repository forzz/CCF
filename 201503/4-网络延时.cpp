 #include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
#define N 20005
vector<int>G[N];//电脑和交换机不用区分，保存在一张图中
int d[N];//表示每个结点与根节点的最大距离
bool vis[N];
int bfs(int s,int &t){//s为根节点，t保存与根节点距离最远的节点
    queue<int>q;
    memset(d,0,sizeof(d));
    memset(vis,0,sizeof(vis));
    t=s;//t节点初始化为s节点
    int ans=0;
    q.push(s);
    vis[s]=1;
    while(!q.empty()){
        int u=q.front();
        q.pop();
        for(int i=0;i<G[u].size();++i){//遍历邻接点
            int v=G[u][i];
            if(!vis[v]){
                vis[v]=1;
                d[v]=d[u]+1;//维护当前节点与根节点的最大距离
                if(d[v]>ans){//判断是否可以更新最远距离
                    ans=d[v];
                    t=v;
                }
                q.push(v);
            }
        }
    }
    return ans;
}
int main()
{
    int i,j,n,m,x;
    scanf("%d%d",&n,&m);
    for(i=2;i<=n;++i){//加入边，交换机
        scanf("%d",&x);
        G[x].push_back(i);//G[x]保存了x的所有邻接点，G[x][i]保存的是第i个邻接点的编号
        G[i].push_back(x);
    }
    for(i=1;i<=m;++i){//加入边，电脑
        scanf("%d",&x);
        G[x].push_back(i+n);
        G[i+n].push_back(x);
    }
    int p,ans;
    ans=bfs(1,p);//根节点为1，最远点为p(p在函数结束后会成为最远节点)
    ans=max(ans,bfs(p,p));//根节点为p，最远点保存为p（此时只要求出ans即可）
    printf("%d\n",ans);
    return 0;
}

