#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
    string s;
    getline(cin,s);
    int sum=0;
    for(int i=0,j=0;i<12;i++)
    {
        if(s[i]=='-')
            continue;
        sum+=(++j)*(s[i]-'0');
    }
    sum%=11;
    sum=(sum==10?-1:sum);
    if(sum==-1&&s[12]=='X'||sum==s[12]-'0')
        cout<<"Right";
    else{
        for(int i=0;i<12;i++)
            cout<<s[i];
        if(sum==-1)
            cout<<'X';
        else cout<<sum;
    }
    return 0;
}
