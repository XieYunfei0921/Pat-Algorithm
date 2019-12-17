#include <iostream>
#include <math.h>
#include <string>
#include <vector>
#include <set>
using namespace std;

// set由于相邻两元素地址不相邻,s.begin+1 报错
// 不要使用pow计算不准确
// 定义累加参数时需要初始化,否则程序会随机赋予初始值

int time=3;

// 数字黑洞
// 输入一个四位数 复杂度O(n)
void kaprekar(int n){

    vector<int> s;
    // a,b 需要初始化
    int a=0,b=0,fa=1,fb=1000,swap=0;
    if(n/1000==n%1000/100 && n%100/10==n/1000 && n%10==n/1000)
    {
        std::cout << n<<" - "<<n<<" = 0000" << std::endl;
        return;
    }
    s.push_back(n/1000);
    s.push_back(n%1000/100);
    s.push_back(n%100/10);
    s.push_back(n%10);

    for (int i = 0; i < s.size()-1; i++)
    {   
        for (int j = i+1; j < s.size(); j++)
        {
            if (s[j]<s[i])
            {
                swap=s[i];
                s[i]=s[j];
                s[j]=swap;
            }
        }
    }

    for (int i = 0; i < s.size(); i++)
    {
        a+=s[i]*fa;
        b+=s[i]*fb;
        fa*=10;
        fb/=10;
    }
    
    std::cout << a<<" - "<<b<<" = "<<(a-b) << std::endl;
    
    if ((a-b)!=6174)
    {
        kaprekar(a-b);
    }
}

int gcd(int a,int b){
    return !b ?a:gcd(b,a%b);
}

int lcm(int a,int b){
    
}

int main(int argc, char const *argv[])
{
    kaprekar(102); 
    // std::cout <<gcd(6,4)  << std::endl;
    
    return 0;
}
