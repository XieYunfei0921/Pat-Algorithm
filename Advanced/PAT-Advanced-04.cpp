#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int INF=1000000000;
struct Node{
    int des;
    int len;
    int calls;
};
bool cmp(Node n1,Node n2){
    if(n1.len==n2.len) return n1.calls>n2.calls;
    return n1.len<n2.len;
}
int main(int argc, char const *argv[])
{
    int n,m,c1,c2,len,calls,start,finish;
    cin>>n>>m>>c1>>c2;
    vector<Node> Adj[n];
    int callNums[n];
    int d[n];
    bool vis[n]={false};
    fill(d,d+n,INF);
    for (int i = 0; i < n; i++)
    {
        cin>>calls;
        callNums[i]=calls;
    }
    for (int i = 0; i < m; i++)
    {
        cin>>start>>finish>>len;
        Adj[start].push_back(Node{finish,len,callNums[start]});
    }
    int total=0,paths=1,totalPath=1,totalCalls=0;
    int maxPath=0,maxCalls=0;
    for (int i = 0; i < n; i++)
        sort(Adj[i].begin(),Adj[i].end(),cmp);
    int u,v;Node nu,nv;
    d[c1]=0;
    for (int i = 0; i < Adj[c1].size(); i++)
        d[Adj[c1][i].des]=d[Adj[c1][i].des]<INF?d[Adj[c1][i].des]:INF;
    totalCalls+=callNums[c1];
    for (int i = 0; i < Adj[c1].size(); i++)
    {   
        nu=Adj[c1][i];
        u=Adj[c1][i].len;
        totalCalls+=nu.calls;
        if(vis[u]==false)
            vis[u]=true;
        else 
            continue;
        for (int j = 0; j < Adj[u].size(); j++)
        {
            nv=Adj[u][j];
            v=Adj[u][j].des;
            if(vis[v]==true) continue;
            if(vis[v]==false && Adj[c1][u].len+Adj[u][v].len<d[v]){
                d[v]=Adj[c1][u].len+Adj[u][v].len;
                paths=1;
                vis[v]==true;
            }
            if(vis[v]==false && Adj[c1][u].len+Adj[u][v].len==d[v]){
                paths=2;
                vis[true]=true;
            }
            totalCalls+=nv.calls;
            totalPath*=paths;
            if(v==c2){
                maxPath=max(maxPath,totalPath);
                maxCalls=max(maxCalls,totalCalls);
                totalPath=1;
                totalCalls=callNums[c1];
                break;
            }
            nu=nv;
            u=v;
        }
    }
    std::cout << maxPath<<" "<<maxCalls << std::endl;
    return 0;
}
