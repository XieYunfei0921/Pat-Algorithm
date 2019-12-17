#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

/*
    考虑到输入1000位的正整数，long long类型存储不了
    改为数组输入,转化为数组计算，数组最大长度为1000
    考虑到mod计算加法乘法的性质,最高位上最大位上为1000个8相乘，累加地位最恶劣情况超过了存储范围
*/

// base=10 pow为数组下标相关 mod为取模基数递归求解10^n/x
int powerMod(int base,int pow,int mod){
    int cnt=1;
    int res=1;
    while (cnt<=pow)
    {
        res*=base%mod;
        res%=mod;
        cnt++;
    }
    return res;
}

int table[1000];
int divide[1000];
void powDivide(int len,int x){
    int rent=0;
    for (int i = len-1; i >= 0; i--){
        divide[i]=(rent*10+table[i])/x;
        rent=(rent*10+table[i])%x;
    }
    for (int i = divide[len-1]==0 && len!=1?len-2:len-1; i >= 0; i--){
        cout<<divide[i];
    }
    std::cout << " "<<rent << std::endl;
}
void getResult(string s,int x){
    int cnt=0;
    for (int i = s.length()-1; i >=0; i--)
    {
        table[cnt]=s[i]-'0';
        cnt++;
    }
    powDivide(cnt,x);
}
int main(int argc, char const *argv[])
{
    string s;
    int x;
    cin>>s>>x;
    getResult(s,x);
    return 0;
}
