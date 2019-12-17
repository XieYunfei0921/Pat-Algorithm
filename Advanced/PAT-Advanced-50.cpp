#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
struct Node{
    int val;
    Node* lchild;
    Node* rchild;
};
/*
    中序序列: 区间[Mids,Mide]   根节点索引k
        左子树  [Mids,k-1]
        右子树  [k+1,Mide]
    后序遍历: 区间[Backs,Backe] 根节点backe
        左子树  [Backs,Backs+k-Mids]
        右子树  [Backs+k-Mids+1,Backe-1]

    递归获取根节点
        左子树&& 左子树 获取左子树的根节点
        右子树&&右子树 获取右子树的根节点
    ... 知道区间长度为1，说明已经到达叶子节点
*/

Node* create(int postFrom,int postTo,int inFrom,int inTo,int post[],int mid[]){
    Node* root=new Node;
    int pos;
    if(postFrom>postTo)
        return NULL;
    int val=post[postTo];
    root->val=val;
    for (int i = inFrom; i <= inTo; i++)
        if(mid[i]==val) {pos=i;break;}
    int leftNum=pos-inFrom;
    int rightNum=postTo-pos+inFrom;
    root->lchild=create(postFrom,postFrom+leftNum-1,inFrom,pos-1,post,mid);
    root->rchild=create(postFrom+leftNum,postTo-1,pos+1,inTo,post,mid);
    return root;
}
void layerOrder(Node* root){
    queue<Node*> qs;
    cout<<root->val;
    if(root->lchild!=NULL) qs.push(root->lchild);
    if(root->rchild!=NULL) qs.push(root->rchild);
    while (!qs.empty())
    {
        Node* temp=qs.front();
        cout<<" "<<temp->val;
        if(temp->lchild!=NULL) qs.push(temp->lchild);
        if(temp->rchild!=NULL) qs.push(temp->rchild);
        qs.pop();
    }
}

int main(int argc, char const *argv[]){
    int n;
    cin>>n;
    int post[n],mid[n];
    for (int i = 0; i < n; i++)
        cin>>post[i];
    for (int i = 0; i < n; i++)
        cin>>mid[i];
    Node* root=create(0,6,0,6,post,mid);
    layerOrder(root);
    return 0;
}
