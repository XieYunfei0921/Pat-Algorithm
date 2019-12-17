#include <iostream>
#include <algorithm>
using namespace std;
bool isLegal(int* arr,int n){
    int l=0,r=1;
    while (l<n-1)
    {
        if(abs(*(arr+l)-*(arr+r))==abs(r-l) || *(arr+l)==*(arr+r)) return false;
        if(r==(n-1)){
            l++;
            r=l+1;
        }else{
            r++;
        }
    }
    return true;
}
int main(int argc, char const *argv[])
{
    int n,k;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>k;
        int arr[k];
        for (int i = 0; i < k; i++)
            cin>>arr[i];
        if(isLegal(arr,k)) std::cout << "YES" << std::endl;
        else std::cout << "NO" << std::endl;
    }
    return 0;
}
