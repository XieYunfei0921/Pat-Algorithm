#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,m,temp,maxn=0,num=0;
    cin>>n>>m;
    int total[n];
    int sum[n];
    fill(sum,sum+n,0);
    // i: 树的编号 j: 剪支次数 
    for (int i = 0; i <n; i++){
        cin>>total[i];
        for (int j = 0; j < m; j++){
            cin>>temp;
            sum[i]+=temp*(-1);
        }
        total[i]-=sum[i];
    }
    int suma=0;
    for (int i = 0; i < n; i++)
        suma+=total[i];
    for (int i = 0; i < n; i++)
        if(sum[i]>maxn){
            maxn=sum[i];
            num=i;
        }
    cout<<suma<<" "<<num+1<<" "<<maxn;
    return 0;
}
