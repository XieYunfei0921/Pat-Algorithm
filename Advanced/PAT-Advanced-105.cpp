#include <iostream>
#include <map>
#include <cctype>
using namespace std;
map<string,int> mp;
/*
    最后一个字符如果合法也要计算
*/
int main(int argc, char const *argv[]){
    string s,temp;
    getline(cin,s);
    temp="";
    int start=0;
    for (int i = start; i < s.length(); i++){
        if (isdigit(s[i]) || isalpha(s[i])){
            if(s[i]<='Z' && s[i]>='A') temp+=s[i]-'A'+'a';
            else temp+=s[i];
        }
        if(!(isdigit(s[i]) || isalpha(s[i])) || i==s.length()-1){
            if(temp!="") mp[temp]++;
            temp="";
        }
    }
    int maxn=0;string mw;
    for (map<string,int>::iterator i = mp.begin(); i != mp.end(); i++){
        if(i->second>maxn){
            maxn=i->second;
            mw=i->first;
        }
    }
    cout<<mw<<" "<<maxn;
    return 0;
}