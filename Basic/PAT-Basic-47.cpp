#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
/*
    考虑1000 78 --> 9078 而不是78
*/
int main(int argc, char const *argv[])
{
    string s1,s2;
    cin>>s1>>s2;
    reverse(s1.begin(),s1.end());
    reverse(s2.begin(),s2.end());
    if(s2.length()<s1.length()) s2.append(s1.length()-s2.length(),'0');
    for (int i = 0; i <s2.length(); i++)
    {
        if(i>=s1.length()) continue;
        if(i%2==0) {
            switch((s1[i]-'0'+s2[i]-'0')%13){
                case 10: s2[i]='J';break;
                case 11: s2[i]='Q';break;
                case 12: s2[i]='K';break;
                default: s2[i]=(s1[i]-'0'+s2[i]-'0')%13+'0';break;
            }
        }
        if(i%2==1) s2[i]=(s2[i]-s1[i]>=0)?s2[i]-s1[i]+'0':s2[i]-s1[i]+10+'0';
    }
    reverse(s2.begin(),s2.end());
    std::cout << s2 << std::endl;
    return 0;
}
