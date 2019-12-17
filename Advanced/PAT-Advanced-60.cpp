#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
#include <queue>
using namespace std;
struct Node{
    double price;
    int num;
    vector<int> sons;
};
map<int,Node> mp;
int main(int argc, char const *argv[])
{
    int n,k,son,leaf;double p,r,sum=0.0;
    cin>>n>>p>>r;
    bool notRoot[n]={false};
    for (int i = 0; i < n; i++){
        cin>>k;
        if(k==0) {
            cin>>leaf;
            mp[i].num=leaf;
            continue;
        }else
        {
            for (int j = 0; j < k; j++){
                cin>>son;
                notRoot[son]=true;
                mp[i].num=1;
                mp[i].sons.push_back(son);
            }
        }
    }
    int root=-1;
    for (int i = 0; i < n; i++)
        if(notRoot[i]==false){root=i;break;}
    // 层序设置价格
    queue<Node> qs;
    Node f=mp[root];
    f.price=p;
    qs.push(f);
    while (!qs.empty())
    {
        Node temp=qs.front();
        if(temp.sons.size()==0){
            sum+=temp.price*temp.num;
        }
        for (int i = 0; i < temp.sons.size(); i++){
            mp[temp.sons[i]].price=temp.price*(1+r/100);
            qs.push(mp[temp.sons[i]]);
        }
        qs.pop();
    }
    printf("%.1f",sum);
    return 0;
}
