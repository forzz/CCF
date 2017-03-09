#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<algorithm>
#include<cstring>
using namespace std;
int n, m;
const int MAXN = 10010;
const int INF = 0x3f3f3f3f;
struct qnode{//正常优先队列默认队首是最大的元素，队列中保存终点和从源点到该终点的最短路程
        //（优先队列的目的是选出最小的边，该边的起点已在最短路集合中，所以不需要保存起点）
    int v;
    int c;
    qnode(int _v = 0, int _c = 0):v(_v), c(_c){}
    bool operator <(const qnode &r)const{
        return c > r.c;
    }
};
struct Edge{//保存边
    int v, cost;//终点和路径长度
    Edge(int _v = 0, int _cost = 0):v(_v), cost(_cost){}
};
vector<Edge>E[MAXN];
bool vis[MAXN];
int dist[MAXN];
void Dijkstra(int n, int start){//共n点，起点为start
    memset(vis, false, sizeof(vis));
    for(int i = 1; i <= n; i ++)
        dist[i] = INF;//dist保存原点到各个点的最小距离，初始为最大值
    priority_queue<qnode> que;
    while(!que.empty())//清空队列
        que.pop();
    dist[start] = 0;//原点压入队列
    que.push(qnode(start, 0));
    qnode tmp;
    while(!que.empty()){//优先队列维护最小路径，每次将该路径放入最短路集合中（也就是该终点放入最短路点集合）
        tmp = que.top();
        que.pop();
        int u = tmp.v;
        if(vis[u])//判断该终点是否已在最短路点集合中
            continue;
        vis[u] = true;//加入最短路点集合
        for(int i = 0; i < E[u].size(); i ++){//遍历该终点的所有邻接点，看是否有新的最短路更新
            int v = E[tmp.v][i].v;
            int cost = E[u][i].cost;
            if(!vis[v] && dist[v] > dist[u] + cost){//维护原点到某点的最短路径，若题只求原点到某点的距离，不需要维护
                dist[v] = dist[u] + cost;
                que.push(qnode(v, dist[v]));
            }
        }
    }
}
queue<int> q;
int minn[MAXN];
void bfs(){//都可以到王国，可以保证一次bfs就可以求出所有的路，题设所有点联通的要求其实是废话
    q.push(1);
    while(!q.empty()){
        int cur = q.front();
        q.pop();
        for(int i = 0; i < E[cur].size(); i ++){//遍历该点的所有邻接点
            if(dist[E[cur][i].v] == dist[cur] + E[cur][i].cost){
//当前的起点和终点构成的边在之前所求的最短路中，将其记录在min中，以终点为下标
                q.push(E[cur][i].v);
                minn[E[cur][i].v] = min(minn[E[cur][i].v], E[cur][i].cost);
            }
        }
    }
    int ans = 0;
    for(int i = 2; i <= n; i ++){//将2-n所有的min值相加，
        ans += minn[i];
    }
    printf("%d\n", ans);
}
void addedge(int u, int v, int w){
    E[u].push_back(Edge(v, w));
}
int main(void){
    scanf("%d%d", &n, &m);
    int x, y, v;
    memset(minn, INF, sizeof(minn));
    for(int i = 0; i < m; i ++){
        scanf("%d%d%d", &x, &y, &v);
        addedge(x, y, v);//无向边就是正反双向有向边
        addedge(y, x, v);
    }
    Dijkstra(n, 1);
    bfs();

    return 0;
}
