#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>
using namespace std;
struct Node{
    float unit;
    float dis;
};
bool cmp1(Node n1,Node n2){ return n1.dis<n2.dis;}
struct Opt{
    float optinum;
    int start;
};
bool cmp3(Opt o1,Opt o2){
    if(o1.optinum==o2.optinum) return o1.start>o2.start;
    return o1.optinum>o2.optinum;
}
int main(int argc, char const *argv[]){
    float cm,d,avg,dis,unit;int n;
    cin>>cm>>d>>avg>>n;
    Node nodes[n];
    vector<Opt> avail[n];
    for (int i = 0; i < n; i++){
        cin>>unit>>dis;
        nodes[i]={unit,dis};
    }
    sort(nodes,nodes+n,cmp1);
    float maxsize=cm*avg;
    for (int i = 0; i < n-1; i++){
        for (int j = i+1; j < n; j++){
            if(nodes[j].dis-nodes[i].dis<=maxsize){
                float area=(nodes[j].dis-nodes[i].dis)*(nodes[i].unit-nodes[j].unit);
                avail[i].push_back(Opt{area,j});
            }
        }
    }
    for (int i = 0; i < n; i++)
        sort(avail[i].begin(),avail[i].end(),cmp3);
    int p=0;float maxdis=0,price=0;
    while (p<=n){
        // 优化逻辑有问题
        float cur=nodes[p].unit;
        if(avail[p].size()==0 && nodes[p].dis+maxsize<d){
            printf("The maximum travel distance = %.2f",nodes[p].dis+maxsize);
            return 0;
        }
        if((avail[p].size()==0 && nodes[p].dis+maxsize>=d) || (avail[p][0].optinum<0 && nodes[p].dis+maxsize>=d)){
            price+=(d-nodes[p].dis)*cur;
            break;
        }
        float deta=nodes[avail[p][0].start].dis-nodes[p].dis;
        price+=deta*cur;
        maxdis+=deta;
        p=avail[p][0].start;
    }
    printf("%.2f",price/avg);
    return 0;
}
