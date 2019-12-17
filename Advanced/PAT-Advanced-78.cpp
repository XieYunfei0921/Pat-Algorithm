#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN=505;
const int INF=100000000;
int d[MAXN];
bool vis[MAXN]={false};
int minNeed=100000000;
int minRemain=100000000;
struct Node{
    int id;
    // 点权(容量)
    int capcity;
    // 边权
    int dis;
};
vector<Node> Adj[MAXN];
vector<int> pre[MAXN];
vector<int> tempPath,path;
// 点权最大值(容量),站点数,问题站点编号(PMBC是0，其余编号1-N)，m路径数量
int c,n,sp,m,st,ed,len;
int pit[MAXN+1];
void Dijkstra(int start){
    fill(d,d+MAXN,INF);
    fill(vis,vis+MAXN,false);
    d[start]=0;
    for (int i = 0; i <= n; i++)
    {
        // 找到路径最近的节点
        int u=-1,MIN=INF;
        for (int j = 0; j <= n; j++){
            if(vis[j]==false && d[j]<MIN){
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;
        // 优化u的邻接节点
        // 寻找时需要记录路径
        /*
            最短路径生成:   
                有并列则添加，
                无并列则替换
        */
        for (int v = 0; v < Adj[u].size(); v++){
            if(vis[Adj[u][v].id]==false && Adj[u][v].dis+d[u]<d[Adj[u][v].id]){
                d[Adj[u][v].id]=Adj[u][v].dis+d[u];
                pre[Adj[u][v].id].clear();
                pre[Adj[u][v].id].push_back(u);
            }else if(vis[Adj[u][v].id]==false && Adj[u][v].dis+d[u]==d[Adj[u][v].id]){
                pre[Adj[u][v].id].push_back(u);
            }
        }
    }
}
// TODO 选择最优路径
/*
    使用DFS统计各条最短路径点权和
    优化最小补给量
*/
void DFS(int pos){
    if(pos==0){
        // 找到PMBC的处理工作
        tempPath.push_back(pos);
        int need=0,remain=0;
        for (int i = tempPath.size()-2; i >=0; i--){    
            // 对路径中的节点求点权和
            int id=tempPath[i];
            if(pit[id]-c/2>0){
                // 不足则补
                remain+=pit[id]-c/2;
            }else{
                // 不足一半容量,需要补充
                // 足够补给
                if(remain>abs(pit[id]-c/2)){
                    remain-=abs(pit[id]-c/2);
                }else{
                    //不够补给
                    need+=abs(pit[id]-c/2)-remain;
                    remain=0;
                }
            }
        }
        if(need<minNeed){
            minNeed=need;
            minRemain=remain;
            path=tempPath;
        }else if(need==minNeed && remain<minRemain){
            minRemain=remain;
            path=tempPath;
        }
        tempPath.pop_back();
        return;
    }
    // 路径处理
    tempPath.push_back(pos);
    for (int i = 0; i < pre[pos].size(); i++){
        DFS(pre[pos][i]);
    }
    tempPath.pop_back();
}

int main(int argc, char const *argv[])
{   
    scanf("%d %d %d %d",&c,&n,&sp,&m);
    // 输入1-N的当前容量 点权
    int base=c/2;
    for (int i = 1; i <= n; i++)
        scanf("%d",&pit[i]);
    for (int i = 0; i < m; i++){
        scanf("%d %d %d",&st,&ed,&len);
        Adj[st].push_back(Node{ed,pit[ed],len});
        Adj[ed].push_back(Node{st,pit[st],len});
    }
    Dijkstra(0);
    DFS(sp);
    printf("%d ",minNeed);
    for (int i = path.size()-1; i >=0 ; i--){
        printf("%d",path[i]);
        if(i>0) printf("->");
    }
    printf(" %d",minRemain);
    return 0;
}
