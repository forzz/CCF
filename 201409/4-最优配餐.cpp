#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<queue>
#define MAX 1010
using namespace std;
int n,m,k,d;
int v[4][2]={{-1,0},{1,0},{0,-1},{0,1}};//四个方向
int vis[MAX][MAX];
long long order[MAX][MAX];//订单量可能超过10^8
struct Node{
    int x,y;
    long long dis;
    Node(int xx,int yy,int c): x(xx),y(yy),dis(c){}
};
queue<Node>Q;
void bfs(){
//（先把每个分店放入队列）每个分店同时向四周搜索，搜索到的第一个客户必然是距离该分店最近的。
    long long ans=0;
    while(!Q.empty()){
        Node t=Q.front();
        Q.pop();
        int x=t.x,y=t.y,dis=t.dis;
        for(int i=0;i<4;i++){//四个方向搜索
            int xx=x+v[i][0],yy=y+v[i][1];
            if(xx>=1&&xx<=n&&yy>=1&&yy<=n&&!vis[xx][yy]){
                ans+=order[xx][yy]*(dis+1);//如果当前点有订单，那么是最近订单，直接加到结果中
                vis[xx][yy]=1;
                Q.push(Node(xx,yy,dis+1));
            }
        }
    }
    cout<<ans<<endl;
}
int main(){
    cin>>n>>m>>k>>d;//分别表示方格图的大小、栋栋的分店数量、客户的数量，以及不能经过的点的数量。
    int a,b,c;
    for(int i=0;i<m;i++){//表示栋栋的一个分店在方格图中的横坐标和纵坐标。
        cin>>a>>b;
        Q.push(Node(a,b,0));
    }
    for(int i=0;i<k;i++){
//分别表示每个客户在方格图中的横坐标、纵坐标和订餐的量。（注意，可能有多个客户在方格图中的同一个位置）
        cin>>a>>b>>c;
        order[a][b]+=c;
    }
    for(int i=0;i<d;i++){//分别表示每个不能经过的点的横坐标和纵坐标
        cin>>a>>b;
        vis[a][b]=1;//直接当作已访问点，看作障碍
    }
    bfs();
    return 0;
}
