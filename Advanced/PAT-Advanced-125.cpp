#include <cstdio>
#include <vector>
#include <map>
using namespace std;
struct Node{
    int addr;
    int val;
    int nextaddr;
};
map<int,Node> mp;
int main(int argc, char const *argv[]){
    int start,n,k,st,val,ed;
    scanf("%05d %d %d",&start,&n,&k);
    vector<Node> ne,below,up;
    for (int i = 0; i < n; i++){
        scanf("%05d %d %05d",&st,&val,&ed);
        mp[st]=Node{st,val,ed};
    }
    while (start!=-1){
        if(mp[start].val<0) ne.push_back(mp[start]);
        else if(mp[start].val<=k) below.push_back(mp[start]);
        else up.push_back(mp[start]);
        start=mp[start].nextaddr;
    }
    int n2=below.size()==0?-1:below[0].addr;
    int n3=up.size()==0?-1:up[0].addr;
    if(ne.size()!=0){
        for (int i = 0; i < ne.size(); i++){
            if(i==ne.size()-1){
                printf("%05d %d ",ne[i].addr,ne[i].val,n2);
                if(n2==-1)
                    printf("%d\n",n2);
                else
                    printf("%05d\n",n2);
            }
            else
                printf("%05d %d %05d\n",ne[i].addr,ne[i].val,ne[i+1].addr);
        }
    }
    if(below.size()!=0){
        for (int i = 0; i < below.size(); i++){
            if(i==below.size()-1){
                printf("%05d %d ",below[i].addr,below[i].val);
                if(n3==-1)
                    printf("%d\n",n3);
                else
                    printf("%05d\n",n3);
            }
            else
                printf("%05d %d %05d\n",below[i].addr,below[i].val,below[i+1].addr);
        }
    }
    if(up.size()!=0){
        for (int i = 0; i < up.size(); i++){
            if(i==up.size()-1)
                printf("%05d %d %d\n",up[i].addr,up[i].val,-1);
            else
                printf("%05d %d %05d\n",up[i].addr,up[i].val,up[i+1].addr);
        }
    }
    return 0;
}
