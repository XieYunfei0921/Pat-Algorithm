#include <iostream>
#include <vector>
using namespace std;
vector<int> vs;
int flag=1;
struct Node{
    int val;
    Node* lchild;
    Node* rchild;
};
void postorder(Node* root){
    if(root==NULL) return;
    postorder(root->lchild);
    postorder(root->rchild);
    vs.push_back(root->val);
}
void show(){
    cout<<vs[0];
    for (int i = 1; i < vs.size(); i++)
        cout<<" "<<vs[i];
    vs.clear();
}
Node* DFSMAX(int low,int high,int arr[]){
    int fa=low;int ls=2*low;
    if(fa>high) return NULL;
    Node* node=new Node;
    if(flag==1){
        if(ls==high && arr[low]<arr[ls])
            flag=0;
        if(ls+1<=high && (arr[low]<arr[ls] && arr[low]<arr[ls+1]))
            flag=0;
    }
    node->val=arr[fa];
    node->lchild=DFSMAX(ls,high,arr);
    node->rchild=DFSMAX(ls+1,high,arr);
    return node;
}
Node* DFSMIN(int low,int high,int arr[]){
    int fa=low;int ls=2*low;
    if(fa>high) return NULL;
    Node* node=new Node;
    // 合法点
    if(flag==1){
        if(ls==high && arr[low]>arr[ls])
            flag=0;
        if(ls+1<=high && (arr[low]>arr[ls] || arr[low]>arr[ls+1]))
            flag=0;
    }
    node->val=arr[fa];
    node->lchild=DFSMIN(ls,high,arr);
    node->rchild=DFSMIN(ls+1,high,arr);
    return node;
}

int main(int argc, char const *argv[]){
    int n,m;
    cin>>n>>m;
    int temp[m];
    for (int i = 0; i < n; i++){
        for (int j = 1; j <= m; j++)
            cin>>temp[j];
        Node* root=NULL;
        if(temp[1]>=temp[2])
            root=DFSMAX(1,m,temp);
        else{
            root=DFSMIN(1,m,temp);
        }
        if(flag==1 && temp[1]>=temp[2]){
            cout<<"Max Heap"<<"\n";
            postorder(root);
            show();
            cout<<"\n";
        }else if(flag==1 && temp[1]<temp[2]){
            cout<<"Min Heap"<<"\n";
            postorder(root); 
            show();
            cout<<"\n";
        }if(flag==0) {
            std::cout << "Not Heap" << "\n";
            postorder(root);
            show();
            cout<<"\n";
        }
        flag=1;
    }
    
    return 0;
}
