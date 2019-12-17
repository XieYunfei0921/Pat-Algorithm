#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <stdio.h>
using namespace std;
/*
    使用并查集时，考虑一下路径压缩否则,最坏时间复杂度会到达n^2
*/
int n,k,son;double p,r;
int father[100001];
int depths[100001];
int getDepths(int x){
    if(x==0) return 0;
    return 1+getDepths(father[x]);
}
int main(int argc, char const *argv[])
{
    cin>>n>>p>>r;
    vector<int> leafs;
    for (int i = 0; i < n; i++)
    {
        cin>>k;
        if(k==0) {leafs.push_back(i);continue;}
        for (int j = 0; j < k; j++)
        {
            cin>>son;
            father[son]=i;
        }
    }
    int minu=100001,cur=0,cnt=0;
    for (int i = 0; i < leafs.size(); i++){
        cur=getDepths(leafs[i]);
        depths[leafs[i]]=cur;
        if(cur<minu)
            minu=cur;
    }
    for (int i = 0; i < leafs.size(); i++)
        if(depths[leafs[i]]==minu) cnt++;
    printf("%.4f %d",p*pow(1+r/100,minu),cnt);
    return 0;
}
