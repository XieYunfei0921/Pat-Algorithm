#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
int gdb(int a,int b){
    return b==0?a:gdb(b,a%b);
}
int lcm(int a,int b){
    return a*b/gdb(a,b);
}
string translate(int a,int b){
    string s="",s1="",s2="";
    while (a>0)
    {
        s+=a%10+'0';
        a/=10;
    }
    reverse(s.begin(),s.end());
    s2.append(s);
    s2.append("/");
    while (b>0)
    {
        s1+=b%10+'0';
        b/=10;
    }
    reverse(s1.begin(),s1.end());
    s2.append(s1);
    return s2;
    
}
int main(int argc, char const *argv[])
{   
    int a1,b1,a2,b2,c;string s;
    vector<string> v;
    scanf("%d/%d %d/%d %d",&a1,&b1,&a2,&b2,&c);
    int maxn=lcm(c,lcm(b1,b2));
    int x1=min(a1*maxn/b1,a2*maxn/b2);
    int x2=max(a1*maxn/b1,a2*maxn/b2);
    for (int i = 1; i < c; i++)
        if(gdb(c,i)==1 && i*maxn/c>x1 && i*maxn/c<x2) {v.push_back(translate(i,c));}
    for (int i = 0; i < v.size(); i++)
    {
        if(i!=v.size()-1) cout<<v[i]<<" ";
        else cout<<v[i];
    }
    return 0;
}
