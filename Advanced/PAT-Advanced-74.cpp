#include <iostream>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <queue>
using namespace std;
// 节点访问次数数组 初始false可以访问
/*
    1. 当再次被访问时,此时状态为true,这时候需要标记状态flag=true:表示有环
    2. 连通图的计算
    3. N-1个点再一个连通图内部一定是一棵树  
        所以需要找出各个节点为根节点的最大深度
*/
struct Node{
    int id;
    int height;
    vector<int> sons;
};
vector<int> Adj[10001];
priority_queue<int,vector<int>,greater<int> > ans;
int cnt=0;
bool times[10001]={false};
void DFS(int source){
    times[source]=true;
    int f=true;
    for (int i = 0; i < Adj[source].size(); i++){
        if(times[Adj[source][i]]==false){
            DFS(Adj[source][i]);
            f=false;
        }
    }
    if(f || Adj[source].size()==0) 
        return;
}
// 由于是一棵树，不会形成环
int getHight(int start){
    // 当前节点高度=子节点最大高度+1
    int maxHeight=-1;bool flag=true;
    times[start]=true;
    for (int i = 0; i < Adj[start].size(); i++)
        if(times[Adj[start][i]]==false) {flag=false;break;}
    // std::cout << "Elements: "<<start<<"\tFlag= "<<flag << std::endl;
    if(flag) return 1;
    for (int i = 0; i < Adj[start].size(); i++){
        if(times[Adj[start][i]]==false){
            int cur=getHight(Adj[start][i]);
            if(cur>maxHeight)
                maxHeight=cur;
        }
    }
    return 1+maxHeight;
}
int main(int argc, char const *argv[])
{
    int n,s,t;
    scanf("%d",&n);
    for (int i = 0; i < n-1; i++){
        scanf("%d %d",&s,&t);
        Adj[s].push_back(t);
        Adj[t].push_back(s);
    }
    int block=0;
    for (int i = 1; i <= n; i++){
        if(times[i]==false){
            DFS(i);
            block++;
        }
    }
    int maxLen=0;
    int para[n+1];
    if(block==1){
        // 寻找各个节点开始的树高
        for (int i = 1; i <= n; i++)
        {
            fill(times,times+1+n,false);
            para[i]=getHight(i);
            if(para[i]>maxLen)
                maxLen=para[i];
        }
        for (int i = 1; i <= n; i++)
        {
            if(para[i]==maxLen)
                ans.push(i);
        }
        while (!ans.empty())
        {
            printf("%d\n",ans.top());
            ans.pop();
        }
    }else
        printf("Error: %d components",block);
    return 0;
}
