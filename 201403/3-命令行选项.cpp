#include<iostream>
#include<vector>
#include<map>
using namespace std;
int main()
{
    string geshi;
    getline(cin,geshi);
    string a;
    int n;
    cin>>n;
    int count(1);   //记下Case的数目
    for(int i=0;i<n;i++)
    {
        cin.get();   //吞换行符(cin与getline之间存在一个换行符未读取)
        vector<string>vec;
        map<string,string>map1;   //前者用于记录字符，后者为前者的参数
        getline(cin,a);
        for(int t=a.find(' ');t!=-1;t=a.find(' '))   //分割命令字符串
        {
            vec.push_back(a.substr(0,t));    //将分割的字符串存入vector数组中
            a=a.substr(t+1,a.size()-t);     //将前面已经算过的除去
        }
        vec.push_back(a);  //最后一个字符串还没存入
        for(int j=1;j<vec.size();j++)
        {
            if(vec[j].size() == 2 && vec[j][0] == '-')   //符合条件
            {
                char c = vec[j][1];
                int next = geshi.find(c);
                if(next == -1)//npos的值为-1
                    break;   //非法则跳出
                if(map1.find(vec[j])==map1.end())   //表示该字符串在map1中没有重复的
                    map1.insert(pair<string,string>(vec[j]," "));   //没有就插入
                if(geshi[next+1] == ':' && j+1<vec.size())   //判断有没有参数
                {
                    map<string,string>::iterator it = map1.find(vec[j]);
                    it->second = vec[j+1];   //添加参数 如果已有参数也可以直接覆盖
                    j++;
                }
            }
            else
                break;
        }
        //由于map本身就是按键的值升序排列，少去了自己排序麻烦，可直接迭代器输出
        cout<<"Case "<<count<<":";
        map<string,string>::iterator iter = map1.begin();
        for(iter = map1.begin();iter!=map1.end();iter++)
        {
            cout<<' '<<iter->first;
            if(iter->second!=" ")
                cout<<' '<<iter->second;
        }
        cout<<endl;
        count++;
    }
    return 0;
}
