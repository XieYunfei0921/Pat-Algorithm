#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <queue>
using namespace std;
const int MAXV=10010;
int G[1000][1000];
bool vism[1000][1000];
bool vis[MAXV];
int INF=999999;
struct Node{
    //目标顶点
    int v;
    // 边权
    int dis;
    // 路径上上一个节点的编号
    int pre;
    // 重载运算符
    friend bool operator<(Node n1,Node n2){
        return n1.dis>n2.dis;
    }
};

priority_queue<Node> Adj[MAXV];
bool cmp(Node n1,Node n2){
    return n1.dis<n2.dis;
}


// 计算s为源点的最短路径长度以及最短路径
/*
    邻接表实现:
    s: 源点     编号0
    num: 节点数目,包括源点
    Dijkstra法思路:
    1. 选择未访问节点中与源点最近的节点访问,记作u
    2. 优化源点s到u所能到达节点的距离
    3. 访问未访问列表中下一个元素,知道所有节点访问完毕

    打印最短路径:
    使用并查集的思想
    设置一个数组,下标为路径目的地,一直向上找父亲,到s为止所有的集合就是路径
    但是需要注意这个只满足三次的图结构,再向上则需要使用递归将问题转化成3层问题
    此外，不限制层次的话，就必须要指定路径结尾编号
*/
int d[MAXV];
Node pre[MAXV];
void Dijkstra(int s,int num){
    fill(d,d+num,INF);
    Node u;
    Node vx;
    int cnt=0;
    while (!Adj[s].empty())
    {   
        // 选取u   
        u=Adj[s].top();
        int uid=u.v;
        if(d[uid]>u.dis){
            d[uid]=u.dis;
            pre[uid]=u;
        }
        // 优化一个u的所在的最短路径
        while (!Adj[uid].empty())
        {   
            // 获取邻接元素
            // 加入val满足松弛条件则val是最短路径上的一个点
            vx=Adj[uid].top();
            int val=vx.v;
            // 优化距离
            if (d[uid]+vx.dis<d[val]){
                vx.pre=u.v;
                pre[val]=vx;
                d[val]=d[uid]+vx.dis;
            }
            // 优化完毕，向下一层优化
            Adj[uid].pop();
            u=vx;
            // 删除元素
            uid=u.v;
        }
    
        Adj[s].pop();
    }
    d[s]=0;
}

/*
    邻接矩阵版  Dijkstra
*/
void MatrixDijkstra(int s){

}

void create(){

}

void init(int start,int end,int val){
    Node node={end,val};
    Adj[start].push(node);
}

void showPath(int s,int n){
    if(s==n)    
        cout<<n<<"\n";
    else
    {
        cout<<n<<" ";
        showPath(s,pre[n].pre);
    }
    
}

int main(int argc, char const *argv[])
{   
    init(0,1,1);
    init(0,3,4);
    init(0,4,4);
    init(1,3,2);
    init(2,5,1);
    init(3,2,2);
    init(3,4,3);
    init(4,5,3);
    Dijkstra(0,6);
    for (int i = 0; i < 6; i++)
    {
       std::cout << d[i] << "\t"; 
    }
    std::cout << "" << std::endl;

    int temp=-1;
    showPath(1,2);
    
    
    return 0;
}
