#include <algorithm>
#include <cstring>
#include <vector>
#include <stack>
using namespace std;
const int maxn = 10000 + 10;
const int maxm = 100000 + 10;
vector<int> g[maxn];
int  deg[maxn];//记录度数
bool vis[maxn], visEdge[maxn][maxn];//记录访问的点和边，欧拉路径是一笔画，需要保持点和路径都不重复
int  n, m;
stack<int> ans;
void dfs(int u)
{
    vis[u] = 1;//记录点
    for(int i = 0; i < g[u].size(); ++i)
    {
        int v = g[u][i];
        if(!visEdge[u][v]){
            visEdge[u][v] = visEdge[v][u] = 1;
            dfs(v);
            ans.push(v);//用栈存储点，在DFS后才push，保持顺序正确
        }
    }
}
int main()
//无向图欧拉路径，1. 图连通； 2. 所有顶点的度数为偶数或只有两个顶点的度数为奇数。
//有向图欧拉路径：每个点入度=出度或只有两个点a、b：a的入-出=1，b的出-入=1
//有向图欧拉回路：每个点入度=出度
//无向图欧拉回路：每个点度为偶数
{
    scanf("%d %d", &n, &m);
    int a, b;
    for(int i = 1; i <= m; ++i){
        scanf("%d %d", &a, &b);
        deg[a]++, deg[b]++;//度数增加
        g[a].push_back(b);
        g[b].push_back(a);
    }
    for(int i = 1; i <= n; ++i){    //保证是字典序最小的
        sort(g[i].begin(), g[i].end());
    }
    int cnt = 0;
    for(int i = 1; i <= n; ++i){//记录度数为奇数的顶点的个数
        if(deg[i] & 1) cnt++;
    }
    if(cnt == 2 && !(deg[1] & 1)){    // 如果存在奇度数的顶点，顶点1必须是奇度数的
        printf("-1\n");
        return 0;
    }
    if(cnt == 2 || cnt == 0){
        dfs(1);//如果存在欧拉路径，那么从奇度数点开始dfs就可以形成一条欧拉路径
        for(int i = 1; i <= n; ++i){//判断是否连通
            if(!vis[i]){
                printf("-1\n");
                return 0;
            }
        }
        printf("1");//第一个点单独输出
        while(!ans.empty()){
            printf(" %d", ans.top());
            ans.pop();
        }
    }
    else{
        printf("-1\n");
    }
    return 0;
}
