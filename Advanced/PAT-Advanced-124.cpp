#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> v;
int main(int argc, char const *argv[]){
    int n;
    int MAX=-1,MIN=1000000010;
    scanf("%d",&n);
    int arr[n];
    bool vis[n]={false};
    for (int i = 0; i < n; i++)
        scanf("%d",&arr[i]);   
    for (int i = 0; i < n; i++){
        if(MAX<arr[i]){
            vis[i]=true;
            MAX=arr[i];
        }
    }
    for (int i = n-1; i >=0; i--){
        if(MIN>arr[i]) MIN=arr[i];
        else vis[i]=false;
    }
    for (int i = 0; i < n; i++)
        if(vis[i]==true) v.push_back(arr[i]);
    sort(v.begin(),v.end());
    if(v.size()!=0){
        printf("%d\n",v.size());
        for (int i = 0; i <v.size(); i++){
            if(i!=0) printf(" %d",v[i]);
            else printf("%d",v[i]);
        }
    }else
        printf("%d\n\n",0);
    return 0;
}
