#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
using namespace std;
const int MAXN=100000;
bool isPrime(int x){
    for (int i = 2; i <= sqrt(x); i++)
        if(x%i==0) return false;
    return true;
}
int countPair(int n){
    vector<int> v;
    for (int i = 2; i <= n; i++)
        if(isPrime(i)) v.push_back(i);
    int cnt=0;
    for (int i = 0; i < v.size()-1; i++)
        if((v[i+1]-v[i])==2) cnt++;
    return cnt;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    std::cout << countPair(n) << std::endl;
    return 0;
}
