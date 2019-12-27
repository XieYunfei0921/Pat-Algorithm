#include <iostream>
#include <queue>
#include <stdio.h>
using namespace std;
struct Node{
    int val;
    int layer;
    Node* lchild;
    Node* rchild;
};
int n;
int inorder[32];
int postorder[32];
Node* deal(int ML,int MR,int PL,int PR){
    if(ML>MR || PL>PR) return NULL;
    Node* root=new Node;
    root->val=postorder[PR];
    int index=-1;
    for (int i = ML; i <= MR; i++)
        if(inorder[i]==postorder[PR]) {index=i;break;}
    int leftNums=index-ML;
    root->lchild=deal(ML,index-1,PL,PL+leftNums-1);
    root->rchild=deal(index+1,MR,PL+leftNums,PR-1);
}
vector<int> res[32];
void layerOrder(Node* root){
    if(root==NULL) return;
    queue<Node*> qs;
    root->layer=0;
    res[0].push_back(root->val);
    qs.push(root);
    while (!qs.empty()){
        Node* temp=qs.front();
        res[temp->layer].push_back(temp->val);
        if(temp->lchild!=NULL) {temp->lchild->layer=temp->layer+1;qs.push(temp->lchild);}
        if(temp->rchild!=NULL) {temp->rchild->layer=temp->layer+1;qs.push(temp->rchild);}
        qs.pop();
    }
}
int main(int argc, char const *argv[]){
    cin>>n;
    for (int i = 0; i < n; i++)
        cin>>inorder[i];
    for (int i = 0; i < n; i++)
        cin>>postorder[i];
    Node* root=deal(0,n-1,0,n-1);
    layerOrder(root);
    cout<<res[0][0];
    int p=1;
    while (p<32){
        if(p%2==0)
            for (int j = res[p].size()-1; j >=0; j--)
                printf(" %d",res[p][j]);
        else
            for (int j = 0; j <res[p].size(); j++)
                printf(" %d",res[p][j]); 
        p++;
    }
    return 0;
}
