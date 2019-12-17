#include <iostream>
#include <algorithm>
using namespace std;
bool isBackNumber(string s){
    if(s=="0") return true;
    int mid=s.length()/2+1;
    for (int i = 0; i <=mid; i++)
        if(s[i]!=s[s.length()-1-i]) return false;
    return true;
}
string add(string s1,string s2){
    int len=s1.length();
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    int sign=0;
    string s="";
    for (int i = 0; i <len; i++)
    {
        s+=(sign+s1[i]-'0'+s2[i]-'0')%10+'0';
        sign=(sign+s1[i]-'0'+s2[i]-'0')/10;
    }
    if(sign!=0) s+=sign+'0';
    reverse(s.begin(),s.end());
    return s;
}
string opposite(string s){
    string s1="";
    reverse(s.begin(),s.end());
    s1+=s;
    return s1;
}
int main(int argc, char const *argv[])
{
    string str;
    cin>>str;
    for (int i = 0; i < 10; i++)
    {
        if(isBackNumber(str)) {std::cout << str<<" is a palindromic number." << std::endl;return 0;}
        std::cout << str <<" + "<<opposite(str)<<" = "<<add(str,opposite(str))<< std::endl;
        str=add(str,opposite(str));
    }
    std::cout << "Not found in 10 iterations." << std::endl;
    return 0;
}
