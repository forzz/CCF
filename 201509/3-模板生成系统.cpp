#include<iostream>
#include<string>
using namespace std;
int main(){
    int lnum,vnum;
    int start,end,flag;
    string in[101],out[101];
   // map<string，stringj> str;
    string str[101][2];
    string temp;
    cin>>lnum>>vnum;
    getchar();  //处理换行符
    for(int i=0;i<lnum;i++){  //读入模板
        getline(cin,in[i]);
    }
    for(int j=0;j<vnum;j++){  //读入替换变量
        cin>>str[j][0];
        getline(cin,str[j][1]);  //第二个字符串中间有空格，所以用getline
        str[j][1]=str[j][1].substr(2,str[j][1].length()-3);  //截取从2开始到length-3结束的字符串，删除“”和最开始的空格
        //substr（起点，从起点开始的字符个数）
    }
    //output
    for(int i=0;i<lnum;i++){
        while(1){
            flag=0;//一个语句包含多个变量，用flag标记此变量有没有定义
            start=in[i].find("{{");
            end=in[i].find("}}");
            if(start<0||end<0)break;  //没有完整的{{}}就不算是变量
            temp=in[i].substr(start+3,end-start-4);  //截取其中的变量（删除两边的空格和{{）
            for(int j=0;j<vnum;j++){  //枚举查找是否在变量表中
                if(temp==str[j][0]){
                    flag=1;
                    temp=str[j][1];
                    break;
                }
            }
            if(flag==0) temp="";  //没定义，不输出任何值
            out[i]=out[i]+in[i].substr(0,start)+temp; //out逐渐增长，截取到替换后的变量末尾
            in[i]=in[i].substr(end+2,in[i].length()-end-2);//in逐渐缩短，截取到现有变量的最后到结尾处
        }
        out[i]=out[i]+in[i];//加上剩下的一节
        cout<<out[i]<<endl;
    }
    return 0;
}

