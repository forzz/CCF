#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;
const int maxn = 35;
int   grid[maxn][maxn], temp[maxn][maxn];
//标记数组(消除游戏每个格子在消除期间可以多次使用,不能直接清0)
//从上到下，从左到右遍历图，以每个格子为中心，往左往上延伸，标记符合情况的格子
int   n, m;
int main()
{
    cin >> n >> m;
    for(int i = 0; i < n; ++i)
        for(int j = 0; j < m; ++j)
            cin >> grid[i][j];
    for(int i = 0; i < n; ++i){
        int cnt = 1;//相同棋子的最大长度
        for(int j = 1; j < m; ++j){
            if(grid[i][j] == grid[i][j - 1]) cnt++;//往左延伸
            else cnt = 1;
            if(cnt >= 3){
                for(int k = j; k > j - cnt; --k) temp[i][k] = 1;
            }
        }
    }
    for(int j = 0; j < m; ++j){
        int cnt = 1;
        for(int i = 1; i < n; ++i){
            if(grid[i][j] == grid[i - 1][j]) cnt++;//往上延伸
            else cnt = 1;
            if(cnt >= 3){
                for(int k = i; k > i - cnt; --k) temp[k][j] = 1;
            }
        }
    }
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < m; ++j){
            if(temp[i][j] == 1) cout << 0 << " ";
            else cout << grid[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}
