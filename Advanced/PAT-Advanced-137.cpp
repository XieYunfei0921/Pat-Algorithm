#include <iostream>
#include <cmath>
#include <queue>
#include <vector>
using namespace std;
struct Node{
    int id;
    int lchild;
    int rchild;
    int layer;
};
int toInt(string s){
    int num=0;
    for (int i = 0; i < s.length(); i++)
        num=num*10+s[i]-'0';
    return num;
}
Node nodes[21];
int layers[6]={0};
queue<int> qs;
vector<int> ans;
void layerOrder(int root){
    qs.push(root);
    ans.push_back(root);
    while (!qs.empty()){
        int temp=qs.front();
        if(nodes[temp].lchild!=-1){
            nodes[nodes[temp].lchild].layer=nodes[temp].layer+1;
            qs.push(nodes[temp].lchild);
            ans.push_back(nodes[temp].lchild);
        }
        if(nodes[temp].rchild!=-1){
            nodes[nodes[temp].rchild].layer=nodes[temp].layer+1;
            qs.push(nodes[temp].rchild);
            ans.push_back(nodes[temp].rchild);
        }
        qs.pop();
    }
}
int main(int argc, char const *argv[]){
    int n;string f,t;
    cin>>n;
    for (int i = 0; i < 21; i++)
        nodes[i].layer=0;
    int father[21];
    fill(father,father+21,-1);
    for (int i = 0; i < n; i++){
        cin>>f>>t;
        if(f=="-")
            nodes[i].lchild=-1;
        else{
            nodes[i].lchild=toInt(f);
            father[toInt(f)]=i;
        }
        if(t=="-")
            nodes[i].rchild=-1;
        else{
            nodes[i].rchild=toInt(t);
            father[toInt(t)]=i;
        }
    }
    int start=0;
    while (father[start]!=-1) {
        start=father[start];
    }
    layerOrder(start);
    int maxn=-1;
    for (int i = 0; i < 21; i++){
        if(nodes[i].layer)
            maxn=nodes[i].layer;
        layers[nodes[i].layer]++;
    }
    bool flag=true;
    int be=pow(2,maxn-1);
    for (int i = 1; i+1 < ans.size(); i++){
        if(father[ans[i]]!=ans[(i-1)/2]){
            flag=false;
            break;
        }
    }
    if(flag) cout<<"YES "<<ans[ans.size()-1];
    else cout<<"NO "<<start;    
    return 0;
}