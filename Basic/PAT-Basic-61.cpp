#include <iostream>
#include <algorithm>
#include <string>
#include <stack>
using namespace std;
void translate(string s){
    int n=0;
    for (int i = 0; i < s.length(); i++)
        n=n*10+s[i]-'0';
    std::cout << n << std::endl;
}
int main(int argc, char const *argv[])
{
    string s,s1,s2;
    cin>>s>>s1>>s2;
    int sign=0;
    char num;
    string st;
    reverse(s.begin(),s.end());
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    s1.append(s.length()-s1.length(),'0');
    s2.append(s.length()-s2.length(),'0');
    for (int i = 0; i <s.length(); i++)
    {   
        num=(s1[i]-'0'+s2[i]-'0'+sign)%(s[i]-'0'==0?10:s[i]-'0')+'0';
        sign=(s1[i]-'0'+s2[i]-'0'+sign)/(s[i]-'0'==0?10:s[i]-'0');
        st.append(1,num);
    }   
    if(sign>=1)
        st.append(1,'1');
    reverse(st.begin(),st.end());
    translate(st);
    return 0;
}
