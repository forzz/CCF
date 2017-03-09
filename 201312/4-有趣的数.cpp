#include <iostream>
using namespace std;
int main()
{
//不考虑条件1，最后形成的数有六种合法状态：（根据题中的所有条件）
//1、只含2         2、只含2、0         3、只含2、3         4、只含2、0、1       5、只含2、0、3       6、含4种数字。
//用dp[i][0]~dp[i][5]来分别表示长度为i的整数，满足上述状态的个数。那么可以得到状态转移方程：
//1、dp[i][0]=1，位数为i且只含2的整数有且只有1个
//2、dp[i][1]=2*dp[i-1][1]+dp[i-1][0]，位数为i且只含2、0的整数可以由位数为i-1的只含2、0的整数
//通过在末尾添加0或者2得到，也可以由位数为i-1的只含2的整数在末尾添加0得到。其余的状态转移方程以此类推。
   long long mod = 1000000007;
   long long n;
   cin>>n;  //位数
   long long **states = new long long*[n+1];
   for(long long i =0;i<n+1;i++)
       states[i]=new long long[6];
   for(long long i =0;i<6;i++)  //初始化dp边界（0个位构成数全是0）
       states[0][i]=0;
   for(long long i=1;i<=n;i++)  //以每位作为dp单位
   {  //需要保证所有的0都出现在所有的1之前，而所有的2都出现在所有的3之前。
       long long j = i-1;
       states[i][0] = 1;
       states[i][1] = (states[j][0] + states[j][1] * 2) % mod;
       states[i][2] = (states[j][0] + states[j][2]) % mod;
       states[i][3] = (states[j][1] + states[j][3] * 2) % mod;
       states[i][4] = (states[j][1] + states[j][2] + states[j][4] * 2) % mod;
       states[i][5] = (states[j][3] + states[j][4] + states[j][5] * 2) % mod;
   }

   cout<<states[n][5]<<endl;
   return 0;
}
