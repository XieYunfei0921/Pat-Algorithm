#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int BST[1010];int index=0,n;int num[2020];
/*
    先排序再标号插入
*/
void inOrder(int root){
    if(root>n) return;    
    inOrder(root*2);
    // root是节点编号 BST[root]是值
    // root已经按照完全二叉树形成完毕,只需要按需赋值即可
    std::cout << "BST["<<root<<"] ="<<num[index] << std::endl;
    BST[root]=num[index++];
    inOrder(root*2+1);
}
int main(int argc, char const *argv[]){
    cin>>n;
    for (int i = 0; i < n; i++)
        cin>>num[i];
    sort(num,num+n);
    for (int i = 0; i < n; i++)
        cout<<num[i]<<" ";
    std::cout << "" << std::endl;
    inOrder(1);
    cout<<BST[1];
    for (int i = 2; i <= n; i++)
        cout<<" "<<BST[i];
    return 0;
}
