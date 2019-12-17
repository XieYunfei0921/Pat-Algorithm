#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <vector>
using namespace std;
struct Node{
    int cityId;
    int val;
    int cost;
};
int getID(string s){
    return (s[0]-'A')*26*26+(s[1]-'A')*26+(s[2]-'A');
}
string getName(int n){
    string s="AAA";
    s[0]=n/(26*26)+'A';
    s[1]=n%(26*26)/26+'A';
    s[2]=n%26+'A';
    return s;
}
const int INF=100000000;
const int MAXN=20000;
int n,k,val,cost;string org,st,ed,c;
vector<Node> Adj[MAXN];
vector<int> nodes;
vector<int> pre[MAXN];
// 最终路径
vector<int> path,temp;
bool vis[MAXN]={false};
int ds[MAXN];
int maxHappy=-1;
int avg;
int routes=0;
map<int,Node> mp;
void Dijkstra(int s){
    fill(ds,ds+MAXN,INF);
    fill(vis,vis+MAXN,false);
    ds[s]=0;
    for (int i = 0; i < nodes.size(); i++)
    {
        int u=-1,MIN=INF;
        for (int j = 0; j < nodes.size(); j++){
            if(vis[nodes[j]]==false && ds[nodes[j]]<MIN){
                u=nodes[j];
                MIN=ds[u];
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for (int v = 0; v < Adj[u].size(); v++){
            if(vis[Adj[u][v].cityId]==false && ds[u]+Adj[u][v].cost<ds[Adj[u][v].cityId]){
                ds[Adj[u][v].cityId]=ds[u]+Adj[u][v].cost;
                pre[Adj[u][v].cityId].clear();
                pre[Adj[u][v].cityId].push_back(u);
            }else if(vis[Adj[u][v].cityId]==false && ds[u]+Adj[u][v].cost==ds[Adj[u][v].cityId]){
                pre[Adj[u][v].cityId].push_back(u);
            }
        }
    }
}
void DFS(int s){
    if(s==getID(org)){
        routes++;
        temp.push_back(getID(org));
        int total=0,cnt=0;
        for (int i = temp.size()-1; i >=0; i--){
            total+=mp[temp[i]].val;
            cnt++;
        }
        if(total>maxHappy){
            maxHappy=total;
            avg=maxHappy/(cnt-1);
            path=temp;
            reverse(path.begin(),path.end());
        }
        temp.pop_back();
        return;
    }
    temp.push_back(s);
    for (int i = 0; i < pre[s].size(); i++)
        DFS(pre[s][i]);
    temp.pop_back();
}
int main(int argc, char const *argv[])
{
    cin>>n>>k>>org;
    nodes.push_back(getID(org));
    for (int i = 1; i < n; i++){
        cin>>c>>val;
        // 赋值点权
        mp[getID(c)].cityId=getID(c);
        mp[getID(c)].val=val;
        nodes.push_back(getID(c));
    }
    for (int i = 0; i < k; i++){
        cin>>st>>ed>>cost;
        mp[getID(ed)].cost=cost;
        mp[getID(st)].cost=cost;
        Adj[getID(st)].push_back(mp[getID(ed)]);
        Adj[getID(ed)].push_back(mp[getID(st)]);
    }
    Dijkstra(getID(org));
    DFS(getID("ROM"));
    cout <<routes<<" "<< ds[getID("ROM")]<<" "<<maxHappy<<" "<<avg<<"\n";
    cout<<getName(path[0]);
    for (int i = 1; i < path.size(); i++)
        cout<<"->"<<getName(path[i]);
    return 0;
}
