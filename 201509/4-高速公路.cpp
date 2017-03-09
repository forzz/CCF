#include<iostream>
#include<string.h>
#include<algorithm>
using namespace std;
int n,m;
int head[10010],stackn[10010],DFN[10010],Low[10010];
//用low[i]表示从i节点出发DFS过程中i下方节点(开始时间大于dfn[i]，且由i可达的节点）所能到达的最早的节点的开始时间。
//用dfn[i]表示编号为i的节点在DFS过程中的访问序号(也可以叫做开始时间）。
int Belong[10010];//染色
int instack[10010],index,top,f,scnt;
struct node//e为起点，next为终点
{
    int e,next;
}edge[100010];
//head[i]保存的是以i为起点的所有边中编号最大的那个,而把这个当作顶点i的第一条起始边的位置.
void add(int s,int e)//s为起点，e为终点
{//f是静态链表的标记，在edge移动，为标记边提供空间
    edge[f].e=e;
    edge[f].next=head[s];//表示与第f条边同起点的上一条边的存储位置（头插法）
    head[s]=f++;//先算入f，再f++
}
//链式前向星也是一种通过存储边的信息的方式存储图的数据结构，可以静态建立邻接表。它将边存放在数组中，
//把数组中的边按照起点顺序排序，前向星就构造完成了。为了查询方便，经常会有一个数组存储起点为Vi的第一条边的位置。
void tarjan(int s)
{
    int t,k,i;
    DFN[s]=Low[s]=++index;// 刚搜到一个节点时low = dfn
    stackn[top++]=s;// 将该节点入栈
    instack[s]=1;// 将入栈标记设置为1
    for(i=head[s];i!=-1;i=edge[i].next)// 遍历入栈节点的边
    {
        k=edge[i].e;//k为终点
        if(!DFN[k])// 如果新搜索到的节点是从未被搜索过
        {
            tarjan(k);// 那自然就得搜索这个节点
            Low[s]=min(Low[k],Low[s]);// 回溯的时候改变当前节点的low值
//对于u的子节点v，从v出发进行的DFS结束回到u时，使得 low[u] = min(low[u],low[v])。
//因为u可达v,所以v可达的最早的节点，也是u可达的。
        }
        else if(instack[k])
//如果新搜索到的节点已经被搜索过而且现在在栈中(该节点的开始时间肯定比当前点早，而且没更新过low，所以用dfn或low更新皆可)
        {
            Low[s]=min(Low[k],Low[s]);
        }
//如果发现某节点u有边连到栈里的节点v，则更新u的low 值为min(low[u],dfn[v]) ，
//若low[u]被更新为dfn[v],则表明目前发现u可达的最早的节点是v.
    }
    if(Low[s]==DFN[s])
//最终退回来的时候 low == dfn ， 没有节点能将根节点更新，那low == dfn 的节点必然就是根节点
    {
        scnt++;
        do
        {
//此时，显然栈中u上方的节点，都是不能到达比u早的节点的。将栈中节点弹出，一直弹到u(包括u),弹出的节点就构成了一个强连通分量.
            t=stackn[--top];// 弹出栈元素
            Belong[t]=scnt;// 为了方便计算，将强联通分量进行标记
            instack[t]=0;// 将栈内标记置为0
        }
        while(s!=t);// 一直弹到x出现为止
    }
}
int main()
{
    int i,j,a,b,v[10010];
    cin>>n>>m;
    f=1;
    memset(head,-1,sizeof(head));
    memset(v,0,sizeof(v));
    for(i=0;i<m;i++)
    {
        cin>>a>>b;
        add(a,b);
    }
    memset(DFN,0,sizeof(DFN));
    for(i=1;i<=n;i++) //遍历每个节点
    {
        if(!DFN[i])// 如果某点没被访问过，则对其进行tarjan
            tarjan(i);// tarjan的成果是得到了一个belong数组，记录每个节点分别属于哪个强联通分量
    }
    for(i=1;i<=n;i++)//求出每个连通分量包含多少点
        v[Belong[i]]++;
    long long sum=0;
    for(i=0;i<=n;i++)//联通分量最多有n个，直接遍历
    {
        if(v[i]>1)
            sum=sum+v[i]*(v[i]-1)/2;//组合公式
    }
    cout<<sum<<endl;
    return 0;
}
