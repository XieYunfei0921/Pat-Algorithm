#include <iostream>
#include <algorithm>
#include <vector>
#include <map>
#include <queue>
using namespace std;
struct Node{
    int id;
    int level;
    vector<int> sons;
};
int toInt(string s){
    return (s[0]-'0')*10+(s[1]-'0');
}
map<int,Node> mp;

int main(int argc, char const *argv[])
{
    int m,n,k;string start,end;
    cin>>n>>m;
    if(m==0)
        return 0;
    bool notLeaf[n+1]={false};
    bool notRoot[n+1]={false};
    for (int i = 0; i < m; i++){
        cin>>start>>k;
        notLeaf[toInt(start)]=true;
        for (int j = 0; j < k; j++){   
            cin>>end;
            mp[toInt(start)].id=toInt(start);
            notRoot[toInt(end)]=true;
            mp[toInt(start)].sons.push_back(toInt(end));
        }
    }
    int root=-1;
    for (int i = 1; i <= n; i++)
        if(notRoot[i]==false) {root=i;break;}
    int maxn=-1;
    queue<Node> qs;
    mp[root].level=1;
    qs.push(mp[root]);
    map<int,int> mv;
    while (!qs.empty())
    {
        Node temp=qs.front();
        if(temp.level>maxn)
            maxn=temp.level;
        if(notLeaf[temp.id]==false)
            mv[temp.level]++;
        for (int i = 0; i < temp.sons.size(); i++){
            mp[temp.sons[i]].level=temp.level+1;
            qs.push(mp[temp.sons[i]]);
        }
        qs.pop();
    }
    cout<<0;
    for (int i = 2; i <= maxn; i++)
    {
        if(mv.count(i)==0)
            cout<<" "<<0;
        else
            cout<<" "<<mv[i];
    }
    
    return 0;
}
