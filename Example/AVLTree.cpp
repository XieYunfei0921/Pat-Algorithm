#include <iostream>
#include <math.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct Node{
    int v;
    int height;
    Node* lchild;
    Node* rchild;
};

int getHeight(Node* root){
    if(root==NULL)
        return 0;
    else
        return root->height;
}
int getFactor(Node* root){
    return getHeight(root->lchild)-getHeight(root->rchild);
}
void updateHeight(Node* root){
    root->height=max(getHeight(root->lchild),getHeight(root->rchild))+1;
}

Node* newNode(int x){
    // 越靠近叶子节点,数的高度越低
    Node* node=new Node;
    node->v=x;
    node->height=1;
    node->lchild=NULL;
    node->rchild=NULL;
    return node;
}
Node* search(Node* root,int x){
    if (root==NULL)
        return NULL;
    if(root->v==x)
        return root;
    if (root->v<x)
        return search(root->rchild,x);
    if(root->v>x)
        return search(root->lchild,x);
}
/*
    二叉查找树的左旋 [现根节点变成右儿子的左儿子]
    1. 右子树的左子树变成源根节点的右子树
    2. 源根节点变成右儿子的左儿子
    3. 返回新根节点
*/
void leftRotate(Node* &root){
    Node* node=root->rchild;
    root->rchild=node->lchild;
    node->lchild=root;
    updateHeight(root);
    updateHeight(node);
    root=node;
}
void rightRotate(Node* &root){
    Node* node=root->lchild;
    root->lchild=node->rchild;
    node->rchild=root;
    updateHeight(root);
    updateHeight(node);
    root=node;
}

Node* balance(Node* &root){
    int factor=getFactor(root);
    switch (factor)
    {
    case 2:
        {
            if(getFactor(root->lchild)==1)
                rightRotate(root);
            else if(getFactor(root->lchild)==-1){
                leftRotate(root->lchild);
                rightRotate(root);
            }
        }
    break;
    case -2: 
        {
            if(getFactor(root->rchild)==1){
                rightRotate(root->rchild);
                leftRotate(root);
            }
            else if(getFactor(root->rchild)==-1){
                leftRotate(root);
            }   
        }
    default:
        break;
    }
    return root;
}

void insert(Node* &root,int x){
    if (root==NULL)
    {
        root=newNode(x);
        return;
    }
    if (root->v<x)
    {
        insert(root->rchild,x);
        updateHeight(root);
        balance(root);
    }else
    {
        insert(root->lchild,x);
        updateHeight(root);
        balance(root);
    }
}

Node* create(int data[],int n){
    Node* root=NULL;
    for (int i = 0; i < n; i++)
    {
        insert(root,data[i]);
    }
    return root;
}

queue<Node*> qs;
void layerOrder(Node* root){
    if (root==NULL)
        return;
    qs.push(root);
    Node* node;
    while (!qs.empty())
    {
        node=qs.front();
        std::cout << node->v << " ";
        if(node->lchild!=NULL)
            qs.push(node->lchild);
        if(node->rchild!=NULL)
            qs.push(node->rchild);
        qs.pop();
    }
}

void inorder(Node* root){
    if (root==NULL)
        return;
    inorder(root->lchild);
    cout<<root->v<<" ";
    inorder(root->rchild);
}

int main(int argc, char const *argv[])
{
    int arr[7]={1,6,-2,4,3,-1,-5};
    Node* root=create(arr,7);
    // 层序遍历
    layerOrder(root);
    std::cout << "" << std::endl;
    inorder(root);
    return 0;
}
