#include <iostream>
#include <stdio.h>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN=501;
const int INF=1000000000;
// 由于题意是一个无向图，且数量小于1000使用邻接矩阵比较好
int n,m,st,ed,G[MAXN][MAXN],weight[MAXN];
// 到d的距离 以及最大点权和 ,最小路径的数量
int d[MAXN],w[MAXN],num[MAXN];
bool vis[MAXN]={false};
void Dijkstra(int s){
    fill(d,d+MAXN,INF);
    memset(num,0,sizeof(num));
    memset(w,0,sizeof(w));
    d[s]=0;
    w[s]=weight[s];
    num[s]=1;
    for (int i = 0; i < n; i++){
        int u=-1,MIN=INF;
        // 找到最短距离
        for (int j = 0; j < n; j++){
            if(vis[j]==false && d[j]<MIN){
                MIN=d[j];
                u=j;
            }
        }
        // 找不到说明剩下的点不在s所在的连通图内部
        // 第一个找到的u其实是s,s的邻接节点d最小的一个
        // 是一直访问最近节点DFS的变形写法
        if(u==-1) return;
        vis[u]=true;
        for (int v = 0; v < n; v++){
            // 在u的基础上优化v,有局部最小到全局最小的演化
            if(vis[v]==false && G[u][v]!=INF){
                if(d[u]+G[u][v]<d[v]){
                    d[v]=d[u]+G[u][v];
                    w[v]=w[u]+weight[v];
                    num[v]=num[u];
                }else if(d[u]+G[u][v]==d[v]){
                    // 两条路径长度相等，但是点权和不一定相等，取大的
                    if(w[u]+weight[v]>w[v]){
                        w[v]=w[u]+weight[v];
                    }
                    // 路径计算
                    num[v]+=num[u];
                }
            }
        }
    }
}
int main(int argc, char const *argv[])
{
    scanf("%d %d %d %d",&n,&m,&st,&ed);
    for (int i = 0; i < n; i++)
        scanf("%d",&weight[i]);
    int u,v;
    fill(G[0],G[0]+MAXN*MAXN,INF);
    for (int i = 0; i < m; i++){
        scanf("%d%d",&u,&v);
        scanf("%d",&G[u][v]);
        G[v][u]=G[u][v];
    }
    Dijkstra(st);
    printf("%d %d\n",num[ed],w[ed]);
    return 0;
}
