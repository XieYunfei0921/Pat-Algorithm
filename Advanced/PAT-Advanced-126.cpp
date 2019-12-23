#include <iostream>
#include <vector>
using namespace std;
const int MAXN=1010;
vector<int> Adj[MAXN];
int main(int argc, char const *argv[]){
    int n,m,k,st,ed;
    cin>>n>>m;
    int degree[n+1]={0};
    int temp[n+1]={0};
    int arr[n+1]={0};
    for (int i = 1; i <= m; i++){
        cin>>st>>ed;
        Adj[st].push_back(ed);
        degree[ed]++;
        temp[ed]++;
    }
    cin>>k;
    vector<int> ans;
    for (int i = 0; i < k; i++){
        for (int j = 1; j <= n; j++)
            cin>>arr[j];
        bool flag=true;
        for (int j = 1; j <= n; j++){
            if(temp[arr[j]]!=0){
                flag=false;
                break;
            }
            for (int g = 0; g < Adj[arr[j]].size(); g++)
                temp[Adj[arr[j]][g]]--;
        }
        if(!flag) ans.push_back(i);
        for (int j = 1; j <= n; j++)
            temp[j]=degree[j];
    }
    for (int i = 0; i < ans.size(); i++){
        if(i!=0) cout<<' ';
        cout<<ans[i];
    }
    return 0;
}
