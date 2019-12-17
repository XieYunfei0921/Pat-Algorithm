#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// 时间复杂度O(n)
vector<int> v;
void decreaseByStep(int arr[],int n){
    int temp=0,index=-1,mini=0x3fffffff;
    bool flag=false;
    if(n==2){
        swap(arr[0],arr[1]);
        return;
    }
    for (int i = n-1; i > 0; i--){
        if(arr[i]>arr[i-1]){
            index=i;
            break;
        }
    }
    if(index==-1){
        reverse(arr,arr+n);
        return;
    }
    temp=arr[index-1];
    // 优化index-1 -> end段
    int ti=-1;
    for (int i = index; i < n; i++){
        if(arr[i]>temp && arr[i]<mini){
            mini=arr[i];
            ti=i;
        }
    }
    arr[index-1]=mini;
    arr[ti]=temp;
    sort(arr+index,arr+n);
}
int main(int argc, char const *argv[]){
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    decreaseByStep(arr,n);
    cout<<arr[0];
    for (int i = 1; i < n; i++)
        cout<<" "<<arr[i];
    return 0;
}
