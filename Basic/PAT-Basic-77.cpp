#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int tab[151];
void init(){
    for (int i = 1; i <= 150; i++)
        tab[i]=i;
}
void callatz(int x){
    while (x!=1)
    {
        if(x%2==0){
            tab[x/2]=x;
            x=x/2;            
        }else
        {
            tab[(3*x+1)/2]=x;
            x=(3*x+1)/2;
        }
    }
}
int main(int argc, char const *argv[])
{
    int k;
    cin>>k;
    int arr[k];
    init();
    for (int i = 0; i < k; i++)
    {
        cin>>arr[i];
        if(tab[arr[i]]!=arr[i]) continue;
        callatz(arr[i]);
    }
    vector<int> v;
    for (int i = 0; i < k; i++)
        if(tab[arr[i]]==arr[i]) v.push_back(arr[i]);
    sort(v.begin(),v.end());
    for (int i = v.size()-1; i >=0; i--)
    {
        if(i==0) cout<<v[i];
        else cout<<v[i]<<" ";
    }
    return 0;
}
