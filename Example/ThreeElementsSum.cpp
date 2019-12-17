#include <iostream>
#include <vector>
using namespace std;
int n,target;
vector<int> v;
void DFS(int arr[],int index,int total,int cur){
    //先选一个
    if(total==4){
        if(cur==target){
            for (int i = 0; i < v.size(); i++){
                cout<<v[i]<<" ";
            }
            cout<<"\n";
        }
        return;
    }
    if(index>=n) return;
    // 选择
    if(total<4){
        v.push_back(arr[index]);
        DFS(arr,index+1,total+1,cur+arr[index]);
        v.pop_back();
        DFS(arr,index+1,total,cur);
    }
}
int main(int argc, char const *argv[]){
    cin>>n>>target;
    int arr[n],vis[n]={false};
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    DFS(arr,0,0,0);
    return 0;
}
