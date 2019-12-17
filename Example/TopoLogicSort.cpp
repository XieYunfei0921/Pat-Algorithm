#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int MAXN=10010;
bool vis[MAXN]={false};
// 代表每个节点的入度
int degree[MAXN];

struct Node{
    int id;
    int val;
    friend bool operator<(Node n1,Node n2){
        return n1.id<n2.id;
    }
};
queue<int> ids;
vector<Node> Adj[MAXN];
void init(int line,int ids[],int val[],int n){
    for (int i = 0; i < n; i++)
    {   
        Node node={ids[i],val[i]};
        Adj[line].push_back(node);
        degree[ids[i]]+=1;
    }
}

void logicSort(int n){
    // 已经初始化好了各个节点的degree
    for (int i = 0; i < n; i++)
    {
        if (degree[i]==0)
        {
            ids.push(i);
        }
    }
    while (!ids.empty())
    {
        int id=ids.front();
        vis[id]=true;
        cout<<id<<" ";
        // 更新邻接节点的度
        // 如何度为0则放到队列中等待访问
        for (int i = 0; i < Adj[id].size(); i++)
        {   
            int pos=Adj[id][i].id;
            if(vis[pos]==false){
                degree[pos]-=1; 
                if (degree[pos]==0)
                    ids.push(pos);
            }
        }
        ids.pop();
    }
}



int main(int argc, char const *argv[])
{
    int a[2][2]={{1,2},{3,1}};
    int b[2][2]={{3,-1},{2,-1}};
    int c[2][2]={{3,4},{2,4}};
    int d[2][2]={{4,-1},{1,-1}};
    int e[2][2]={{2,4},{2,5}};
    init(0,a[0],a[1],2);
    init(1,b[0],b[1],1);
    init(2,c[0],c[1],2);
    init(3,d[0],d[1],1);
    init(4,NULL,NULL,0);
    init(5,e[0],e[1],2);
    std::cout << "" << std::endl;
    logicSort(6);
    return 0;
}