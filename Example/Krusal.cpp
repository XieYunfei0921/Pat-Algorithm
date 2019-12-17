#include <algorithm>
#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
const int INF=999999;
struct Edge{
    int start;
    int end;
    int val;
};
struct Node{
    int val;
    int leftLen;
    int rightLen;
    Node* lchild;
    Node* rchild;
};

Node* newNode(int x){
    Node* node=new Node;
    node->val=x;
    node->leftLen=0;
    node->rightLen=0;
    node->lchild=NULL;
    node->rchild=NULL;
    return node;
}

void insert(Node* &root,int x){
    if (root==NULL)
    {
        root=newNode(x);
        return;
    }
    if (x>root->val)
        insert(root->rchild,x);
    else
        insert(root->lchild,x);
}

bool cmp(Edge e1,Edge e2){
    return e1.val<e2.val;
}
/*
    kruskal算法的实现
    初始状态各个点隐去边,单独作为连通块
    1. 将边按从小到大排序,并把测试的两个顶点放到一个连通块中,测试边加入最小生成树中
    2. 执行上一步骤,知道所有的点都放到了生成数组
    3. 若生成树中的节点等于初始节点数,则图连通
*/
// 寻找集合根结点用于判断是否输入一个连通图
const int MAXV=10010;
Edge graph[MAXV];
int father[MAXV];
int initial(int n){
    // 初始化血缘关系 共计n个节点
    for (int i = 0; i < n; i++)
    {
        father[i]=i;
    }
}
int findFather(int x)
{
    if(father[x]==x)
        return x;
    else
        return findFather(father[x]);
}
int merge(int start,int end){
    father[end]=start;
}

vector<Edge> kruskal(Edge edges[],int n,int num){
    // 初始化关系节点数n
    initial(n);
    sort(edges,edges+num,cmp);
    int front=0;
    int end=0;
    int val=0;
    vector<Edge> sides;
    // 定义集合的根结点编号
    for (int i = 0; i < num; i++)
    {
        front=edges[i].start;
        end=edges[i].end;
        val=edges[i].val;
        // 首位不在一个连通块中可以连接
        if(findFather(front)!=findFather(end)){
            // cout<<"front: "<<front<<"\tend: "<<end<< "\t";
            // cout<<"root front: "<<front<<" --> "<<father[front]<<"\troot end: "<<end<<" --> "<<father[end]<<"\n";
            merge(findFather(front),findFather(end));
            sides.push_back(edges[i]);
        }else
        {
            continue;
        }   
        // 判断是否取完所有的点
        if (sides.size()==n-1)
        {
            break;
        }
        // 判断图是否连通
    }
    if(sides.size()<n-1)
        std::cout << "给出的图不连通" << std::endl;
    return sides;
}

void initEdge(int start[],int end[],int val[],int num){
    for (int i = 0; i < num; i++)
    {
        graph[i]={start[i],end[i],val[i]};
    }
}

int main(int argc, char const *argv[])
{
    int start[10]={0,1,2,3,4,0,1,2,3,4};
    int end[10]={1,2,3,4,0,5,5,5,5,5};
    int val[10]={4,1,6,5,1,2,3,5,4,3};
    initEdge(start,end,val,10);
    vector<Edge> side=kruskal(graph,6,10);
    for (int i = 0; i < side.size(); i++)
    {
        cout<<side[i].start<<" --> "<<side[i].end<<"\t";
    }
    std::cout << "" << std::endl;
    for (int i = 0; i < 6; i++)
    {
        cout<<father[i]<<" ";
    }
    
    
    return 0;
}
