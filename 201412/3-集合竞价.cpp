#include <iostream>
#include <algorithm>
#include <cstdio>
using namespace std;
struct S {//保存每条语句
    float cost;//价钱
    long long num;//数量
    bool buy;//买或者卖
    int c;//是否取消
    S(float f=-1,long long n=0,bool b=false,int cc=0) {
        cost=f,num=n,buy=b,c=cc;
    }
S cord[5000];
int mark[5000]= {0};
int main(void) {
    string str;
    float co;//辅助参数
    long long nu;
    int n=0;
    while(cin>>str) {//读入每组命令
        switch(str[0]) {
            case 'b':
                cin>>co>>nu;
                cord[n]=S(co,nu,true,1);
                break;
            case 's':
                cin>>co>>nu;
                cord[n]=S(co,nu,false,1);
                break;
            case 'c'://取消命令也要加入，可能取消该取消指令
                cin>>nu;
                cord[n]=S();
                cord[nu-1].c=cord[nu-1].c?0:1;
                break;
        }
        n++;
    }
    float bc=0;
    long long nn=0;
    for(int i=0; i<n; i++) {//暴力枚举出c（c必为某个买卖价，这样才能是最大值）
        if(mark[i]||cord[i].cost<0) {
            continue;
        }
        float c=cord[i].cost;//假设当前价钱是结果
        long long bn=0,sn=0;//买和卖总交易量
        for(int j=0; j<n; j++) {//暴力枚举
            if(cord[j].cost<0){
                continue;
            }
            if(cord[j].cost==c) {//和结果相等，算入相应结果
                mark[j]=1;
                if(cord[j].buy) {
                    bn+=cord[j].num*cord[j].c;
                } else {
                    sn+=cord[j].num*cord[j].c;
                }
            } else if(cord[j].cost>c&&cord[j].buy) {//比结果大，若为买，则算入结果
                bn+=cord[j].num*cord[j].c;
            } else if(cord[j].cost<c&&!cord[j].buy){//比结果小，若为卖，则算入结果
                sn+=cord[j].num*cord[j].c;
            }
        }
        long long mi=min(bn,sn);//记录当前解
        if(mi>nn||mi==nn&&c>bc) {//更新最优解
            nn=mi,bc=c;
        }
    }
    printf("%.2f %lld\n",bc,nn);

    return 0;
}
