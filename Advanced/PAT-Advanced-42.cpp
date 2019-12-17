#include <iostream>
#include <vector>
using namespace std;
int tab[40]={0};
int maxn=0;
void put(int n){
    int sum=0;
    while (n>0)
    {
        sum+=n%10;
        n/=10;
    }
    tab[sum]++;
    if(tab[sum]>1 && sum>maxn) maxn=sum;
}
int main(int argc, char const *argv[])
{
    int n,x,cnt=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>x;
        put(x);
    }
    vector<int> v;
    for (int i = 0; i < 40; i++)
    {   
        if(tab[i]>0){
            cnt++;
            v.push_back(i);
        }
    }
    std::cout << cnt << std::endl;
    for (int i = 0; i < v.size(); i++)
    {
        if(i==v.size()-1) cout<<v[i];
        else cout<<v[i]<<" ";   
    }
    return 0;
}
