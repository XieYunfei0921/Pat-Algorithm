#include <iostream>
#include <math.h>
#include <string>
using namespace std;

int gcd(int a,int b){
    // 求最大公约数
    if(b==0){
        return a;
    } else
    {
        return gcd(b,a%b);
    }
    
}

int lcm(int a,int b){
    // 求最小公倍数
    return a*b/gcd(a,b);
}

int main(int argc, char const *argv[])
{

    std::cout << "6和9的最大公约数= "<<gcd(9,6) << std::endl;
    std::cout << "6和9的最小公倍数= "<<lcm(9,6) << std::endl;

    

    return 0;
}
