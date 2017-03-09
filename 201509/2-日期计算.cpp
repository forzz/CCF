#include<cstring>
#include<iostream>
#include<algorithm>
#include<string>
using namespace std;
int main()
{
        int y,d;
        cin>>y>>d;
        int tag=0;
        if(((y%4==0)&&(y%100!=0))||y%400==0)
                tag=1;
        int m=1;
        int tian=31;
        while(1)
        {
                if(d>tian)
                {
                        d-=tian;
                        m++;
                        switch(m){
                        case 1: case 3:case 5:case 7:case 8:case 10:case 12:
                                tian=31; break;
                        case 4: case 6:case 9:case 11:
                                tian=30; break;
                        case 2:
                                tian=(tag==1?29:28);
                                break;
                        }
                }
                if(d<=tian)
                {
                        cout<<m<<endl<<d;
                        break;
                }
        }
        return 0;
}
