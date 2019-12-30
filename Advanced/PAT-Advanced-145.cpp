#include <stdio.h>
#include <queue>
#include <map>
using namespace std;
const int MAXN=10010;
int inOrder[MAXN],preOrder[MAXN];
struct Node{
    int val;
    int layer;
    Node* lchild;
    Node* rchild;
};
map<int,Node*> father;
map<int,Node*> mp;
Node* deal(int PL,int PR,int ML,int MR){
    if(PL>PR || ML>MR) return NULL;
    Node* root=new Node;
    root->val=preOrder[PL];
    int index=-1;
    for (int i = ML; i <= MR; i++)
        if(inOrder[i]==preOrder[PL]){index=i;break;}
    int left=index-ML;
    root->lchild=deal(PL+1,PL+left,ML,index-1);
    root->rchild=deal(PL+1+left,PR,index+1,MR);
}
void layerOrder(Node* root){
    if(root==NULL) return;
    queue<Node*> qs;
    root->layer=0;
    father[root->val]=root;
    qs.push(root);
    while (!qs.empty()){
        Node* temp=qs.front();
        mp[temp->val]=temp;
        qs.pop();
        if(temp->lchild!=NULL) {temp->lchild->layer=temp->layer+1;father[temp->lchild->val]=temp;qs.push(temp->lchild); }
        if(temp->rchild!=NULL) {temp->rchild->layer=temp->layer+1;father[temp->rchild->val]=temp;qs.push(temp->rchild); }
    }
}
void query(Node* root,int x,int y){
    Node* n1;Node* n2;
    if(mp[x]->layer>mp[y]->layer){
        n1=mp[y];
        n2=mp[x];
    }else{
        n1=mp[x];
        n2=mp[y];
    }
    int st=n2->val;
    while (n2->layer!=n1->layer){n2=father[n2->val];}
    if(n1->val==n2->val){
        printf("%d is an ancestor of %d.\n", n1->val, st);
        return;
    }
    while (n1->val!=n2->val){
        n1=father[n1->val];
        n2=father[n2->val];
    }
    printf("LCA of %d and %d is %d.\n", x, y, n1->val);
}
int main(int argc, char const *argv[]){
    int m,n,x,y;
    scanf("%d %d",&m,&n);
    for (int i = 0; i < n; i++)
        scanf("%d",&inOrder[i]);
    for (int i = 0; i < n; i++)
        scanf("%d",&preOrder[i]);
    Node* root=deal(0,n-1,0,n-1);
    layerOrder(root);
    for (int i = 0; i < m; i++){
        scanf("%d %d",&x,&y);
        if(father.count(x)==0 && father.count(y)==0)
            printf("ERROR: %d and %d are not found.\n", x, y);
        else if(father.count(x)==0 || father.count(y)==0)
            printf("ERROR: %d is not found.\n", father.count(x) == 0 ? x : y);
        else
            query(root,x,y);
    }
    return 0;

}
