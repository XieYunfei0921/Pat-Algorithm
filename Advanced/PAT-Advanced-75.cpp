#include <iostream>
#include <cstdio>
#include <string>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;
/*
    有两处Bug
    点权和边权最好分开设置,避免不必要的逻辑转换
*/
struct Node{
    string pos;
    int val;
};
int n,k,times;
map<string,vector<Node> > Adj;
map<string,bool> vis;
map<string,int> sub;
priority_queue<string,vector<string>,greater<string> > ans;
// 遍历连通图,计算最大Gang
int cnt=0;
int maxLen=0;
int nums=0;
int block=0;
string toString(int x){
    string s="";
    while (x>0)
    {
        s+=x%10+'0';
        x/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}
void DFS(string s){
    for (int i = 0; i < Adj[s].size(); i++){
        if(vis[Adj[s][i].pos]==false){
            vis[Adj[s][i].pos]=true;
            cnt+=Adj[s][i].val;
            sub[s]+=Adj[s][i].val;
            sub[Adj[s][i].pos]+=Adj[s][i].val;
            DFS(Adj[s][i].pos);
        }
    }
}
void caculate(){
    int maxn=0;string start;
    for (map<string,int>::iterator i = sub.begin(); i != sub.end(); i++){
        if(i->second>maxn){
            maxn=i->second;
            start=i->first;
        }
    }
    if(sub.size()>2 && cnt>k){
        string s=start+" "+toString(sub.size());
        ans.push(s);
        block++;
    }
}
void reset(){
    cnt=0;
    sub.clear();
}
int main(int argc, char const *argv[]){
 
    scanf("%d %d",&n,&k);
    string s,t;
    set<string> temp;
    for (int i = 0; i < n; i++){
        cin>>s>>t>>times;
        Adj[s].push_back(Node{t,times});
        vis[s]=false;
        vis[t]=false;
        temp.insert(s);
        temp.insert(t);
    }
    // 计算连通图 
    for (set<string>::iterator i = temp.begin(); i != temp.end(); i++){
        if(vis[*i]==false){
            DFS(*i);
            caculate();
            reset();
        }
    }
    std::cout << block << std::endl;
    if(block!=0){
        while (!ans.empty()){
            cout<<ans.top()<<"\n";
            ans.pop();
        }
    }
    return 0;
}
