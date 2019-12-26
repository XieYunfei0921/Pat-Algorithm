#include <iostream>
#include <queue>
using namespace std;
struct Node{
    int val;
    int layid;
    Node* lchild;
    Node* rchild;
};
Node* newNode(int x){
    Node* node=new Node;
    node->val=x;
    node->lchild=NULL;
    node->rchild=NULL;
    return node;
}
void insert(Node* &root,int x){
    if(root==NULL){
        root=newNode(x);
        return;
    }
    if(x>root->val)
        insert(root->rchild,x);
    else
        insert(root->lchild,x);
}
int maxn=-1,n1=0,n2=0;
void layerOrder(Node* root){
    if(root==NULL) return;
    queue<Node*> qs;
    root->layid=0;
    qs.push(root);
    while (!qs.empty()){
        Node* temp=qs.front();
        if(temp->layid>maxn)
            maxn=temp->layid;
        if(temp->lchild!=NULL) {temp->lchild->layid=temp->layid+1;qs.push(temp->lchild);}
        if(temp->rchild!=NULL) {temp->rchild->layid=temp->layid+1;qs.push(temp->rchild);}
        qs.pop();
    }
}
void inOrder(Node* root){
    if(root==NULL) return;
    inOrder(root->lchild);
    if(root->layid==maxn) n2++;
    if(root->layid==maxn-1) n1++;
    inOrder(root->rchild);
}
int main(int argc, char const *argv[]){
    int n,temp;
    cin>>n;
    Node* root=NULL;
    for (int i = 0; i < n; i++){
        cin>>temp;
        insert(root,temp);
    }
    layerOrder(root);
    inOrder(root);
    cout<<n2<<" + "<<n1<<" = "<<n1+n2;
    return 0;
}
