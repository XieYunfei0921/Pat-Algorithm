#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
using namespace std;
int arr[101],index=0;
bool notRoot[101]={false};
struct Node{
    int val;
    int lchild;
    int rchild;
};
map<int,Node> mp;
void inOrder(int root){
    if(root==-1) return;
    inOrder(mp[root].lchild);
    mp[root].val=arr[index++];
    inOrder(mp[root].rchild);
}
void layOrder(int root){
    if(root==-1) return;
    queue<Node> qs;
    qs.push(mp[root]);
    cout<<mp[root].val;
    int cnt=0;
    while (!qs.empty())
    {
        Node temp=qs.front();
        if(cnt!=0)
            cout<<" "<<temp.val;
        if(temp.lchild!=-1){
            qs.push(mp[temp.lchild]);
            cnt++;
        }
        if(temp.rchild!=-1){
            cnt++;
            qs.push(mp[temp.rchild]);
        }
        qs.pop();
    }
}
int main(int argc, char const *argv[]){
    int n,lchild,rchild;   
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>lchild>>rchild;
        if(lchild!=-1)
            notRoot[lchild]=true;
        if(rchild!=-1)
            notRoot[rchild]=true;
        mp[i].lchild=lchild;
        mp[i].rchild=rchild;
    }
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    sort(arr,arr+n);
    int root=-1;
    for (int i = 0; i < n; i++)
        if(notRoot[i]==false) {root=i;break;}
    inOrder(root);
    layOrder(root);
    return 0;
}
