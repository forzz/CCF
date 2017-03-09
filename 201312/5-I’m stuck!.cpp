#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
struct P{
    int x,y;
};
char Map[55][55];//保存地图
int mov[4][2]={{1,0},{-1,0},{0,-1},{0,1}};//下上左右4个方向
bool able[55][55][55][55],v1[55][55],v2[55][55];
//v1表示从起点可以到达的位置               v2表示从终点可以到达的位置
void get(P a,int &st,int &ed){//设st和ed表示当前点走的范围
    if(Map[a.x][a.y]=='-') st=2,ed=4;
    else if(Map[a.x][a.y]=='|') st=0,ed=2;
    else if(Map[a.x][a.y]=='.') st=0,ed=1;
    else st=0,ed=4;//'+': 当玩家到达这一方格后，下一步可以向上下左右四个方向相邻的任意一个非'#'方格移动一格；
}
int main()
{
    int n,m,i,j;
    scanf("%d%d",&n,&m);
    for(i=0;i<n;++i) scanf("%s",Map[i]);
    queue<P> q;
    P p,e;//p为起点，e为终点
    for(i=0;i<n;++i)            //记录起点和终点
    for(j=0;j<m;++j){
        if(Map[i][j]=='S'){
            p.x=i,p.y=j;
            q.push(p);//起点直接放到队列中
        }
        else if(Map[i][j]=='T'){
            e.x=i,e.y=j;
        }
    }
    memset(v1,0,sizeof(v1));
    memset(v2,0,sizeof(v2));
    memset(able,0,sizeof(able));
    v1[p.x][p.y]=1;
    while(!q.empty()){
        p=q.front();q.pop();
        P tem=p;
        int st,ed;
        get(p,st,ed);//前进方向
        for(i=st;i<ed;++i){
            tem.x=p.x+mov[i][0];
            tem.y=p.y+mov[i][1];
            if(tem.x>=0&&tem.y>=0&&tem.x<n&&tem.y<m&&Map[tem.x][tem.y]!='#'){//判断移动是否合法
                able[p.x][p.y][tem.x][tem.y]=1;//两点之间可以移动，为从终点的BFS提供方便
                if(!v1[tem.x][tem.y]){
                    v1[tem.x][tem.y]=1;
                    q.push(tem);
                }
            }
        }
    }
    if(!v1[e.x][e.y]) {puts("I'm stuck!");return 0;}
    int ans=0;
    q.push(e);//将e作为起点
    v2[e.x][e.y]=1;
    while(!q.empty()){
        p=q.front();q.pop();
        P tem=p;
        for(i=0;i<4;++i){
            tem.x=p.x+mov[i][0];
            tem.y=p.y+mov[i][1];
            if(tem.x>=0&&tem.y>=0&&tem.x<n&&tem.y<m&&Map[tem.x][tem.y]!='#'&&able[tem.x][tem.y][p.x][p.y]&&!v2[tem.x][tem.y]){
                v2[tem.x][tem.y]=1;
                q.push(tem);
            }
        }
    }
    for(i=0;i<n;++i)
        for(j=0;j<m;++j)
            if(v1[i][j]&&!v2[i][j]) ++ans;
    printf("%d\n",ans);
    return 0;
}
