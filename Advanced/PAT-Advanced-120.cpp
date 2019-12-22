#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
struct Node{
    float lib;
    float total;
    float single;
    void caulate(){this->single=this->total/this->lib;}
};
bool cmp(Node n1,Node n2){
    return n1.single>n2.single;
}
int main(int argc, char const *argv[]){
    int n;float ms,d;
    cin>>n>>d;
    float libs[n];Node nodes[n];
    for (int i = 0; i < n; i++)
        cin>>libs[i];
    for (int i = 0; i < n; i++){
        cin>>ms;
        nodes[i]={libs[i],ms,0};
        nodes[i].caulate();
    }
    sort(nodes,nodes+n,cmp);
    float prices=0.00;int p=0;
    while (d>=0){
        if(p>=n) break;
        if(nodes[p].lib<=d) {
            prices+=nodes[p].total;
            d-=nodes[p].lib;
            p++;
        }else {
            prices+=nodes[p].single*d;
            break;
        }
    }
    printf("%.2f",prices);
    return 0;
}
