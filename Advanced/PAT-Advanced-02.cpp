#include <iostream>
#include <cmath>
#include <stdio.h>
#include <algorithm>
using namespace std;
/*
    OJ坑点:
    long double 格式化字符串的bug 早期MinGW的BUG
    库函数MinGW使用了windows的库来连接程序,两者类型不同
    x86 和 x86-64 架构下 GCC 中 long double 是 IEEE-754 中的 extended format(10位 Mingw)
    MSVC 以及 Windows 提供的运行库使用的是 IEEE-754 中的 double format(windows 8位)
*/
int main(int argc, char const *argv[])
{   
    float info[1001]={0};
    int a,b,exp;float coe;
    cin>>a;
    for (int i = 0; i < a; i++)
    {
        cin>>exp>>coe;
        info[exp]+=coe;
    }
    cin>>b;
    for (int i = 0; i < b; i++)
    {
        cin>>exp>>coe;
        info[exp]+=coe;
    }
    int cnt=0;
    for (int i = 1000; i >=0; i--)
        if(info[i]!=0.0) cnt++;
    std::cout << cnt ;
    for (int i = 1000; i >=0; i--)
        if(info[i]!=0.0) printf(" %d %.1f",i,info[i]);
    return 0;
}
