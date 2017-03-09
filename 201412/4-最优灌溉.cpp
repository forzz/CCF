#include<iostream>
#include<algorithm>
using namespace std;

int root[100000];    //记录麦田即对应点以及该点的根节点
struct Node{    //记录每个水渠的权值以及它的首尾节点
	int front;
	int next;
	int cost;
};
Node c[100005];
int findroot(int x){ return x == root[x] ? x : root[x] = findroot(root[x]); }//并查集
bool cmp(Node x, Node y)  //针对价格的排序
{
	return x.cost < y.cost;
}
int main()
{
	int n,m;
	cin >> n >> m;
	int sum(0),m1(m);
	for(int i = 0; i < n; i++)
		root[i] = i;    //将每一个节点的初始根节点设为其本身
	for(int i = 0; i < m; i++)//读入每个边
	{
		cin >> c[i].front >> c[i].next >> c[i].cost;
	}
	sort(c, c + m1, cmp);    //对价格进行升序排序
	for(int i = 0; i < m; i++)//最多m条水渠,只搜索前m条
	{
		if(findroot(c[i].front) != findroot(c[i].next))    //比较两节点的根节点是否相同
		{
			sum += c[i].cost;
			//如果不相同，则把后者的根节点设为前者的根节点，即为集合的合并
			//这里如果两者的根节点一样，说明如果它们再相连会构成回路，说明该水渠不可取
			root[findroot(c[i].next)] = findroot(c[i].front);
		}
	}
	cout << sum <<endl;
	return 0;
}

