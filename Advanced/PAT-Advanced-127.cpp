#include <cstdio>
#include <vector>
using namespace std;
const int MAXN=50010;
int n;
int pre[MAXN],mid[MAXN];
struct Node{
    int val;
    Node* lchild;
    Node* rchild;
};
Node* deal(int PL,int PR,int ML,int MR){
    if(PL>PR || ML>MR) return NULL;
    Node* root=new Node;
    root->val=pre[PL];
    int index=-1;
    for (int i = ML; i <= MR; i++){
        if(mid[i]==pre[PL]){
            index=i;
            break;
        }
    }
    int leftNum=index-ML;
    root->lchild=deal(PL+1,PL+leftNum,ML,index-1);
    root->rchild=deal(PL+leftNum+1,PR,index+1,MR);
    return root;
}
vector<int> ans;
void postOrder(Node* root){
    if(root==NULL) return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    ans.push_back(root->val);
}
int main(int argc, char const *argv[]){
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
        scanf("%d",&pre[i]);
    for (int i = 0; i < n; i++)
        scanf("%d",&mid[i]);
    Node* root=deal(0,n-1,0,n-1);
    postOrder(root);
    printf("%d",ans[0]);
    return 0;
}
