#include <iostream>
#include <algorithm>
using namespace std;
int n,arr[21];  
/*
    注意更新高度的策略
    已经需要将左右旋转最一般的情况考虑清楚,不要只考虑特例
*/
struct Node{
    int val;
    int height;
    Node* lchild;
    Node* rchild;
};
Node* newNode(int x){
    Node* node=new Node;
    node->val=x;
    node->lchild=NULL;
    node->rchild=NULL;
    node->height=1;
    return node;
}
int getHight(Node* root){
    if(root==NULL) return 0;
    return root->height;
}
void updateHeight(Node* root){
    root->height=max(getHight(root->lchild),getHight(root->rchild))+1;
}
void rightRotate(Node* &root){
    Node* temp=root->lchild;
    root->lchild=temp->rchild;
    temp->rchild=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
}
void leftRotate(Node* &root){
    Node* temp=root->rchild;
    root->rchild=temp->lchild;
    temp->lchild=root;
    updateHeight(root);
    updateHeight(temp);
    root=temp;
}
int getBalanceFactor(Node* root){
    return getHight(root->lchild)-getHight(root->rchild);
}
void insert(Node* &root,int x){
    if(root==NULL){
        root=newNode(x);
        return;
    }
    if(root->val>x){
        insert(root->lchild,x);
        updateHeight(root);
        if(getBalanceFactor(root)==2){
            // 左树高 LL/LR
            if(getBalanceFactor(root->lchild)==1)
                rightRotate(root);
            else{
                leftRotate(root->lchild);
                rightRotate(root);
            }
        }
    }else{
        insert(root->rchild,x);
        updateHeight(root);
        if(getBalanceFactor(root)==-2)
        {
            // 右树高 RL/RR
            if(getBalanceFactor(root->rchild)==1){
                rightRotate(root->rchild);
                leftRotate(root);
            }
            else
                leftRotate(root);
        }
    }
}
void inOrder(Node* root){
    if(root==NULL) return;
    inOrder(root->lchild);
    cout<<root->val<<" "<<root->height<<"\n";
    inOrder(root->rchild);
}
int main(int argc, char const *argv[]){
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>arr[i];
    }
    Node* root=NULL;
    for (int i = 0; i < n; i++){
        insert(root,arr[i]);
    }
    cout<<root->val;
    return 0;
}
