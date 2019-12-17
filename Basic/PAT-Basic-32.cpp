#include <iostream>
#include <algorithm>
#include <map>
#include <cctype>
using namespace std;
char toUpperCase(char c){
    if(c<='z' && c>='a') return c-'a'+'A';
    return c;
}

void deal(string s1,string s2){
    string ans;
    for (int i = 0; i < s1.length(); i++)
    if (s2.find(s1[i]) == string::npos && ans.find(toupper(s1[i])) == string::npos)
        ans += toupper(s1[i]);
    cout << ans;
}

bool isSameWord(char c1,char c2){
    if(toUpperCase(c1)==toUpperCase(c2)) return true;
    else return false;
}

int main(int argc, char const *argv[])
{
    string s1,s2;
    map<char,bool> status;
    int p1=0,p2=0;
    cin>>s1>>s2;
    while (p1<s1.length() || p2<s2.length())
    {   
        if(!isSameWord(s1[p1],s2[p2])){
            if(status.find(toUpperCase(s1[p1]))->second==false){
                cout<<toUpperCase(s1[p1]);
                status[toUpperCase(s1[p1])]=true;
            }
            p1++;
        }
        else{p1++;p2++;}
    }
    return 0;
}
