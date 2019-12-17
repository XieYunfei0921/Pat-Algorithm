#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
using namespace std;
const int MAXN=1020;
const int INF=100000000;
struct Node{
    int id;
    int dist;
};
// 房子总数,气站数量,路的数量,气站的最大服务范围 编号 房子1-N 气站G1-GM
/*
    有一处Bug
*/
int n,m,k,ds,dis;
string fr,ed;
vector<Node> Adj[MAXN];
bool vis[MAXN]={false};
int d[MAXN];
int id=2000;
float mini=-1;
float suma=INF;
// 单源点的Dijkstra
int toInt(string s){
    int num=0;
    if(s[0]=='G'){
        for (int i = 1; i < s.length(); i++)
            num=num*10+s[i]-'0';
        num=num+n;
    }else{
        for (int i = 0; i < s.length(); i++)
            num=num*10+s[i]-'0';
    }
    return num;
}
void Dijkstra(int s,int num){
    fill(vis,vis+MAXN,false);
    fill(d,d+MAXN,INF);
    d[s]=0;
    for (int i = 1; i <= num; i++){
        int u=-1,MIN=INF;
        for (int j = 1; j <= num; j++){
            if(d[j]<MIN && vis[j]==false){
                u=j;
                MIN=d[j];
            }
        }
        if(u==-1) return;
        vis[u]=true;
        for (int v = 0; v < Adj[u].size(); v++){
            if(vis[Adj[u][v].id]==false && d[u]+Adj[u][v].dist<d[Adj[u][v].id]){
                d[Adj[u][v].id]=d[u]+Adj[u][v].dist;
            }
        }
    }
    int minu=INF,sum=0;
    for (int i = 1; i <= n; i++){
        if(d[i]>ds) return;
        if(minu>d[i])
            minu=d[i];
        sum+=d[i];
    }
    // 比较获得结果
    if(mini<minu){
        id=s;
        suma=sum;
        mini=minu;
    }else if(minu==mini && suma>sum){
        id=s;
        mini=minu;
        suma=sum;
    }else if(minu==mini && suma==sum && s<id){
        id=s;
        mini=minu;
        suma=sum;
    }
    
}
int main(int argc, char const *argv[]){
    set<int> list;
    scanf("%d %d %d %d",&n,&m,&k,&ds);
    int maxnum=-1;
    for (int i = 0; i < k; i++){
        cin>>fr>>ed>>dis;
        if(max(toInt(fr),toInt(ed))>maxnum)
            maxnum=max(toInt(fr),toInt(ed));
        if(toInt(fr)>n)
            list.insert(toInt(fr));
        if(toInt(ed)>n)
            list.insert(toInt(ed));
        Adj[toInt(fr)].push_back(Node{toInt(ed),dis});
        Adj[toInt(ed)].push_back(Node{toInt(fr),dis});
    }
    for (set<int>::iterator i = list.begin(); i != list.end(); i++){
        Dijkstra(*i,maxnum);
        // 计算最小平均距离以及最小距离指标
    }
    if(id==2000){
        printf("No solution\n");
        return 0;
    }

    printf("G%d\n",id-n);
    printf("%.1f ",mini);
    printf("%.1f",suma/n);
    return 0;
}
