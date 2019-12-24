#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int MAXN=10010;
struct Edge{
    int start;
    int des;
};
int vis[MAXN]={0};
map<int,int> mp;
bool equal(Edge e1,Edge e2){
    if(e1.des==e2.des && e2.start==e1.start) return true;
    if(e1.des==e2.start && e1.start==e2.des) return true;
    return false;
}
vector<Edge> Adj[MAXN];
int main(int argc, char const *argv[]){
    int n,m,fr,to;
    cin>>n>>m;
    for (int i = 0; i < m; i++){
        cin>>fr>>to;
        Adj[fr].push_back(Edge{fr,to});
        Adj[to].push_back(Edge{to,fr});
        int id=min(fr,to)*n+max(fr,to);
        mp[id]++;
    }
    int k,nums,temp;
    cin>>k;
    for (int i = 0; i <k; i++){
        map<int,int> temps=mp;
        cin>>nums;
        for (int j = 0; j < nums; j++){
            cin>>temp;
            for (int tt = 0; tt < Adj[temp].size(); tt++){
                int id=min(Adj[temp][tt].start,Adj[temp][tt].des)*n+
                max(Adj[temp][tt].start,Adj[temp][tt].des);
                if(temps.count(id)>0)
                    temps[id]--;
            }
        }
        bool flag=true;
        for (map<int,int>::iterator j = temps.begin(); j != temps.end(); j++){
            if(j->second>0) {flag=false;break;}
        }
        if(!flag) cout<<"No"<<"\n";
        else cout<<"Yes"<<"\n";
    }
    return 0;
}
