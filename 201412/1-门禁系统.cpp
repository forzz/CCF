#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
int num[1010];
int has[1010];
int main(){
    int n;
    cin>>n;
    memset(has,0,sizeof(has));
    memset(num,0,sizeof(num));
    for(int i=0;i<n;i++)
    {
        cin>>num[i];
        has[num[i]]++;
        cout<<has[num[i]]<<' ';
    }
    return 0;
}

