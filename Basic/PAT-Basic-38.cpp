#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
using namespace std;
bool status[67]={false};
int findIndex(char x){
    int index=-1;
    if(x<='z' && x>='a')  {index=x-'a';return index;}
    if(x<='Z' && x>='A')  {index=x-'A'+26;return index;}
    if(x<='9' && x>='0')  {index=x-'0'+52;return index;}
    switch (x)
    {
        case '_': index=62;break;
        case ',': index=63;break;
        case '.': index=64;break;
        case '-': index=65;break;
        case '+': index=66;break;
        default: index=-1;break;
    }
    return index;
}
void setIndex(char c){
    if(c=='+'){
        for (int i = 26; i < 52; i++)
            status[i]=true;
    }
    if(c<='Z' && c>='A')
        status[findIndex(c)-26]=true;
    status[findIndex(c)]=true;
}
/*
    注意没坏的场景,不能使用cin输入,使用getline输入
*/
int main(int argc, char const *argv[])
{
    string s1,s2;
    getline(cin,s1);
    getline(cin,s2);
    for (int i = 0; i < s1.length(); i++)
        setIndex(s1[i]);
    for (int i = 0; i < s2.length(); i++)
        if(status[findIndex(s2[i])]==false) cout<<s2[i];
    return 0;
}

