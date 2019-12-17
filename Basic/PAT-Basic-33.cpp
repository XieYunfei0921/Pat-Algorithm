#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,p;
    long long temp;
    cin>>n>>p;
    int table[n];
    for (int i = 0; i < n; i++)
        cin>>table[i];
    sort(table,table+n);
    int front,back,cnt;
    if(n==1 && p==1){cout<<1;return 0;}
    if(n==1 && p!=1){cout<<0;return 0;}
    if(n%2==0){
        front=(n-1)/2;
        back=(n+1)/2;
        if(table[back]<=table[front]*p) 
            cnt=2;
        else if(p==1) {cout<<1;return 0;}
        else{cout<<0;return 0;}
    }else
    {
        front=back=(n-1)/2;
        cnt=1;
    }
    while (table[back]<=table[front]*p)
    {   
        cnt+=2;front--;back++;
        if(front<0 || back>n-1)
            break;
    }
    cnt-=2;front++;
    if(table[back]<=table[front]*p && front>=0 && back<=n-1) cnt++;
    else{ front--;back--;if(table[back]<=table[front]*p && front>=0 && back<=n-1) cnt++;}
    std::cout << cnt << std::endl;
    return 0;
}
