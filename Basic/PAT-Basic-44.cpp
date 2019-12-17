#include <iostream>
#include <string>
using namespace std;
const int MOD=1000000007;
int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    int frontP=0,backT=0,total=0;
    for (int i = 0; i < count; i++)
        if(s[i]=='T') backT++;
    for (int i = 0; i < s.length(); i++){
        if(s[i]=='P') frontP++;
        if(s[i]=='T') backT--;
        // 防止乘积过大
        if(s[i]=='A') {total=(total+(frontP*backT)%MOD)%MOD;}
    }
    cout<<total%MOD;
    return 0;
}
/*
    QA: 运行超市N^2复杂度不行
    考虑到只有APT三个字符,找到了A字符的位置其他位置不是P字符就是T字符
    现在考虑一下:
    以A为中心,计算前面的p和后面的t
    p正序遍历求出即可
    t倒叙求比较方便  
    经验: 不要迷惑于表象,先去求证理论可行的表达式,按照方案实施  
*/
