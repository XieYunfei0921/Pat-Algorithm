#include <iostream>
#include <set>
using namespace std;
// 圈子判定:
// 最大圈子判断: 圈子成员是否还有共同好友没有进入,如果存在则不是最大圈子
const int MAXN=210;
set<int> Adj[MAXN];
int counters[MAXN]={0};
int main(int argc, char const *argv[]){
    int nv,ne,st,ed;
    cin>>nv>>ne;
    for (int i = 0; i < ne; i++){
        cin>>st>>ed;
        Adj[st].insert(ed);
        Adj[ed].insert(st);
    }
    int k,nums;
    cin>>k;
    for (int i = 0; i < k; i++){
        cin>>nums;
        int temp[nums+1];
        for (int j = 1; j <= nums; j++)
            cin>>temp[j];
        bool flag=true;
        for (int j = 1; j <= nums; j++){
            for (int x = 1; x <= nums; x++){
                if(x!=j && Adj[temp[j]].count(temp[x])==0){
                    flag=false;
                    break;
                }  
                if(x!=j){
                    for (set<int>::iterator y = Adj[temp[j]].begin(); y != Adj[temp[j]].end(); y++){
                        counters[*y]++;
                    }
                } 
            }
        }
        if(!flag) cout<<"Not a Clique\n";
        else{
            // 查看是否为最大的圈子
            bool f1=true;
            for (int j = 1; j < 210; j++)
                if(counters[i]>nums) {f1=false;break;}
            if(f1) cout<<"Yes\n";
            else cout<<"Not Maximal\n";
            for (int j = 0; j < 210; j++)
                counters[j]=0;
        }
    }
    return 0;
}
