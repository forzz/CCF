#include<iostream>
#include<cstdio>
#include<cstring>
#include<cstdlib>
#include<algorithm>
using namespace std;
int movex[]={1,-1,0,0};  //四种方向
int movey[]={0,0,1,-1};
char str[110][110];
int vis[110][110];
int n, m;
void dfs(int x, int y, char c)  //种子填充
{
    str[x][y] = c;
    vis[x][y] = 1;
    for(int i = 0; i < 4; i++)
    {
        x = movex[i]+x;
        y = movey[i]+y;
        if(x >= 0 && y >= 0 && x < m && y < n && str[x][y]!='|' && str[x][y]!='-' && str[x][y]!='+' && vis[x][y] == 0)
        {
            dfs(x, y, c);
        }
        x = x-movex[i];  //恢复初始状态，等下一次循环
        y = y-movey[i];
    }
}
int main()
{
    int num;
    cin >> n >> m >> num;
    memset(str,'.',sizeof(str));  //初始化
    int kind;
    int a,b,c,d;
    char cha;
    for(int i = 0; i < num; i++)  //读入每个操作
    {
        cin >> kind;
        if(kind == 1)  //填充字符
        {
            for(int i = 0; i < m; i++)  //初始化vis数组，每次都要重新初始化
            {
                for(int j = 0; j < n; j++)
                    vis[i][j] = 0;
            }
            cin >> a >> b >> cha;
            dfs(b,a,cha);
        }
        else if(kind == 0)  //画线
        {
            cin >> a >> b >> c >> d;
            if(b > d){int temp = b; b = d; d = temp;}  //小在前，大在后
            if(a > c){int temp = a; a = c; c = temp;}
            for(int i = b; i <= d; i++)  //遍历填充
            {
                for(int j = a; j <= c; j++)
                {
                    if(b == d)  //横线
                    {
                        if(str[i][j] == '|' || str[i][j] == '+')
                        {
                            str[i][j] = '+';
                        }
                        else
                            str[i][j] = '-';
                    }
                    else if(a == c)  //竖线
                    {
                        if(str[i][j] == '-' || str[i][j] == '+')
                            str[i][j] = '+';
                        else
                            str[i][j] = '|';
                    }
                }
            }
        }
    }
    for(int i = m-1; i >= 0; i--)  //倒着输出，将y轴翻转
    {
        for(int j = 0; j < n; j++)
        {
            cout << str[i][j];
        }
        cout << endl;
    }
    return 0;
}
