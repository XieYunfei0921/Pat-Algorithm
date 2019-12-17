#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
#include <map>
#include <queue>
using namespace std;
/*
    时间复杂度太高了
*/
struct Node{
    int id;
    double price;
    vector<int> sons;
};
map<int,Node> mp;
int main(int argc, char const *argv[]){
    int n,supply,cnt=0;double p,r,maxn=0;
    queue<Node> qs;
    cin>>n>>p>>r;
    int root=-1;
    for (int i = 0; i < n; i++){
        cin>>supply;
        if(supply==-1) {root=i;continue;}
        mp[supply].sons.push_back(i);
        mp[i].id=i;
    }
    mp[root].price=p;
    qs.push(mp[root]);
    while (!qs.empty()){
        Node temp=qs.front();
        if(temp.sons.size()==0 && temp.price>maxn)
            maxn=temp.price;
        for (int i = 0; i < temp.sons.size(); i++){
            mp[temp.sons[i]].price=temp.price*(1+r/100);
            qs.push(mp[temp.sons[i]]);
        }
        qs.pop();
    }
    for (int i = 0; i < n; i++)
        if(mp[i].price==maxn) cnt++;
    printf("%.2f %d",maxn,cnt);
    return 0;
}
