#include <cstdio>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[]){
    int n,m;
    scanf("%d %d",&n,&m);
    int arr[n];
    for (int i = 0; i < n; i++)
        scanf("%d",&arr[i]);
    sort(arr,arr+n);
    int left=0,right=n-1;
    while (left<right){
        if(arr[left]+arr[right]<m)
            left++;
        if(arr[left]+arr[right]>m)
            right--;
        if(arr[left]+arr[right]==m)
            break;
    }
    if(left>=right) 
        printf("No Solution");
    else
        printf("%d %d",arr[left],arr[right]);
    return 0;
}
