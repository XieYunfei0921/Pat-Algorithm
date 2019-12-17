#include <iostream>
#include <algorithm>
using namespace std;
bool isPalindromic(string s){
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
    int sign=0;
    string ans="";
    string s1=s;
    reverse(s.begin(),s.end());
    for (int i = 0; i < s.length(); i++)
    {
        ans+=sign+s1[i]-'0'+s[i]-'0'>=10?sign+s1[i]-'0'+s[i]-'0'-10+'0':sign+s1[i]-'0'+s[i]-'0'+'0';
        sign=sign+s1[i]-'0'+s[i]-'0'>=10?1:0;
    }
    if(sign>0) ans+='1';
    reverse(ans.begin(),ans.end());
    std::cout << s1<<" + "<<s<<" = "<<ans << std::endl;
    return ans;
}
int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    for (int i = 1; i <= 10; i++)
    {
        if(isPalindromic(s)) {
            std::cout << s<<" is a palindromic number." << std::endl;
            return 0;
        }
        s=add(s);
    }
    std::cout << "Not found in 10 iterations." << std::endl;
    return 0;
}
