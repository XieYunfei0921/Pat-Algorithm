#include <iostream>
using namespace std;
int toInt(string s){
    int num=0;
    for (int i = 0; i < s.length(); i++)
        num=num*10+s[i]-'0';
    return num;
}
int main(int argc, char const *argv[])
{
    int n,len,front,back;string s;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>s;
        len=s.length();
        front=toInt(s.substr(0,len/2));
        back=toInt(s.substr(len/2,len/2));
        if(front*back!=0 && toInt(s)%(front*back)==0) cout<<"Yes"<<"\n";
        else cout<<"No"<<"\n";
    }
    return 0;
}
