#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;
const int MAXN=10010;
int dp[MAXN][MAXN];
int dps[MAXN];
/*
    01问题特点:
        可以划分为若干个有序的阶段，每个阶段只与上个阶段相关
    
    状态: 包的物品价值，包的重量dp[i][v]的最大价值
    初始状态: dp[0][0]=0
    转移方程: dp[i][v]=max(dp[i-1][v-w[i]]+c[i],dp[i-1][v])
*/
void zeroOneProblem(int n,int V,int c[],int w[]){
    for (int i = 1; i < n; i++)
    {   
        // 放入第i件物品
        for (int v = w[i]; v <=V; v++)
        {
            dp[i][v]=max(dp[i-1][v-w[i]]+c[i],dp[i-1][v]);
        }
    }
    int max=0;
    for (int i = 1; i < n; i++)
    {
        for (int v = 0; v <= V; v++)
        {   
            // std::cout << dp[i][v] << std::endl;
            if(dp[i][v]>max)
                max=dp[i][v];
        }
    }
    std::cout << max << std::endl;
    
}

/*
    完全背包问题
    状态变量: dps[v] 表示包里重量为v时,包内物品的总价值
    初始值: dps[0]=0
    状态转换方程:
        dps[v]=max(dps[v-w[i]]+c[i],dps[v])
        dps[v-w[i]]+c[i]--> 放了一个不一样的
        dps[v]--> 放了一个一样的
*/
void completePackage(int n,int V,int w[],int c[]){
    dps[0]=0;
    for (int i = 0;i<n ; i++)
    {
        for (int v = w[i]; v <= V; v++)
        {
            dps[v]=max(dps[v-w[i]]+c[i],dps[v]);
            // std::cout << "i= "<<i<<"\tv= "<<v<<"\tdps["<<v<<"]= "<<dps[v] << std::endl;
        }
    }

    int maxNum=0;
    for (int i = 0; i <= V; i++)
    {   
        // std::cout << dps[i] << " ";
        if(dps[i]>maxNum)
            maxNum=dps[i];
    }
    std::cout <<"\n"<< maxNum << std::endl;
}

void init(int n,int v){
    for (int i = 0; i < n; i++)
    {
        dp[0][i]=0;
    }
}

int main(int argc, char const *argv[])
{   
    init(5,8);
    int c[5]={3,5,1,2,2};
    int w[5]={4,5,2,1,3};
    zeroOneProblem(5,8,w,c);
    completePackage(5,8,w,c);
    return 0;
}
