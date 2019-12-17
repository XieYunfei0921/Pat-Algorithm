#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
using namespace std;
vector<int> v,v1,v2;
/*
    有Bug
*/
struct Node{
    int val;
    Node* lchild;
    Node* rchild;
};
void postOrder(Node* root){
    if(root==NULL) return;
    postOrder(root->lchild);
    postOrder(root->rchild);
    v.push_back(root->val);
}
void show(){
    cout<<v[0];
    for (int i = 1; i < v.size(); i++)
        cout<<" "<<v[i];
}
int toInt(string s){
    int num=0;
    for (int i = 0; i < s.length(); i++)
        num=num*10+s[i]-'0';
    return num;
}
Node* deal(int left1,int right1,int left2,int right2){
    // 错误原因 输出空的位置判断错误
    // 由于是通过中序确定顺序的,所以只需要确定前/后序的顺序即可
    if(left1>right1)
        return NULL;
    Node* root=new Node;

    // if(left2==right2 || left1==right1){
    //     root->val=v2[left2];
    //     root->lchild=NULL;
    //     root->rchild=NULL;
    //     return root;
    // }
    // if(left1>right2 || left2>right2)
    //     return NULL;
    // if(left1<0 || left2<0 || right2<0 || right1<0)
    //     return NULL;
    root->val=v1[left1];
    int index=-1;
    for (int i = left2; i <= right2; i++)
        if(v2[i]==root->val){index=i;break;}
    int leftLen=index-left2;
    root->lchild=deal(left1+1,left1+leftLen,left2,index-1);
    root->rchild=deal(left1+leftLen+1,right1,index+1,right2);
    return root;
}
int main(int argc, char const *argv[])
{
    stack<int> st;string s;
    int n;
    cin>>n;
    cin.ignore();
    for (int i = 0; i < 2*n; i++)
    {
        getline(cin,s);
        if(s.find(' ')!=string::npos){
            string sub=s.substr(s.find(' ')+1,s.length()-s.find(' '));
            v1.push_back(toInt(sub));
            st.push(toInt(sub));
        }else{
            v2.push_back(st.top());
            st.pop();
        }
    }
    Node* root=deal(0,v1.size()-1,0,v2.size()-1);
    postOrder(root);
    show();
    return 0;
}
