#include <iostream>
#include <string.h>
using namespace std;
int main() {
    int a[1005];
    int n,num;
    int i,j;
    memset(a,0,sizeof(int)*1005);
    cin >> n;
    for (i=0;i<n;i++){
        cin >> num;
        a[num]++;
    }
    for (i=1004;i>0;i--)
        for (j=0;j<1005;j++)
            if (a[j] == i)
                cout << j << " " << a[j] << endl;
    return 0;
}
