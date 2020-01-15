#include <iostream>
#include <map>
#include <queue>
using namespace std;
map<int,int> father;
struct Node{
	int val;
	int layer;
	Node* lchild;
	Node* rchild;
};

const int MAXN=10100;
map<int,Node*> ele;
int m,n,x,y;
int arr[MAXN];

Node* deal(int PS,int PE){
	if(PS>PE || PS<0 || PE>=n) return NULL;
	Node* root=new Node;
	root->val=arr[PS];
	int index=-1;
	for(int i=PS+1;i<=PE;i++){
		if(arr[i]>=arr[PS]){
			index=i;
			break;
		}
	}
	if(index==PS+1){
		root->rchild=deal(PS+1,PE);
		root->lchild=NULL;
	}else if(index<PS){
		root->lchild=deal(PS+1,PE);
		root->rchild=NULL;
	}else{
		root->lchild=deal(PS+1,index-1);
		root->rchild=deal(index,PE);
	}
}

void layerOrder(Node* root){
	if(root==NULL) return;
	queue<Node*> qs;
	root->layer=0;
	qs.push(root);
	while(!qs.empty()){
		Node* temp=qs.front();
		ele[temp->val]=temp;
		if(temp->lchild!=NULL) {
			temp->lchild->layer=temp->layer+1;
			qs.push(temp->lchild);
			father[temp->lchild->val]=temp->val;
		}
		if(temp->rchild!=NULL) {
			temp->rchild->layer=temp->layer+1;
			qs.push(temp->rchild);
			father[temp->rchild->val]=temp->val;
		}
		qs.pop();
	}
}

int main(){
	scanf("%d %d",&m,&n);
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	Node* root=deal(0,n-1);
	layerOrder(root);
	for(int i=0;i<m;i++){
		scanf("%d %d",&x,&y);
		if(ele.count(x)==0 && ele.count(y)==0) printf("ERROR: %d and %d are not found.\n",x,y);
		else if(ele.count(x)==0 && ele.count(y)!=0) printf("ERROR: %d is not found.\n",x);
		else if(ele.count(y)==0 && ele.count(x)!=0) printf("ERROR: %d is not found.\n",y);
		else{
			Node* n1=ele[x];
			Node* n2=ele[y];
			Node* temp;
			if(n1->layer>n2->layer){
				temp=n1;
				n1=n2;
				n2=temp;
			}
			int xn1=n1->val,yn1=n2->val;
			while(n2->layer>n1->layer){n2=ele[father[n2->val]];}
			if(n1->val==n2->val)
				printf("%d is an ancestor of %d.\n",xn1,yn1);
			else{
				while(n1->val!=n2->val){
					n1=ele[father[n1->val]];
					n2=ele[father[n2->val]];
				}
				printf("LCA of %d and %d is %d.\n",xn1,yn1,n1->val);
			}
		}
	}
	return 0;
}
