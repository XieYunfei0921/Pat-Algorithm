#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
bool isPrime(int x){
    if(x==0 || x==1) return false;
    for (int i = 2; i*i <=x ; i++)
        if(x%i==0) return false;
    return true;
}
int main(int argc, char const *argv[])
{
    map<string,string> smp;
    int n;string id;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        cin>>id;
        if(i==1) smp[id]="Mystery Award";
        else if(isPrime(i)) smp[id]="Minion";
        else smp[id]="Chocolate";
    }
    int m;
    cin>>m;
    for (int i = 1; i <= m; i++)
    {
        cin>>id;
        if(smp.count(id)==0) {
            std::cout << id<<": Are you kidding?" << std::endl;
            continue;
        }
        std::cout << id<<": "<<smp[id] << std::endl;
        smp[id]="Checked";
    }
    
    return 0;
}
