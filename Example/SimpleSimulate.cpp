#include <iostream>
#include <string>
#include <math.h>
using namespace std;

// 简单模拟
// 题目有具体的要求,当实现起来不麻烦的时候,使用简单模拟

int times=0;
// 题目描述
// 卡拉兹猜想
int callatz(int org){
    
    std::cout << "times= "<<times<<"\torg= "<<org << std::endl;
    if (org%2==0)
    {
        org=org/2;
    }else
    {
        org=(3*org+1)/2;
    }
    times++;

    if (org!=1)
    {
        callatz(org);
    }

    return times;
    
    
    
}


int main(int argc, char const *argv[])
{

    std::cout << "输入n= "<<15<<"输出次数= "<<callatz(15) << std::endl;

    return 0;
}
