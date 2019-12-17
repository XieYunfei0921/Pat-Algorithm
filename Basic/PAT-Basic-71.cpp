#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
bool isPrime(string s){
    int num=0;
    for (int i = 0; i < s.length(); i++)
        num=num*10+s[i]-'0';
    for (int i = 2; i <= sqrt(num); i++)
        if(num%i==0) return false;
    return true;
}
int main(int argc, char const *argv[])
{
    int L,K,start=0;
    cin>>L>>K;
    string s;
    cin>>s;
    while (start+K<=s.length())
    {
        if(isPrime(s.substr(start,K))) {std::cout << s.substr(start,K) << std::endl;return 0;}
        start++;
    }
    std::cout << "404" << std::endl;
    
    return 0;
}
