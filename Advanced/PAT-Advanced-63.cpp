#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;
int toInt(string s){
    return (s[0]-'0')*10+(s[1]-'0');
}
struct Node{
    int id;
    int level;
    vector<int> sons;
};
map<int,Node> mp;
int main(int argc, char const *argv[]){
    int n,m,k;string s,t;
    cin>>n>>m;
    if(m==0){
        cout<<1<<" "<<1;
    }
    bool notRoot[n+1]={false};
    for (int i = 0; i < m; i++){
        cin>>s>>k;
        for (int j = 0; j < k; j++){
            cin>>t;
            mp[toInt(s)].sons.push_back(toInt(t));
            notRoot[toInt(t)]==true;
        }
    }
    int root=-1,maxLevel=0,maxpop=0;
    for (int i = 1; i <= n; i++)
        if(notRoot[i]==false) {root=i;break;}
    mp[root].level=1;
    vector<Node> vs,nv;
    vs.push_back(mp[root]);
    while (vs.size()!=0)
    {
        int elements=0;
        for (int i = 0; i < vs.size(); i++)
        {   
            for (int j = 0; j < vs[i].sons.size(); j++){
                mp[vs[i].sons[j]].level=vs[i].level+1;
                nv.push_back(mp[vs[i].sons[j]]);
            }
        }
        elements=nv.size();
        if(elements>maxpop){
            maxpop=elements;
            maxLevel=vs[0].level+1;
        }
        vs=nv;
        nv.clear();
    }
    cout<<maxpop<<" "<<maxLevel;
    return 0;
}
