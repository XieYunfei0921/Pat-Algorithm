#include <iostream>
#include <algorithm>
using namespace std;
void judge(int arr[],int n,int capicity){
}
int main(int argc, char const *argv[]){
    int m,n,k;
    cin>>m>>n>>k;
    int arr[n];
    for (int i = 0; i < k; i++){
        for (int j = 0; j < n; j++)
            cin>>arr[i];
        judge(arr,n,m);
    }
    return 0;
}
