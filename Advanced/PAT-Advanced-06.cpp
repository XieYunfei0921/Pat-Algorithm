#include <iostream>
#include <algorithm>
using namespace std;
/*
    最大连续子列和问题
    1. 动态规划思想
    状态dp[i]: 表示以i结尾的最大子列和
    初始状态: dp[0]=a[0]
    状态转移方程: 
        dp[i]=Node{i,i,a[i]}; dp[i]+a[i]<a[i]
        dp[i]=Node{dp[i-1].from,dp[i-1].to+1,dp[i-1].sum+a[i]}
*/
struct Node{
    int from;
    int to;
    int sum;
};
bool cmp(Node n1,Node n2){
    return n1.sum>n2.sum;
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int tab[n];
    Node dp[n];
    bool flag=true;
    for (int i = 0; i < n; i++){
        cin>>tab[i];
        if(tab[i]<0) flag&=true;
        else flag&=false;
    }
    if(flag) {std::cout << 0<<" "<<tab[0]<<" "<<tab[n-1] << std::endl;return 0;}
    dp[0]=Node{0,0,tab[0]};
    for (int i = 1; i < n; i++)
    {
        if(dp[i-1].sum>0)
            dp[i]=Node{dp[i-1].from,dp[i-1].to+1,dp[i-1].sum+tab[i]};
        else
            dp[i]=Node{i,i,tab[i]};
    }
    sort(dp,dp+n,cmp);
    std::cout << dp[0].sum<<" "<<tab[dp[0].from]<<" "<<tab[dp[0].to] << std::endl;
    return 0;
}
