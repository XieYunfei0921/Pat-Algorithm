#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
string translate(int n){
    string s="";
    while (n>0)
    {
        s+=n%10+'0';
        n/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}
int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    int tab[n+1]={0};
    for (int i = 0; i < m; i++)
    {   
        for (int j = 1; j < n+1; j++)
        {
            int temp;
            cin>>temp;
            tab[j]+=temp;
        }
    }
    int maxn=0;
    string s="";
    for (int i = 1; i < n+1; i++)
        if(tab[i]>maxn) maxn=tab[i];
    for (int i = 1; i < n+1; i++){
        if(tab[i]==maxn){
            s+=translate(i);s+=" ";
        }
    }
    std::cout << maxn << std::endl;
    std::cout << s.substr(0,s.length()-1) << std::endl;
    return 0;
}
