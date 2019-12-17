#include <iostream>
#include <math.h>
#include <string>
#include <stack>
using namespace std;

void convert(int a,int b,int scale){
    int num;
    int sum=a+b;
    stack<int> s;
    // 输出A+B 转换成十进制数
    do 
    {   
        s.push(sum%scale);
        sum/=scale;
    } while (sum!=0);

    while (!s.empty())
    {
        cout<<s.top();
        s.pop();
    }
}

int main(int argc, char const *argv[])
{
    convert(7,4,8);

    return 0;
}
