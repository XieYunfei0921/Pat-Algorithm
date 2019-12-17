#include <iostream>
#include <algorithm>
#include <cstdio>
#include <map>
#include <queue>
using namespace std;
/*
    TLE + 1 WA
    需要重构,降低代码的复杂度
*/
struct Node{
    int id;
    int layer;
    vector<int> followers;
};
map<int,Node> mp;
map<int,int> layers;
bool vis[1001]={false}; 
int n,l,k,kx,start,id;
int BFS(int source,int limit){
    queue<Node> qs;
    mp[source].layer=0;
    qs.push(mp[source]);
    int cnt=0;
    while (!qs.empty()){
        Node temp=qs.front();
        vis[temp.id]=true;
        layers[temp.layer]++;
        qs.pop();
        if(temp.layer<=limit){
            for (int i = 0; i < mp[temp.id].followers.size(); i++)
            {
                if(vis[mp[mp[temp.id].followers[i]].id]==false){
                    mp[mp[temp.id].followers[i]].layer=mp[temp.id].layer+1;
                    qs.push(mp[mp[temp.id].followers[i]]);
                }
            }
        }
    }
    for (map<int,int>::iterator i = layers.begin(); i != layers.end(); i++){
        if(i->first!=0 && i->first<=limit)
            cnt+=i->second;
    }
    layers.clear();
    return cnt;
}
void init(){
    for (int i = 1; i <= n; i++)
        mp[i].id=i;
}
int main(int argc, char const *argv[]){
    scanf("%d %d",&n,&l);
    init();
    for (int i = 1; i <= n; i++){
        scanf("%d",&k);
        for (int j = 0; j < k; j++){
            scanf("%d",&id);
            mp[id].followers.push_back(i);
        }
    }
    cin>>kx;
    for (int i = 0; i < kx; i++){
        scanf("%d",&start);
        printf("%d\n",BFS(start,l));
        fill(vis,vis+1001,false);
    }
    return 0;
}
