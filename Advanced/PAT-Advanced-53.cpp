#include <iostream>
#include <algorithm>
using namespace std;
bool isParlidromic(string s){
    if(s.length()==0) return true;
    int left=0,right=s.length()-1;
    while (left<=right)
    {
        if(s[left]!=s[right]) return false;
        left++;
        right--;
    }
    return true;
}
string add(string s){
    string s1=s;
    reverse(s1.begin(),s1.end());
    int sign=0;
    string s2;
    for (int i = 0; i < s.length(); i++)
    {
        s2+=s1[i]-'0'+s[i]-'0'+sign>=10?sign+s1[i]-'0'+s[i]-'0'-10+'0':sign+s1[i]-'0'+s[i]-'0'+'0';
        sign=s1[i]-'0'+s[i]-'0'+sign>=10?1:0;
    }
    if(sign==1) s2+='1';
    reverse(s2.begin(),s2.end());
    return s2;
}
int main(int argc, char const *argv[])
{
    string s;int n,temp;
    cin>>s>>n;
    temp=0;
    if(isParlidromic(s)){
        std::cout << s<<"\n"<<0 << std::endl;
        return 0;
    }
    while (temp<n)
    {
        s=add(s);
        if(isParlidromic(s)){
            std::cout << s << std::endl;
            std::cout << temp+1 << std::endl;
            return 0;
        }
        temp++;
    }
    std::cout << s << std::endl;
    std::cout << n << std::endl;
    return 0;
}
