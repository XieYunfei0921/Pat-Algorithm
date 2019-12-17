#include <iostream>
#include <algorithm>
using namespace std;
string toString(int n){
    string s="";
    while (n>0)
    {
        s+=n%10+'0';
        n/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}
string getNext(string s){
    int left=0,right=0;
    string ans="";
    while (right<=s.length())
    {
        if(s[left]==s[right]){
            right++;
            continue;
        }else{
            ans+=s[left];
            ans+=toString(right-left);
            left=right;
            right=left;
        }
    }
    return ans;   
}
int main(int argc, char const *argv[])
{
    int d,f;
    cin>>d>>f;
    string s=toString(d);
    while (--f)
    {
        s=getNext(s);
    }
    std::cout << s << std::endl;
    return 0;
}
