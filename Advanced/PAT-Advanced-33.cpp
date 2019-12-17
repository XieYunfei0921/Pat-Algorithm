#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

/*
问题转化为素数列表填充问题
假设两个相邻的素数 pn-1 p(n)

*/

bool isPrime(int x){
    for (int i = 2; i <= sqrt(x); i++)
        if(x%i==0) return false;
    return true;
}
int main(int argc, char const *argv[])
{
    int n;    
    cin>>n;
    vector<int> v;
    int factor=2;
    while (n!=1)
    {
        if(n%factor==0) {n/=factor;v.push_back(factor);}
        else factor++;
    }
    int MAXF=v[v.size()-1];
    // 建立邻接表求取质因子分布
    int table[MAXF];
    vector<int> Adj[MAXF+1];
    for (int i = 0; i < v.size(); i++)
        table[v[i]]++;
    int temp;
    for (int i = 2; i < MAXF+1; i++)
    {   
        temp=i;
        factor=2;
        while (temp!=1)
        {
            if(temp%factor==0) Adj[i].push_back(factor);
            else factor++;
        }
    }
    // 贪心
    int maxlen=1,start=v[0],end=v[0]+1;
    // 对于每个贪心需要的点,需要检查它的邻接表内容,保证能够贪到,且签到元素未使用完毕
    for (int i = 0; i < Adj[i]; i++)
    {
        /* code */
    }
    
    return 0;
}
