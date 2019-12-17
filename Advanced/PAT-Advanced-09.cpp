#include <iostream>
#include <algorithm>
using namespace std;
int toNum(char c){
    if(c>='a' && c<='z') return 10+c-'a';
    return c-'0';
}
long long toDecibal(string s,int radix){
    int num=0;
    for (int i = 0; i < s.length(); i++)
        num=num*radix+toNum(s[i]);
    return num;
}
int smallRadix(string s){
    int maxc=toNum('0');
    for (int i = 0; i < s.length(); i++)
        if(toNum(s[i])>maxc) maxc=toNum(s[i]);
    return maxc+1;
}
int main(int argc, char const *argv[])
{
    string n1,n2;int tag,radix;
    int rad;
    cin>>n1>>n2>>tag>>radix;    
    string org=tag==1?n1:n2;
    string oth=tag==1?n2:n1;
    long long val=toDecibal(org,radix);
    int least=smallRadix(oth);
    long long v2=toDecibal(oth,least);
    if(v2>val){std::cout << "Impossible" << std::endl;return 0;}
    while (least<=36)
    {
        v2=toDecibal(oth,least);
        if(v2==val){std::cout << least << std::endl;return 0;}
    }
    return 0;
}
