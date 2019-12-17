#include <iostream>
#include <math.h>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;
const int maxn=10010;
struct Node{
    // 数据域
    // 相连节点编号
    int id;
    // 权值
    int value;
    // 方向 指出1,指入-1,无向0
    int direct;
    // 指针域
    Node* next(){
        Node* n=new Node;
        return n;
    }
};

vector<int> Adj[maxn];
bool vis[maxn]={false};
// 获取一个节点开头的连通图 
/*  
    邻接表法:
    u: 节点编号
    n: 遍历深度/边的数量
*/
void DFS(int u,int n){
    vis[u]=true;
    // 枚举u所能到达的所有节点v
    // Node* nodes=Adj[u];
    for (int i = 0; i < Adj[u].size(); i++)
    {
        int v=Adj[u][i];
        std::cout <<"Node: "<<u<< "\tSide: "<<u<<"--> "<<v << std::endl;
        if(vis[v]==false){
            DFS(v,n+1);
        }
    }
}
// 获取所有节点开头的连通图 
/*
    point: 点的数量
*/
void travelAll(int points){
    for (int i = 0; i < points; i++)
    {   
        // 访问未被访问过的节点--> 换一个连通图
        if (vis[i]==false)
        {
            DFS(i,1);
        }
    }
}

/*
    邻接矩阵法:
    如何判断节点是否可以被DFS访问到:
        0. 对于未访问的节点j
        1. matrix[i][j]!=INF 说明i可以到达j节点
        2. 设置vis[i][j]=true表示这条边访问完成
        3. 访问的节点集合加入j节点,跳到matrix[j]一行,继续DFS,知道连通图里的所有点都访问完毕
*/
const int MAXV=1000;
const int INF=999999;
int G[MAXV][MAXV]={
        {0,2,0,0,1},
        {2,0,2,0,2},
        {0,2,0,1,0},
        {0,0,1,0,1},
        {1,2,0,1,0}
    };
/*
TODO 遍历以u开头的所有路径
    u: 当前节点编号
    depth: 遍历深度 --> 可转化为路径长度
    fail: 不可到达的数字标记
    num: 总结点数
    重设去重数组vism解决单向遍历问题
*/
bool vism[MAXV][MAXV]={false};

void matrixDFS(int u,int depth,int fail,int num){   
    // 去重方法 index=(depth-1)*m
    vism[u][u]=true;
    for (int i = 0; i < num; i++)
    {
        if (vism[u][i]==false && G[u][i]!=fail)
        {   
            vism[u][i]=true;
            vism[i][u]=true;
            std::cout << "Point: "<<u<<"\tLine: "<<u<<" --> "<<i << std::endl;
            matrixDFS(i,depth+1,fail,num);
        }
    }
}

void travelMatrix(int num){
    for (int i = 0; i < num; i++)
    {
        if (vis[i]==false)
        {
            matrixDFS(i,1,0,num);
        }
    }
}
/* 使用BFS遍历以BFS开头的节点
    邻接矩阵:   
        1. 得到G[u]中所有值不是INF的
        2. 将这些index加入队列,设置去重数组vism[u][i]=vism[i][u]=0
        3. 取出队列队首循环操作直至队列为空
*/
queue<int> qs;
void matrixBFS(int u,int num){
    qs.push(u);
    vism[u][u]=true;
    while (!qs.empty())
    {   
        cout<<qs.front()<<" ";
        for (int i = 0; i < num; i++)
        {
            // 寻找下一层次的节点,存入队列中
            if (vism[u][i]==false && G[u][i]!=0) 
            {
                vism[u][i]=true;
                vism[i][u]=true;
                qs.push(i);
            }
        }
        // 寻找完毕,拿出队首元素
        qs.pop();
        
    }
}

/*
    邻接表实现BFS:

*/
void BFS(int u,int num){
    qs.push(u);
    vis[u]=true;
    while (!qs.empty())
    {   
        std::cout << qs.front() << std::endl;
        for (int i = 0; i < Adj[u].size(); i++)
        {   
            if (vis[i]==false && Adj[u][i]!=0)
            {
                vis[i]=true;
                qs.push(i);
            }
        }
        qs.pop();
    }
}

void travelBFS(int num){
    for (int i = 0; i < num; i++)
    {
        if (vis[i]==false)
        {   
            BFS(i,num);
            std::cout << "" << std::endl;
        }
    }
}

// 遍历图中的所有节点,假设节点编号按顺序增大
// 因此遇到多个连通图的图需进一步处理
void travelMatrixBFS(int num){
    for (int i = 0; i < num; i++)
    {
        if (vism[i][i]==false)
        {
            matrixBFS(i,num);
            std::cout << "" << std::endl;
        }
    }
    
}


// 图结构基本实践
int main(int argc, char const *argv[])
{
    // 使用邻接矩阵实现图结构
    // travelMatrix(5);
    // travelMatrixBFS(5);
    // 使用邻接表实现图结构 5个节点
    Adj[0].push_back(1);
    Adj[0].push_back(4);
    Adj[1].push_back(0);
    Adj[1].push_back(2);
    Adj[1].push_back(4);
    Adj[2].push_back(1);
    Adj[2].push_back(3);
    Adj[3].push_back(2);
    Adj[3].push_back(4);
    Adj[4].push_back(0);
    Adj[4].push_back(1);
    Adj[4].push_back(3);
    // travelAll(5);
    travelBFS(5);
    return 0;
}
