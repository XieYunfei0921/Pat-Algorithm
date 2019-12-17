#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
struct Node{
    int pos;
    // 边权
    int dist;
    // 边权
    int cost;
};
const int MAXN=505;
const int INF=100000000;
int maxCost=1000000000;
bool vis[MAXN]={false};
// vector<Node> Adj[MAXN];
map<int,Node> Adj[MAXN];
// 前驱列表
vector<int> pre[MAXN];
int ds[MAXN];
vector<int> temp,ans;
int n,m,s,d,fr,des,len,val;
void Dijkstra(int s){
    fill(ds,ds+MAXN,INF);
    ds[s]=0;
    for (int i = 0; i < n; i++){
        int u=-1,MIN=INF;
        for (int j = 0; j < n; j++){
            if(vis[j]==false && ds[j]<MIN){
                u=j;
                MIN=ds[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;
        // TODO 优化
        for (map<int,Node>::iterator v = Adj[u].begin(); v != Adj[u].end(); v++){
            int id=Adj[u][v->first].pos;
            if(vis[id]==false && ds[u]+Adj[u][v->first].dist<ds[id]){
                ds[id]=ds[u]+Adj[u][v->first].dist;
                // 记录路径
                pre[id].clear();
                pre[id].push_back(u);
            }else if(vis[id]==false && ds[u]+Adj[u][v->first].dist==ds[id]){
                // 记录路径
                pre[id].push_back(u);
            }
        }
    }
}
// 遍历最短路径,求出最小边权和
void DFS(int st,int ed){
    if(ed==st){
        // 寻找到了头节点处理方法
        temp.push_back(st);
        int costs=0;
        for (int i = temp.size()-1; i >=1; i--)
            costs+=Adj[temp[i]][temp[i-1]].cost;
        if(costs<maxCost){
            maxCost=costs;
            ans=temp;
            reverse(ans.begin(),ans.end());
        }
        temp.pop_back();
        return;
    }
    temp.push_back(ed);
    for (int i = 0; i < pre[ed].size(); i++)
        DFS(st,pre[ed][i]);
    temp.pop_back();
}

int main(int argc, char const *argv[]){
    scanf("%d %d %d %d",&n,&m,&s,&d);
    for (int i = 0; i < m; i++){
        scanf("%d %d %d %d",&fr,&des,&len,&val);
        Adj[fr][des]=Node{des,len,val};   
        Adj[des][fr]=Node{fr,len,val};
    }
    Dijkstra(s);
    DFS(s,d);
    printf("%d",ans[0]);
    for (int i = 1; i < ans.size(); i++)
        printf(" %d",ans[i]);
    printf(" %d %d",ds[d],maxCost);
    return 0;
}
