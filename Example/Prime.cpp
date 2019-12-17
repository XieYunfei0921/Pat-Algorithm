#include <iostream>
#include <string>
#include <math.h>
#include <vector>
using namespace std;

bool isPrime(int n){
    // 复杂度sqrt(n)
    bool flag=1;
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n%i==0)
        {
            flag=0;
            break;
        }
        
    }
    return flag;
}
// 埃式筛选法 O(n log logn)
vector<int> primtList(int maxn){
    vector<int> primes;
    int primeFlag[maxn]={0,0,0};// 素数标记
    for (int i = 2; i < maxn; i++)
    {
        if (primeFlag[i]==0)
        {
            // std::cout << "i= "<<i << std::endl;
            primes.push_back(i);
            for (int j = i+i; j < maxn; j+=i)
            {
                primeFlag[j]=1;
            }
        }
    }
    return primes;
}

vector<int> factors(int num){
    vector<int> primes=primtList(10000);
    int mid=(int)sqrt(num);
    vector<int> factor;
    for (int i = 0; i <= mid; i++)
    {
        for (vector<int>::iterator it=primes.begin();it!=primes.end();it++)
        {
            while (num%*it==0)
            {
                factor.push_back(*it);
                num=num/(*it);  
            }
            
        }
    }
    return factor;
}

int main(int argc, char const *argv[])
{
    
    vector<int> primes=factors(97532468);
    // std::cout << p.size() << std::endl;
    
    for (vector<int>::iterator i = primes.begin(); i != primes.end(); i++)
    {
        /* code */
        cout<<*i<<" ";
    }
    

    return 0;
}
