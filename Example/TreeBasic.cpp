#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;

struct Node{
    int data;
    // 节点编号最小为1,插入时使用
    int num;
    Node* lchild;
    Node* rchild;
    Node* newNode(int v,int num){
        Node* node=new Node;
        node->data=v;
        node->num=num;
        node->lchild=NULL;
        node->rchild=NULL;
        return node;
    }
    // 从根节点找
    bool search(Node* root,int x){
        if (root==NULL)
            return false;
        if(root->data==x)
            return true;
        search(root->lchild,x);
        search(root->rchild,x);
    }
    bool searchByIndex(Node* root,int x){
        if (root==NULL) 
            return false;
        if(root->num==x)
            return true;
        search(root->lchild,x);
        search(root->rchild,x);
    }
    void update(Node* &root,int x,int v){
        if (root==NULL)
            return;
        if(root->data==x){
            root->data=v;
            num++;
        }
        update(root->lchild,x,v);
        update(root->rchild,x,v);
    }
    void insert(Node* &root,int v,int num){
        if (root==NULL)
        {
            root=newNode(v,num);
            return;
        }
        // 根据题意插入左/右子树
        // std::cout <<"v= "<<v<< "\tnum= "<<num << std::endl; 
        if (num%2==0)
        {   
            insert(root->lchild,v,num);
        }else
        {
            insert(root->rchild,v,num);
        }
    }
    Node* createCompleteTree(int data[],int n){
        Node* root=newNode(data[0],1);
        for (int i = 1; i < n; i++)
        {
            insert(root,data[i],i+1);
        }
        return root;
    }
}node;

bool cmp(Node n1,Node n2){
    return n1.num>n2.num;
}

void showNextLine(Node* node){
    if (node==NULL)
        return;
    cout<<node->data<<" ";
    showNextLine(node->lchild);
    showNextLine(node->rchild);
}

void preorder(Node* root){
    // 先序遍历 根节点 左子树 右子树
    if(root==NULL)
        return;
    cout<<root->data<<" ";
    preorder(root->lchild);
    preorder(root->rchild);
}
void inorder(Node* root){
    if(root==NULL)
        return;
    preorder(root->lchild);
    cout<<root->data<<" ";
    preorder(root->rchild);
}
void postorder(Node* root){
    if(root==NULL)
        return;
    postorder(root->lchild);
    postorder(root->rchild);
    cout<<root->data<<" ";
}
void layerOrder(Node* root){
    queue<Node*> q;
    q.push(root);
    while (!q.empty())
    {
        Node* n=q.front();
        cout<<n->data<<" ";
        // 求一层节点
        if(n->lchild!=NULL) q.push(n->lchild);
        if(n->rchild!=NULL) q.push(n->rchild);
        q.pop();
    }
}

int main(int argc, char const *argv[])
{
    int arr[12]={7,2,4,6,1,2,5,8,9,-4,-2,0};
    Node* root=node.createCompleteTree(arr,12);
    // std::cout << root->lchild->data << std::endl;
    // sort(root,root+12,cmp);
    // showNextLine(root);
    preorder(root);
    std::cout << "" << std::endl;
    inorder(root);
    std::cout << "" << std::endl;
    postorder(root);
    std::cout << "" << std::endl;
    layerOrder(root);
    return 0;
}
