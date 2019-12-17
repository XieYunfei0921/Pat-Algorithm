#include <iostream>
#include <algorithm>
using namespace std;
int tab[37]={0};
int getFriends(int n){
    int num=0;
    while (n>0)
    {
        num+=n%10;
        n/=10;
    }
    return num;
}
int main(int argc, char const *argv[])
{   
    int n,cnt=0;
    cin>>n;
    int table[n];
    for (int i = 0; i < n; i++)
        cin>>table[i];
    for (int i = 0; i < n; i++)
        tab[getFriends(table[i])]++;
    for (int i = 0; i < 37; i++)
        if(tab[i]>0) cnt++;
    std::cout << cnt << std::endl;
    for (int i = 0; i < 37; i++){
        if(tab[i]>0 && cnt!=1) {cout<<i<<" ";cnt--;continue;}
        if(tab[i]>0 && cnt==1) {cout<<i;cnt--;break;} 
    }
    return 0;
}
