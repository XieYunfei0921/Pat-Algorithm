#include <iostream>
using namespace std;
int table[38];
bool flags[38];
char toUpper(char c){
    if(c<='z' && c>='a')
        c=c-'a'+'A';
    return c;
}
void setBit(char c){
    char org=toUpper(c);
    if(org<='9' && org>='0')
        table[org-'0']=1;
    if(org<='Z' && org>='A')
        table[10+org-'A']=1;
    if(org=='_') table[37]=1;
}
bool findBit(char c){
    char org=toUpper(c);
    if(org<='9' && org>='0')
        return table[org-'0']!=0;
    if(org<='Z' && org>='A')
        return table[10+org-'A']!=0;
    if(org=='_') 
        return table[37]!=0;
}
bool findStatus(char c){
    char org=toUpper(c);
    if(org<='9' && org>='0')
        return flags[org-'0'];
    if(org<='Z' && org>='A')
        return flags[10+org-'A'];
    if(org=='_') 
        return flags[37];
}
void setStatus(char c,bool b){
    char org=toUpper(c);
    if(org<='9' && org>='0')
        flags[org-'0']=b;
    if(org<='Z' && org>='A')
        flags[10+org-'A']=b;
    if(org=='_') 
        flags[37]=b;
}
int main(int argc, char const *argv[])
{
    fill(table,table+38,0);
    fill(flags,flags+38,false);
    string s1,s2;
    cin>>s1>>s2;
    for (int i = 0; i < s2.length(); i++)
        setBit(s2[i]);
    for (int i = 0; i < s1.length(); i++){
        if(!findBit(s1[i]) && findStatus(s1[i])==false){
            cout<<toUpper(s1[i]);
            setStatus(s1[i],true);
        } 
    }
    return 0;
}
