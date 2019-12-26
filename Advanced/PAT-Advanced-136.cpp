#include <iostream>
#include <map>
using namespace std;
struct Node{
    int id;
    string info;
    int lchild;
    int rchild;
};
map<int,Node> mp;
void inOrder(int root,int start){
    if(root==-1) return;
    if(!(mp[root].lchild==-1 && mp[root].rchild==-1) && root!=start)
        cout<<"(";
    inOrder(mp[root].lchild,start);
    cout<<mp[root].info;
    inOrder(mp[root].rchild,start);
    if(!(mp[root].lchild==-1 && mp[root].rchild==-1) && root!=start)
        cout<<")";
}
int father[22]={0};
int main(int argc, char const *argv[]){
    int n,lc,rc;
    string info;
    cin>>n;
    for (int i = 1; i <= n; i++){
        cin>>info>>lc>>rc;
        mp[i]=Node{i,info,lc,rc};
        if(lc!=-1)
            father[lc]=i;
        if(rc!=-1)
            father[rc]=i;
    }
    int start=1;
    while (father[start]!=0){
        start=father[start];
    }
    inOrder(start,start);
    return 0;
}