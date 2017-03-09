#include<iostream>
#include<cstdio>
#include<deque>
using namespace std;
struct point{
    int x1,x2,y1,y2,num;
}temp;//创建结构体的同时创建了该类型的temp变量
int main()
{
    deque<point> q;
    deque<point>::iterator it;
    int n,m;
    cin >> n >> m;
    for(int i = 1;i <= n;i++)
    {
        temp.num = i;
        cin >> temp.x1 >> temp.y1 >> temp.x2 >> temp.y2;
        q.push_front(temp);//后进入的优先级高
    }
    while(m--)
    {
        int x,y,flag = 1;
        cin >> x >> y;
        for(it = q.begin();it != q.end();it++)
        {
            if(it->x1 <= x && it->x2 >= x && it->y1 <= y && it->y2 >= y)//点击位置在当前窗口中
            {
                cout << it->num << endl;
                temp = *it;//保存it指针
                q.erase(it);//删除当前位置的窗口
                q.push_front(temp);//窗口置顶
                flag = 0;
                break;
            }
        }
        if(flag)
        {
            cout << "IGNORED" << endl;
        }
    }
    return 0;
}
