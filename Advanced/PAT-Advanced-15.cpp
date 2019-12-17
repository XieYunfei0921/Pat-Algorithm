#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
int sta[10]={0};
int main(int argc, char const *argv[])
{
    string s;string ans="";int sign=0;
    bool flag=true;
    cin>>s;
    for (int i = s.length()-1; i >=0; i--)
    {
        sta[s[i]-'0']++;
        ans+=((s[i]-'0')*2+sign)%10+'0';
        sign=(s[i]-'0')*2+sign>9?1:0;
    }
    if(sign==1) {ans+='1';sta[1]++;}
    reverse(ans.begin(),ans.end());
    for (int i = 0; i < ans.size(); i++)
        sta[ans[i]-'0']--;
    for (int i = 0; i < 10; i++)
        if(sta[i]!=0) {flag=false;break;}
    if(!flag) {
        std::cout << "No" << std::endl;
        std::cout << ans << std::endl;
    }
    else {
        std::cout << "Yes" << std::endl;
        std::cout << ans << std::endl;
    }
    return 0;
}
