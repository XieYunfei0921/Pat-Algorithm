#include <cstdio>
#include <vector>
#include <set>
#include <map>
using namespace std;
const int MAXN=10010;
bool flag=true;
bool vis[MAXN]={false};
vector<int> Adj[MAXN];
set<int> counters;
map<int,int> color;
void DFS(int start){
    vis[start]=true;
    counters.insert(color[start]);
    for (int i = 0; i < Adj[start].size(); i++){
        if(color[start]==color[Adj[start][i]]){
            flag=false;
            return;
        }
    }
    for (int i = 0; i <  Adj[start].size(); i++)
        if(vis[Adj[start][i]]==false) DFS(Adj[start][i]);
}
void reset(){
    flag=true;
    color.clear();
    counters.clear();
    fill(vis,vis+MAXN,false);
}
int main(int argc, char const *argv[]){
    int n,m,st,ed;
    scanf("%d %d",&n,&m);
    for (int i = 0; i < m; i++){
        scanf("%d %d",&st,&ed);
        Adj[st].push_back(ed);
        Adj[ed].push_back(st);
    }
    int k,cl;
    scanf("%d",&k);
    for (int i = 0; i < k; i++){
        for (int j = 0; j < n; j++){
            scanf("%d",&cl);
            color[j]=cl;
        }
        DFS(0);
        if(flag) printf("%d-coloring\n",counters.size());
        else printf("No\n");
        reset();
    }
    return 0;
}
