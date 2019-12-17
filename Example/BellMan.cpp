#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
const int MAXN=10010;
const int INF=999999;
bool vis[MAXN]={false};
int d[MAXN];
struct Node{
    int v;
    int dis;
};
vector<Node> Adj[MAXN];

int find(int line,int x){
    int index=-1;
    for (int i = 0; i < Adj[line].size(); i++)
    {
        if (Adj[line][i].v==x)
        {
            index=i;
            break;
        }
    }
    return index;
}
bool isEmpty(int u){
    for (int i = 0; i < Adj[u].size(); i++)
    {
        if (vis[Adj[u][i].v]==false)
        {
            return false;
        }
    }
    return true;
}

bool bellMan(int s,int n){
    vis[s]=true;
    d[s]=0;
    fill(d,d+n,INF);
    // 遍历所有边 i为边的终点编号
    // 为有权边赋值
    int MIN=INF,u=-1,v=-1;
    int uc=Adj[s].size();
    while (uc>0)
    {
        for (int j = 0; j < Adj[s].size(); j++)
        {
            if(Adj[s][j].dis<MIN && vis[Adj[s][j].v]==false){
                MIN=Adj[s][j].dis;
                u=Adj[s][j].v;
            }
        }
        if(vis[u]==false){
            d[u]=MIN;
            vis[u]=true;    
        }
        MIN=INF;
        int i=0;
        // 循环条件: u节点存在没有访问的节点v
        while(i<Adj[u].size() && !isEmpty(u))
        {   
            int v=Adj[u][i].v;
            if (vis[v]==true){
                i++;
                continue;
            }
            int sdis=INF;
            if(find(s,v)!=-1) 
                sdis=Adj[s][find(s,v)].dis;
            std::cout << "Index= "<<find(s,v)<<"\tsdis= "<<sdis << std::endl;
            if(d[u]+Adj[u][i].dis<sdis){
                d[v]=d[u]+Adj[u][i].dis;
            }
            else
            {
                d[v]=sdis;
            }
            u=v;
            vis[v]=true;
            MIN=INF;
        }
        uc--;
    }
    d[s]=0;
    // 访问u点
    // 判断是否有负环
    /*
        检查方案: 检查是否能够再被压缩
    */
   for (int i = 0; i < n; i++)
   {
       for (int j = 0; j < Adj[i].size(); j++)
       {
           int v=Adj[i][j].v;
           int dis=Adj[i][j].dis;
           if (d[i]+dis<d[v])
           {
               return false;
           }
       }
   }
   return true;
}

void SPFA(int s,int n){

}

void init(int start,int end,int val){
    Node node={end,val};
    Adj[start].push_back(node);
}

void initBatchLineMatrix(int line,int end[],int dis[],int index[],int n){
    for (int i = 0; i < n; i++)
    {
        init(line,i,INF);
    }
    for (int i = 0; i < n; i++)
    {
        // 获取索引号
        int id=index[i];
        Adj[line][id].v=end[i];
        Adj[line][id].dis=dis[i];
    }
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
    bool flag=bellMan(0,6);
    std::cout << "Flag= "<<flag << std::endl;
    for (int i = 0; i < 6; i++)
    {
        cout<<d[i]<<" ";
    }
    
    return 0;
}
