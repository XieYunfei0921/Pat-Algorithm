#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
// 注意 库存和总价题目上写的是正数，不是正整数
struct Node{
    int lib;
    int total;
    double val;
};
bool cmp(Node n1,Node n2){
    return n1.val>n2.val;
}
int main(int argc, char const *argv[])
{
    int n,d;
    cin>>n>>d;
    int lib[n],total[n];Node nodes[n];
    for (int i = 0; i < n; i++)
        cin>>lib[i];
    for (int i = 0; i < n; i++)
        cin>>total[i];
    for (int i = 0; i < n; i++){
        nodes[i].lib=lib[i];
        nodes[i].total=total[i];
        nodes[i].val=(double)total[i]/lib[i];
    }
    double profit=0.00;
    sort(nodes,nodes+n,cmp);
    for (int i = 0; i <n; i++)
    {   
        if(nodes[i].lib<d){
            profit+=nodes[i].total;
        }else{
            profit+=nodes[i].val*d;
            break;
        }
        d-=nodes[i].lib;
    }
    printf("%.2f",profit);
    return 0;
}
