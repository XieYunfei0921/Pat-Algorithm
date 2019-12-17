#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
int n,k,p;
int maxn=-1;
int powP(int base,int p){
    if(p==0) return 1;
    return base*powP(base,p-1);
}
vector<int> ans,temp,fac;
void DFS(int index,int num,int sum,int facSum){
    if(num==k && sum==n){
        if(facSum>maxn){
            ans=temp;
            maxn=facSum;
        }
        return;
    }
    if(num>k || sum>n) return;
    if(index-1>0){
        // 选择
        temp.push_back(index);
        DFS(index,num+1,sum+fac[index],facSum+index);
        // 没有选择
        temp.pop_back();
        DFS(index-1,num,sum,facSum);
    }
}

int main(int argc, char const *argv[])
{   
    cin>>n>>k>>p;
    for (int i = 0; i < k+1; i++){
        fac.push_back(powP(i,p));
    }
    DFS(fac.size()-1,0,0,0);
    if(maxn==-1) cout<<"Impossible\n";
    else
    {
        cout<<n<<" = "<<ans[0]<<"^"<<p;
        for (int i = 1; i < ans.size(); i++)
            cout<<" + "<<ans[i]<<"^"<<p;
    }
    return 0;
}
