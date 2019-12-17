#include <iostream>
#include <algorithm>
#include <vector>
/*
    答案采取的是暴力插入法
*/
using namespace std;
struct Node{
    int val;
    Node* lchild;
    Node* rchild;
};
int arr[1000];
Node* newNode(int x){
    Node* node=new Node;
    node->val=x;
    node->lchild=NULL;
    node->rchild=NULL;
    return node;
}
bool flag=true;
Node* create(int L,int R){
    if(L>R) return NULL;
    if(L==R) return newNode(arr[L]);
    Node* root=new Node;
    root->val=arr[L];
    int index=-1;
    for (int i = L+1; i <= R; i++)
        if(arr[i]>=arr[L]){index=i;break;} 
    // BUG 段错误: 原因 数列在区间内单调
    if(index==-1) {flag=false;return NULL;}
    for (int i = index; i <= R; i++)
        if(arr[i]<arr[L]){flag=false;break;}
    root->rchild=create(index,R);
    root->lchild=create(L+1,index-1);
    return root;
}
Node* createMirror(int L,int R){
    if(L>R) return NULL;
    if(L==R) return newNode(arr[L]);
    Node* root=new Node;
    root->val=arr[L];
    if(arr[L+1]<arr[L]) flag=false;
    int index=-1;
    for (int i = L+1; i <= R; i++)
        if(arr[i]<arr[L])  {index=i;break;}
    if(index==-1){flag=false;return NULL;}
    for (int i = index; i <= R; i++){
        if(arr[i]>=arr[L]) {flag=false;break;}
    }
    root->rchild=createMirror(index,R);
    root->lchild=createMirror(L+1,index-1);
    return root;
}
vector<int> v;
void postOrder(Node* root){
    if(root==NULL) return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    v.push_back(root->val);
}
int main(int argc, char const *argv[]){
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    Node* root;
    if(arr[1]<arr[0])
        root=create(0,n-1);
    else
        root=createMirror(0,n-1);
    if(flag){
        std::cout << "YES" << "\n";
        postOrder(root);
        cout<<v[0];
        for (int i = 1; i < v.size(); i++)
            cout<<" "<<v[i];
    }else{
        std::cout << "NO" << std::endl;
    }
    return 0;
}
