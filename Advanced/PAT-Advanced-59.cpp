#include <iostream>
#include <algorithm>
#include <map>
#include <queue>
#include <vector>
using namespace std;
vector<int> v;
struct Node{
    int id;
    int lchild;
    int rchild;
};
map<int,Node> nm;
int toInt(string s){
    int num=0;
    for (int i = 0; i < s.length(); i++)
        num=num*10+s[i]-'0';
    return num;
}
void inOrder(Node root){
    //先访问右节点根左节点
    if(root.id==-1)
        return;
    if(root.rchild!=-1)
        inOrder(nm[root.rchild]);
    v.push_back(root.id);
    if(root.lchild!=-1)
        inOrder(nm[root.lchild]);
}
int main(int argc, char const *argv[])
{
    int n;
    char lc,rc;int l,r;
    cin>>n;
    bool isRoot[n]={false};
    for (int i = 0; i < n; i++){
        cin>>lc>>rc;
        l=lc=='-'?-1:lc-'0';
        r=rc=='-'?-1:rc-'0';
        if(l>=0) isRoot[l]=true;
        if(r>=0) isRoot[r]=true;    
        nm[i]=Node{i,l,r};
    }
    int num=-1;
    for (int i = 0; i < n; i++)
        if(isRoot[i]==false){num=i;break;}
    Node nx=nm[num];
    queue<Node> qs;
    qs.push(nx);
    int cnt=0;
    while (!qs.empty())
    {
        Node temp=qs.front();
        if(cnt==0)
            cout<<temp.id;
        else
            cout<<" "<<temp.id;
        if(temp.rchild!=-1)
            qs.push(nm[temp.rchild]);
        if(temp.lchild!=-1)
            qs.push(nm[temp.lchild]);
        qs.pop();
        cnt++;
    }
    cout<<"\n";
    inOrder(nx);
    cout<<v[0];
    for (int i = 1; i < v.size(); i++)
        cout<<" "<<v[i];   
    return 0;
}
