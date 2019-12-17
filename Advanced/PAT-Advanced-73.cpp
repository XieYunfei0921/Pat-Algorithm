#include <iostream>
#include <vector>
#include <cstring>
using namespace std;
vector<int> Adj[1000];
bool vis[1000];
// 遍历一条包含所有check数组中节点的路径,若是这条路径经过了删除的节点
// 遍历一个连通图
int deletedPoint;
void DFS(int source){
    if(source==deletedPoint) return;
    vis[source]=true;
    for (int i = 0; i < Adj[source].size(); i++){
        if(vis[Adj[source][i]]==false)
            DFS(Adj[source][i]);
    }
}
int main(int argc, char const *argv[]){
    int n,m,k,s,t;
    cin>>n>>m>>k;
    bool check[k]={false};
    for (int i = 0; i < m; i++){
        cin>>s>>t;
        Adj[s].push_back(t);
        Adj[t].push_back(s);
    }
    for (int i = 0; i < k; i++){
        cin>>deletedPoint;
        memset(vis,false,sizeof(vis));
        int block=0;
        for (int j = 1; j <=n; j++)
        {
            if(j!=deletedPoint && vis[j]==false){
                DFS(j);
                block++;
            }
        }
        cout<<block-1<<"\n";
    }
    return 0;
}
