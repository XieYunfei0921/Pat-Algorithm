#include <iostream>
#include <math.h>
#include <algorithm>
#include <queue>
using namespace std;

// 完全二叉树
struct Node{
    int v;
    //编号满足二叉查找树
    int num;
    int height;
    Node* lchild;
    Node* rchild;
};
Node* newNode(int x,int num){
    Node* node=new Node;
    node->v=x;
    node->num=num;
    node->lchild=NULL;
    node->lchild=NULL;
    return node;
}

Node* search(Node* root,int num){
    Node* node;
    if(root==NULL || num<root->num)
        return NULL;
    if (num==root->num)
        return root;
    if(num%2==0){
        node=search(root,num/2);
        return node->lchild;
    }else
    {
        node=search(root,num/2);
        return node->rchild;
    }
}

/*
    对于任意一个根节点root,插入元素num=root->num*2时,插左边
    由于是按顺序差的所以不知道插的位置,所以需要查找父节点的位置
*/
void insert(Node* &root,int x,int num){
    // 计算层号
    if(root==NULL){
        root=newNode(x,num);
        return;
    }
    // 决定插入的位置
    Node* node=search(root,num/2);
    if (num%2==0)
    {
        node->lchild=newNode(x,num);
    }else
    {
        node->rchild=newNode(x,num);
    }
}
// 创建一颗完全二叉树
Node* create(int data[],int n){
    Node* root=NULL;
    for (int i = 0; i < n; i++)
    {   
        // std::cout << "Insert: "<<data[i] << std::endl;
        insert(root,data[i],i+1);
    }
    return root;
}

// 层序排列
queue<Node*> qs;
void layerOrder(Node* root){
    qs.push(root);
    while (!qs.empty())
    {
        Node* node=qs.front();
        std::cout << node->v << " ";
        if(node->lchild!=NULL) {
            qs.push(node->lchild);
        }
        if(node->rchild!=NULL){
            qs.push(node->rchild);
        }
        qs.pop();
    }
}

void inorder(Node* root){
    if (root==NULL || root->num<=0)
        return;
    inorder(root->lchild);
    cout<<"root v= "<<root->v<<"\tnum= "<<root->num<<"\n";
    inorder(root->rchild);
}

/*
    对区间进行堆顶调整
    方案: 递归
    每次循环形成一个小堆,迭代生成全局堆
*/
int heap[1000];
/*
    第h层的调整方案[非叶子节点]
    第h层节点数2^(h-1)
*/
void downAdjust(int low,int hight){
    int i=low;
    int j=2*i;
    // 调整根节点为i的子树  
    while (j<=hight)
    {
        if (j+1<=hight && heap[j+1]>heap[j])
        {
            j=j+1;
        }
        if (heap[i]<heap[j])
        {   
            // 调整i为局部最大
            swap(heap[j],heap[i]);
            i=j;
            j=2*i;
        }else
        {
            break;
        }
    }
    
}

void createHeap(int n){
    // 非叶子层总数n/2
    for (int i = n/2; i >= 1; i--)
    {
        downAdjust(i,n);
    }
}

void deleteTop(int num){
    heap[1]=heap[num--];
    downAdjust(1,num);
}

/*
    调整思路:
        先跟兄弟比
        再跟爸爸比
    输入参数:
        x需要插入的参数
        num:原来堆里的元素总数
        num+1: 新插入元素的编号
*/
void addElement(int x,int num){
    int id=num+1;
    int left=0;
    int father=0;
    while (left!=1)
    {
        if(id%2==0)
            left=id;
        else
            left=id-1;
        father=left/2;
        // 跟兄弟比 左节点要大于右节点 大的放到left节点
        if (heap[left]<heap[id]){
            swap(heap[left],heap[id]);
            break;
        }
        // 跟爸爸比
        if (heap[left]>heap[father])
        {
            swap(heap[left],heap[father]);
            break;
        }
        // 成功之后迭代
        left=father%2==0?father:father-1;
        father=left/2;
    }
}
void heapSort(int num){
    createHeap(num);
    for (int i = num; i >1; i++)
    {
        swap(heap[1],heap[i]);
        downAdjust(1,i-1);
    }
}

int main(int argc, char const *argv[])
{   
    int arr[6]={2,3,9,2,1,5};
    Node* root=create(arr,6);
    // Node* root=newNode(2,1);
    // root->lchild=newNode(3,2);
    // root->rchild=newNode(9,3);
    // root->lchild->lchild=newNode(2,4);
    // root->lchild->rchild=newNode(1,5);
    // root->rchild->lchild=newNode(5,6);
    // Node* node=search(root,5);
    // std::cout << node->num << std::endl;
    // layerOrder(root);
    inorder(root);
    return 0;
}
