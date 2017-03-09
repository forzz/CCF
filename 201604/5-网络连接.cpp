#include<iostream>
#include<cstdio>
#include<queue>
#include<cstring>
using namespace std;
struct node {
    int x,y;
    int step ;
//    bool operator <(const node & p) const {
//        return step>p.step ;
//    }
};
struct Trap {
    int a,b;
};
int n,m,t;
Trap trap[105][105];
bool flag[105][105][400];
int addx[4]={0,0,1,-1} ;
int addy[4]={-1,1,0,0} ;
int bfs(){
    queue<node>qq ;
    memset(flag,false,sizeof(flag));
    //queue<node>qq ;
    while(!qq.empty())qq.pop() ;
    node p ;
    p.x=1;
    p.y=1;
    p.step=0;
    flag[1][1][0]=true ;
    qq.push(p) ;
    while(!qq.empty()){
        node top = qq.front() ;
        qq.pop() ;
        if(top.x==n&&top.y==m){
            return top.step ;
        }
        for(int i=0;i<4;i++){
            node newnode ;
            newnode.x=top.x+addx[i] ;
            newnode.y=top.y+addy[i] ;
            newnode.step = top.step+1 ;
            if(newnode.x<1||newnode.x>n||newnode.y<1||newnode.y>m)continue ;
            if(flag[newnode.x][newnode.y][newnode.step])continue ;
            if(newnode.step>trap[newnode.x][newnode.y].b||newnode.step<trap[newnode.x][newnode.y].a){
                qq.push(newnode) ;
                flag[newnode.x][newnode.y][newnode.step]=true ;
            }
        }
    }
    return -1;
}

int main(){
    while(~scanf("%d%d%d",&n,&m,&t)){
        for(int i=0;i<t;i++){
            int r,c,a,b;
            scanf("%d%d%d%d",&r,&c,&a,&b);
            trap[r][c].a=a;
            trap[r][c].b=b;
        }
        int ans=bfs() ;
        printf("%d\n",ans);
    }
    return 0;
}
