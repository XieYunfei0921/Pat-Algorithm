#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;
struct Node{
    string addr;
    int val;
    string next;
    void show(){
        cout<<this->addr<<" "<<this->val<<" "<<this->next<<"\n";
    }
};
bool status[10001]={false};
int main(int argc, char const *argv[])
{
    string start,end,org;int n,val;
    map<string,Node> m;
    cin>>org>>n;
    if(org=="-1")
        return 0;
    for (int i = 0; i < n; i++){
        cin>>start>>val>>end;
        m[start]=Node{start,val,end};
    }
    vector<Node> v1,v2;
    while (org!="-1")
    {
        if(status[abs(m[org].val)]==false){
            v1.push_back(m[org]);
            status[abs(m[org].val)]=true;
        }else{
            v2.push_back(m[org]);
        }   
        org=m[org].next;
    }
    for (int i = 0; i < v1.size(); i++)
    {
        if(i!=v1.size()-1) v1[i].next=v1[i+1].addr;
        else v1[i].next="-1";
    }
    for (int i = 0; i < v2.size(); i++)
    {
        if(i!=v2.size()-1) v2[i].next=v2[i+1].addr;
        else v2[i].next="-1";
    }
    for (int i = 0; i < v1.size(); i++)
        v1[i].show();
    for (int i = 0; i < v2.size(); i++)
        v2[i].show();
    return 0;
}
