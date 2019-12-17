#include <iostream>
#include <stdio.h>
#include <map>
#include <vector>
using namespace std;
// 官方解答是使用二分缩小区间得到最小满足条件的区间
struct Node{
    int fromIndex;
    int toIndex;
};
map<int,vector<Node> > mp;
vector<int> sum;
int n,target;
int main(int argc, char const *argv[]){
    scanf("%d %d",&n,&target);
    int arr[n];
    sum.resize(n+1);
    sum[0]=0;
    for (int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
        sum[i+1]=arr[i]+sum[i];
    }
    int left=1,right=1;
    while (left<=n && right<=n){
        if(sum[right]-sum[left-1]>=target){
            mp[sum[right]-sum[left-1]].push_back(Node{left,right});
            left++;
            right=left;
        }else{
            right++;
        }
    }
    for (int i = 0; i < mp.begin()->second.size(); i++)
        printf("%d-%d\n",mp.begin()->second[i].fromIndex,mp.begin()->second[i].toIndex);
    return 0;
}
