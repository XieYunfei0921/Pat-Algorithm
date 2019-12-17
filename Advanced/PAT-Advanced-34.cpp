#include <iostream>
#include <cmath>
using namespace std;
bool isPrime(string s){
    int num=0;
    for (int i = 0; i < s.length(); i++)
        num=num*10+s[i]-'0';
    if(num==0 || num==1) return false;
    for (int i = 2; i*i <= num; i++)
        if(num%i==0) return false;
    return true;
}
int main(int argc, char const *argv[])
{
    int n,k;
    string s;
    cin>>n>>k>>s;
    int left=0;
    while (left+k<=n)
    {   
        if(isPrime(s.substr(left,k))){
            std::cout << s.substr(left,k) << std::endl;
            return 0;
        }
        left++;
    }
    std::cout << "404" << std::endl;
    return 0;
}
