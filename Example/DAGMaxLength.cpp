#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
#include <vector>
using namespace std;
const int MAXN=10010;
struct Node{
    int id;
    int val;
};
int dp[MAXN];
int choice[MAXN];
vector<Node> Adj[MAXN];
void init(int start,Node* arr,int len){
    for (int i = 0; i < len; i++)
    {
        Adj[start].push_back(*(arr+i));
    }
}
/*
  使用动态规划求DAG的最长路径
  思路:
    设置状态: dp[i]表示以i为结尾的最长路径值
    初始状态: dp[0]=0
    假设直接到达i的节点为j1,j2...jn
    那么dp[i]=max(dp[jx]+len(jx->i)
*/
void DP(int i){
    int maxLen=0;
    int maxId=-1;
    // 访问节点
    cout<<i<<" ";
    if(Adj[i].size()==0) return;
    // 找i结点出边最长的一个作为关键路径上的下一个点
    for (int j = 0; j < Adj[i].size(); j++)
    {   
        // 求最大的边权
        if(Adj[i][j].val>maxLen){
            maxLen=Adj[i][j].val;
            maxId=Adj[i][j].id;
        }
    }
    choice[i]=maxId;
    DP(maxId);
}

int main(int argc, char const *argv[])
{
    Node n0[2]={{2,2},{3,2}};
    Node n1[2]={{3,3},{4,2}};
    Node n2[1]={{5,3}};
    Node n3[2]={{5,3},{6,2}};
    Node n4[1]={{6,1}};
    Node n5[2]={{7,2},{8,3}};
    Node n6[2]={{7,2},{8,2}};
    init(0,n0,2);
    init(1,n1,2);
    init(2,n2,1);
    init(3,n3,2);
    init(4,n4,1);
    init(5,n5,2);
    init(6,n6,2);
    fill(dp,dp+MAXN,0);
    DP(1);
    return 0;
}
