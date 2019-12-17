#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
using namespace std;
const int MAXV=10010;
const int INF=999999;
bool vis[MAXV]={false};
int d[MAXV];
struct Node{
    int id;
    int dis;
};
vector<Node> Adj[MAXV];

// TODO 找到与start最近未访问节点的编号
Node findMinDistanceId(int start){
    // index为节点编号
    Node node;
    int index=-1;
    int MIN=INF;
    for (int i = 0; i < Adj[start].size(); i++)
    {
        if(vis[Adj[start][i].id]==false && Adj[start][i].dis<MIN){
            MIN=Adj[start][i].dis;
            index=Adj[start][i].id;
        }
    }
    node.dis=MIN;
    node.id=index;
    return node;
}

int findDistance(int start,int end){
    int dis=INF;
    for (int i = 0; i < Adj[start].size(); i++)
    {
        if (Adj[start][i].id==end)
            dis=Adj[start][i].dis;
    }
    return dis;
}

vector<int> prim(int s,int n){
    fill(d,d+MAXV,INF);
    vector<int> ans;
    d[s]=0;
    vis[s]=true;
    ans.push_back(s);
    Node u,v;
    while(findMinDistanceId(s).id!=-1){
        u=findMinDistanceId(s);
        vis[u.id]=true;
        ans.push_back(u.id);
        d[u.id]=u.dis;
        while (findMinDistanceId(u.id).id!=-1)
        {
            v=findMinDistanceId(u.id);
            // 优化路径
            if (u.dis+v.dis<findDistance(s,v.id))
                d[v.id]=v.dis;   
            else
                d[v.id]=findDistance(s,v.id);
            vis[v.id]=true;
            ans.push_back(v.id);
            u=v;
        }
    }
    
    return ans;
}
void init(int start,int end,int val){
    Node node={end,val};
    Adj[start].push_back(node);
}
void initBatchLine(int line,int end[],int dis[],int n){
    for (int i = 0; i < n; i++)
    {
        init(line,end[i],dis[i]);
    }
}

int main(int argc, char const *argv[])
{   
    int a0[3]={1,3,4};
    int b0[3]={1,4,4};
    int a1[1]={3};
    int b1[1]={2};
    int a2[1]={5};
    int b2[1]={1};
    int a3[2]={2,4};
    int b3[2]={2,3};
    int a4[1]={5};
    int b4[1]={3};
    initBatchLine(0,a0,b0,3);
    initBatchLine(1,a1,b1,1);
    initBatchLine(2,a2,b2,1);
    initBatchLine(3,a3,b3,2);
    initBatchLine(4,a4,b4,1);
    vector<int> ans=prim(0,6);
    for (int i = 0; i < 6; i++)
    {
        cout<<d[i]<<" ";
    }
    std::cout << "" << std::endl;
    for (int i = 0; i < ans.size(); i++)
    {
        cout<<ans[i]<<" ";
    }
    
    
    return 0;
}
