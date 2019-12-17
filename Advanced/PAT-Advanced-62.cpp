#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <cmath>
/*
    使用并查集解决  TLE
*/
using namespace std;
int height[100001];
int org[100001];
int n;
double p,r;
int getHeight(int index){
    if(index==-1) return 0;
    return 1+getHeight(org[index]);
}
int main(int argc, char const *argv[])
{
    int supply,cnt=0,maxH=0;double p,r;
    cin>>n>>p>>r;
    int root=-1;
    for (int i = 0; i < n; i++){
        cin>>supply;
        if(supply==-1) root=i;
        org[i]=supply;
    }
    for (int i = 0; i < n; i++)
        height[i]=getHeight(org[i]);

    for (int i = 0; i < n; i++){
        if(height[i]>maxH)
            maxH=height[i];
    }
    for (int i = 0; i < n; i++)
        if(height[i]==maxH)
            cnt++;
    double val=p*pow(1+r/100,maxH);
    printf("%.2f %d",val,cnt);
    return 0;
}
