#include <iostream>
#include <iomanip>
using namespace std;
bool is_Special(int year){
    if(year%400==0||(year%4==0&&year%100!=0))
        return true;
    else return false;
}
int main(){
    int a,b,c,y1,y2;
    cin>>a>>b>>c>>y1>>y2;
    int month_day[12] = {31,28,31,30,31,30,31,31,30,31,30,31};
    for(int i=y1;i<=y2;i++){  //从y1年开始遍历，一直到y2年
        int first_day = 2;      //保存的是第i年第一天是星期几
        int base = 1850;   //基准是1850
//根据1850年第一天是星期二，区分是否闰年，是的话，每年星期数加2，不是的话，星期数加1
//因为365除以7，余数为1； 366除以7，余数为2
        while(base!=i){
            if(is_Special(base))
                first_day = (first_day + 2)%7;
            else
                first_day = (first_day + 1)%7;
            if(first_day==0)
                first_day = 7;
            base++;
        }
        int month = 1;    //下面求第a个月第1天是星期几，用first_day表示
        while(month != a){
            if(is_Special(i))
                month_day[1] = 29;   //表示闰年2月份有29天
            first_day = (first_day + month_day[month-1]%7)%7;
            if(first_day == 0)
                first_day = 7;
            month++;
        }
        int day = 1;  //表示最终结果：第a月第day天
        day = day + 7*(b-2) + c + (7 - first_day);
        if((c - first_day) < 0)
            day = day + 7;
        if(day > month_day[a-1])
            cout<<"none"<<endl;  //表示day超过当前月最大天数
        else{
                        cout<<setfill('0')<<setw(2)<<i<<"/"<<setw(2)<<a<<"/"<<setw(2)<<day<<endl;
            }
        month_day[1] = 28;//二月恢复为28天
    }
    return 0;
}

