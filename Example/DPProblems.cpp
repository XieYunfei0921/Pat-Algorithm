#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;
const int MAXN=10010;
int dp[MAXN];
int dps[MAXN][MAXN];
/*
    最大连续子列和:
    动态规划解法:
    假设末尾为i的最大子列和为dp[i],前面i-1的子列和已知
    则:
        dp[i]=max{dp[i-1]+A[i],A[i]}
        dp[i]=dp[i-1]+A[i]代表最长子列和数组扩展条件
*/
void maxSublist(int data[],int n){
    fill(dp,dp+n,0);
    dp[0]=data[0];
    for (int i = 1; i < n; i++)
    {
        dp[i]=max(dp[i-1]+data[i],data[i]);
    }
    // 获得最大子列和
    int m=0;
    for (int i = 0; i < n; i++)
    {
        if(dp[i]>m)
            m=dp[i];
    }
    std::cout << m << std::endl;
}

/*
    最大不下降序列求法
    状态设置: dp[i]--> 下标为i的最大不下降序列长度
    状态转移方程: dp[i]=max{dp[i-1]+1,1}(连续)
        dp[i]=max{dp[j]+1,1}(j<i 不连续)
*/
void LIS(int data[],int n){
    fill(dp,dp+n,1);
    // 求不连续
    // for (int i = 1; i < n; i++)
    // {
    //     if(data[i]>=data[i-1])
    //         dp[i]=dp[i-1]+1;
    //     else
    //         dp[i]=1;
    // }
    for (int i = 1; i < n; i++)
    {   
        for (int j = 0; j < i; j++)
        {
            if(data[i]>=data[j] && dp[j]+1>dp[i]){
                dp[i]=dp[j]+1;
            }
        }
    }
    
    int maxNum=0;
    for (int i = 0; i < n; i++)
    {
        if(dp[i]>maxNum)
            maxNum=dp[i];
    }
    std::cout << maxNum << std::endl;
}

/*
    最长公共子序列LCS
    状态设置: dps[i][j]: A字符串i位置和B字符串j位置的LCS值
    状态转移方程: a[i]==b[j]?dps[i][j]=dps[i-1][j-1]+1:max(dps[i-1][j],dps[i][j-1])
*/
void LCS(string s1,string s2){
    int len1=s1.length();
    int len2=s2.length();
    if(s1[0]==s2[0]){
        for (int i = 0; i < len2; i++)
            dps[0][i]=1;
        for (int j = 0; j < len1; j++)
            dps[j][0]=1;
    }
    else{
        for (int i = 0; i < len2; i++)
            dps[0][i]=1;
        for (int j = 0; j < len1; j++)
            dps[j][0]=1;
    }

    for (int i = 1; i < len1; i++)
    {
        for (int j = 1; j < len2; j++)
        {
            if (s1[i]==s2[j])
            {
                dps[i][j]=dps[i-1][j-1]+1;
            }else{
                dps[i][j]=max(dps[i-1][j],dps[i][j-1]);
            }
        }
    }
    std::cout << dps[len1-1][len2-1] << std::endl;
}


/*
    状态: dps[i][j]表示i-j位置是否为回文串
    初始化: dps[k][k]=1
    转换方程: s[i]==s[j] && s[i-1][j+1]==1?s[i][j]=1:s[i][j]=0
*/
void maxBackString(string s){
    int len=s.length();
    int ans=1;
    for (int i = 0; i < len; i++)
    {
        dps[i][i]=1;
        if(i!=len-1){
            dps[i][i+1]=s[i]==s[i+1]?1:0;
            ans=2;
        }
    }
    // i<j
    for (int L = 3; L < len; L++)
    {
        for (int i = 0; i+L-1 < len; i++)
        {
            int j=i+L-1;
            if(s[i]==s[j] && dps[i+1][j-1]==1){
                dps[i][j]=1;
                ans=L;
            }
            else
                dps[i][j]=0;
        }
    }
    std::cout << "Ans= "<<ans << std::endl;
}


int main(int argc, char const *argv[])
{
    int data[6]={-2,11,-4,13,-5,-2};
    maxSublist(data,6);
    int arr[8]={1,2,3,-9,3,9,0,11};
    LIS(arr,8);
    LCS("sadstory","adminsorry");
    maxBackString("PATZJUJZTACCBCC");
    return 0;
}
