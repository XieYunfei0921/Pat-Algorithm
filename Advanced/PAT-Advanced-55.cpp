#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>
using namespace std;
struct Node{
    string addr;
    int val;
    string next;
    void show(){
        // 使用\n而不是使用endl可以加快运行速度
        std::cout << this->addr<<" "<<this->val<<" "<<this->next << "\n";
    }
};
bool cmp(Node n1,Node n2){
    return n1.val<n2.val;
}
int main(int argc, char const *argv[])
{
    int n,val;string start,end,org;
    cin>>n>>org;
    vector<Node> v;
    map<string,Node> m;
    for (int i = 0; i < n; i++){
        cin>>start>>val>>end;
        m[start]=Node{start,val,end};   
    }
    while (org!="-1") {
        v.push_back(m[org]);
        org=m[org].next;
    }
    sort(v.begin(),v.end(),cmp);
    std::cout << v.size() <<" "<<v[0].addr<< std::endl;
    for (int i = 0; i < v.size(); i++){
        if(i!=v.size()-1)
            v[i].next=v[i+1].addr;
        else
            v[i].next="-1";
    }
    for (int i = 0; i < v.size(); i++)
        v[i].show();
    return 0;
}
