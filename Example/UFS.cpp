#include <algorithm>
#include <queue>
#include <vector>
#include <iostream>
using namespace std;
const int maxn=10010;
int father[maxn]={-1};
int* initial(int n){
    for (int i = 0; i < n; i++)
    {
        father[i]=i;
    }
}
int findFather(int x){
    if(father[x]==x)
        return x;
    else
        return findFather(father[x]);
}
int unionSet(int a,int b){
    int fa=findFather(a);
    int fb=findFather(b);
    if (fa!=fb)
    {
        father[fb]=fa;
    }
    return fa;
}

int pathCompressSearch(int x){
    vector<int> v;
    while (x!=father[x])
    {   
        v.push_back(x);
        x=father[x];
    }
    for (int i = 0; i < v.size(); i++)
    {
        father[v[i]]=x;
    }
    return x;
}

int main(int argc, char const *argv[])
{
    // initial(5);
    // std::cout << findFather(4) << std::endl;
    // unionSet(3,4);
    // std::cout << findFather(4) << std::endl;
    father[0]=0;
    father[1]=0;
    father[2]=1;
    father[3]=2;
    father[4]=3;
    father[5]=4;
    pathCompressSearch(5);
    std::cout << findFather(4) << std::endl;
    return 0;
}
