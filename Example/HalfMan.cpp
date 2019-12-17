#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

struct Node{
    int v;
    Node* lchild;
    Node* rchild;
    bool cmp(Node* n){
        return n->v>this->v;
    }
};

Node* newNode(int x){
    Node* node=new Node;
    node->v=x;
    node->lchild=NULL;
    node->rchild=NULL;
    return node;
}
// 左节点n1 右节点n2 n1<n2
Node* merge(Node* n1,Node* n2){
    Node* node=new Node;
    node->v=n1->v+n2->v;
    node->lchild=n1;
    node->rchild=n2;
    return node;
}

priority_queue<Node*> ss;
void init(int data[],int n){
    for (int i = 0; i < n; i++)
    {   
        ss.push(newNode(data[i]));
    }
}

Node* halfManTree(){
    Node* node;
    while (ss.size()!=1)
    {   
        Node* n1=ss.top();
        ss.pop();
        Node* n2=ss.top();
        ss.pop();
        node=merge(n1,n2);
        ss.push(node);
        std::cout << "size= "<<ss.size() << std::endl;
    }
    return node; 
}
queue<Node*> qs;
void layerOrder(Node* root){
    qs.push(root);
    while (!qs.empty())
    {   
        Node* node=qs.front();
        std::cout <<node->v  << " ";
        if(node->lchild!=NULL) qs.push(node->lchild);
        if(node->rchild!=NULL) qs.push(node->rchild);
        qs.pop();
    }
}


int main(int argc, char const *argv[])
{
    int arr[5]={6,3,2,2,1};
    init(arr,5);
    Node* node=halfManTree();
    layerOrder(node);
    return 0;
}
