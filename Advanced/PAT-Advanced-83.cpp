#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
    1 段错误
    3 答案错误
*/
struct Node{
    int val;
    Node* lchild;
    Node* rchild;
};
int n;
int pre[505];
vector<int> ans;
bool flag=true;
Node* DFSMAX(int low,int high,int arr[]){
    int fa=low;int ed=2*low;
    if(fa>high) return NULL;
    Node* root=new Node;
    root->val=arr[fa];
    if(flag){
        if(ed==high && arr[low]<arr[ed])
            flag=false;
        if(ed+1<=high && (arr[low]<arr[ed] || arr[low]<arr[ed+1]))
            flag=false;
    }
    root->rchild=DFSMAX(ed+1,high,arr);
    if(root->rchild!=NULL)
        pre[ed+1]=fa;
    root->lchild=DFSMAX(ed,high,arr);
    if(root->lchild!=NULL)
        pre[ed]=fa;
    if(root->lchild==NULL && root->rchild==NULL)
        ans.push_back(fa);
    return root;
}
Node* DFSMIN(int low,int high,int arr[]){
    int fa=low;int ed=2*low;
    if(fa>high) return NULL;
    Node* root=new Node;
    root->val=arr[fa];
    if(flag==true){
        if(ed==high && arr[fa]>arr[ed]){
            flag=false;
        }
        if(ed+1<=high && (arr[fa]>arr[ed] || arr[fa]>arr[ed+1])){
            flag=false;
        }
    }
    root->rchild=DFSMIN(ed+1,high,arr);
    if(root->rchild!=NULL)
        pre[ed+1]=fa;
    root->lchild=DFSMIN(ed,high,arr);
    if(root->lchild!=NULL)
        pre[ed]=fa;
    if(root->lchild==NULL && root->rchild==NULL)
        ans.push_back(fa);
    return root;
}

// 找到叶子节点集合,从头到尾输出他
vector<int> res;
void searchRoot(int root,int leaf,int arr[]){
    if(leaf==root){
        res.push_back(leaf);
        cout<<arr[res[res.size()-1]];
        for (int i = res.size()-2; i >=0; i--){
            cout<<" "<<arr[res[i]];
        }
        res.clear();
        return;
    }
    res.push_back(leaf);
    searchRoot(root,pre[leaf],arr);
}
int main(int argc, char const *argv[]){
    cin>>n;
    int temp[n+1];
    for (int i = 1; i <= n; i++)
        cin>>temp[i];
    Node* root;
    if(temp[1]>temp[2])
        root=DFSMAX(1,n,temp);
    else
        root=DFSMIN(1,n,temp);
    for (int i = 0; i < ans.size(); i++){
        searchRoot(1,ans[i],temp);
        cout<<"\n";
    }
    if(!flag)
        cout<<"Not heap"<<"\n";
    else if(flag==true && temp[1]>temp[2])
        cout<<"Max Heap"<<"\n";
    else
        cout<<"Min Heap"<<"\n";
    return 0;
}
