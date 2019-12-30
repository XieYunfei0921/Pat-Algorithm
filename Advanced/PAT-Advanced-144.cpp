#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[]){
    int n;
    cin>>n;
    int arr[n],beyond[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    sort(arr,arr+n,greater<int>());
    beyond[0]=0;
    int p=0;
    while (p<n && arr[p]>p+1){
        p++;
    }
    cout<<p;
    return 0;
}
