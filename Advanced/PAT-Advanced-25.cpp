#include <iostream>
#include <algorithm>
#include <cctype>
using namespace std;
int main(int argc, char const *argv[])
{   
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    string s="";
    int len1=min(s1.length(),s2.length());
    int index;
    for (int i = 0; i < len1; i++)
        if(s1[i]==s2[i] && s1[i]<='G' && s1[i]>='A') {s+=s1[i];index=i;break;}
    for (int i = index+1; i < len1; i++)
        if(s1[i]==s2[i] &&((s1[i]<='N' && s1[i]>='A') || isdigit(s1[i]))) {s+=s1[i];break;}
    int len2=min(s3.length(),s4.length());
    for (int i = 0; i < len2; i++){
        if(s3[i]==s4[i] && isalpha(s3[i])) {
            index=i;
            break;
        }
    }
    switch (s[0])
    {
        case 'A':cout<<"MON "; break;
        case 'B':cout<<"TUE "; break;
        case 'C':cout<<"WED "; break;
        case 'D':cout<<"THU "; break;
        case 'E':cout<<"FRI "; break;
        case 'F':cout<<"SAT "; break;
        case 'G':cout<<"SUN "; break;
    }    
    if(isdigit(s[1]))
        cout<<"0"<<s[1]-'0'<<":";
    else 
        cout<<10+s[1]-'A'<<":";
    if(index>9)
        cout<<index;
    else
        cout<<"0"<<index;
    return 0;
}
