#include <iostream>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

struct Node{
    int data;
    int num;
    // 存放子节点的编号
    vector<int> childs;
};
// 二叉查找树节点结构体
struct BSTNode{
    int val;
    int id;
    BSTNode* lchild;
    BSTNode* rchild;
};
/*
    当前根节点为NULL 查找失败
    当前根节点值为x,查找成功
    当前节点值小于x,查找左子树
    当前节点值大于x,查找右子树
*/
BSTNode* search(BSTNode* root,int x){
    if (root==NULL)
        return NULL;
    if(root->val==x) 
        return root;
    if(root->val<x)
        return search(root->rchild,x);
    if(root->val>x)
        return search(root->lchild,x);
}
BSTNode* newNode(int x){
    BSTNode* node=new BSTNode;
    node->val=x;
    node->lchild=NULL;
    node->rchild=NULL;
    return node;
}
void insert(BSTNode* &root,int x){
    if (root==NULL){
        std::cout << "Node val= "<<x << std::endl;
        root=newNode(x);
        root->lchild=NULL;
        root->rchild=NULL;
    }
    if(root->val<x)
        insert(root->rchild,x);
    if(root->val>x)
        insert(root->lchild,x);
}

void update(BSTNode* root,int x,int v){
    if (root==NULL)
        return;
    if(root->val==x){
        root->val=v;
    } 
    if(root->val<x)
        update(root->rchild,x,v);
    if(root->val>x)
        update(root->lchild,x,v);
}
/*
    寻找节点前驱/后继的方法
    递归寻找节点左子树的右子树=前驱 -->找到最大权值点
    递归寻找节点右子树的左子树=后继 --> 找到最小权值点
*/
BSTNode* findMax(BSTNode* root){
    while (root->rchild!=NULL)
    {
        root=root->rchild;
    }
    return root;
}

BSTNode* findMin(BSTNode* root){
    while (root->lchild!=NULL)
    {
        root=root->lchild;
    }
    return root;
}

void remove(BSTNode* &nodes,int x){
    BSTNode* root=search(nodes,x);
    if (root==NULL)
        return;
    int temp=0;
    BSTNode* t;
    if (root->rchild==NULL)
    {
        t=findMax(root->lchild);
    }else if(root->rchild!=NULL){
        t=findMin(root->rchild);
    }
    root->val=t->val;
    delete(t);
}

BSTNode* create(int data[],int n){
    BSTNode* root=NULL;
    for (int i = 0; i < n; i++)
    {   
        insert(root,data[i]);
    }
    return root;
}
void inorder(BSTNode* root){
    if (root==NULL)
        return;
    inorder(root->lchild);
    cout<<root->val<<" ";
    inorder(root->rchild);
}


int main(int argc, char const *argv[])
{
    int arr[7]={4,3,1,-2,9,6,5};
    BSTNode* root=create(arr,7);
    // 中序遍历
    inorder(root);
    remove(root,1);
    std::cout << "" << std::endl;
    inorder(root);
    return 0;
}
