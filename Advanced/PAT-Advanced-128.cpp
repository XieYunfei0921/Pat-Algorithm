#include <cstdio>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[]){
    int n;
    scanf("%d",&n);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    int mid=(n-1)/2;
    int s1=0,s2=0;
    for (int i = 0; i <=mid; i++)
        s1+=arr[i];
    for (int i = mid+1; i <n; i++)
        s2+=arr[i];
    int deta=n%2==0?0:1;
    int res=n%2==0?s2-s1:s2-s1+2*arr[mid];
    printf("%d %d",deta,res);
    return 0;
}
