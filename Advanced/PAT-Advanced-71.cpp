#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>
using namespace std;
int father[1001]={0};
int hobbies[1001];
int findFather(int x){
    int a=x;
    if(x!=father[x])
        findFather(father[x]);
    while (a!=father[a]){
        int z=a;
        a=father[a];
        father[z]=x;
    }
    return x;
}
void Union(int a,int b){
    int fa=father[a];
    int fb=father[b];
    if(fa!=fb)
        fa=father[fb];
}
void init(int n){
    for (int i = 0; i < n; i++)
        father[i]=i;
}
int main(int argc, char const *argv[]){
    int n,id,k;
    cin>>n;
    init(n);
    fill(hobbies,hobbies+1000,-1);
    int temp;
    for (int i = 0; i < n; i++){
        scanf("%d:",&k);
        for (int j = 0; j < k; j++){
            cin>>id;
            if(hobbies[id]==-1){
                hobbies[id]=i;
            }else{
                Union(hobbies[id],i);
            }
        }
    }
    int cnt=0;
    vector<int> roots;
    // 找root的数量
    for (int i = 0; i < n; i++){
        std::cout << "i= "<<i<<"\tfather= "<<father[i] << std::endl;
        if(hobbies[i]==i) {
            cnt++;
            roots.push_back(i);
        }
    }
    std::cout << cnt << std::endl;
    return 0;
}
