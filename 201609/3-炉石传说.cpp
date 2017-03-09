#include<iostream>
#include<cstring>
#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
struct xx
{
    int life,att;
    xx(int a,int b):life(a),att(b){};
};
vector<xx> v[2];//表示召唤位
char op[10];
int main()
{
    int n,flag = 0;
    v[0].push_back(xx(30,0));//默认0号位是英雄
    v[1].push_back(xx(30,0));
    scanf("%d",&n);
    while(n--)
    {
        scanf("%s",op);
        if(op[0] == 'e')    flag ^= 1;//表示切换回合
        else if(op[0] == 's')
        {
            int a,b,c;
            scanf("%d%d%d",&a,&b,&c);
            v[flag].insert(v[flag].begin()+a,xx(c,b));//该位置加入随从
        }
        else//攻击
        {
            int a,b;
            scanf("%d%d",&a,&b);
            v[flag][a].life -= v[flag^1][b].att;//当前随从少血
            v[flag^1][b].life -= v[flag][a].att;//对方随从少血
            if(v[flag][a].life <= 0)    v[flag].erase(v[flag].begin()+a);//如果当前随从血量低于0，直接删除
            if(b != 0 && v[flag^1][b].life <= 0)    v[flag^1].erase(v[flag^1].begin()+b);//b=0时，b是英雄
        }
    }
    if(v[0][0].life <= 0)    printf("-1\n");//所有回合结束后判断胜负
    else if(v[1][0].life <= 0)  printf("1\n");
    else    printf("0\n");
    printf("%d\n%d ",v[0][0].life,v[0].size()-1);
    for(int i = 1;i < v[0].size();i++)  printf("%d ",v[0][i].life);
    printf("\n");
    printf("%d\n%d ",v[1][0].life,v[1].size()-1);
    for(int i = 1;i < v[1].size();i++)  printf("%d ",v[1][i].life);
    printf("\n");
    return 0;
}
