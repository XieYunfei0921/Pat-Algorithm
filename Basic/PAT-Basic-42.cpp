#include <iostream>
#include <algorithm>
using namespace std;
int tab[26];
void put(char c){
    if(c<='Z' && c>='A') c=c-'A'+'a';
    if(!(c<='z' && c>='a')) return;
    tab[c-'a']+=1;
}
int main(int argc, char const *argv[])
{
    string s;
    getline(cin,s);
    for (int i = 0; i < s.length(); i++)
        put(s[i]);
    int maxn=0,index=-1;
    for (int i = 0; i < 26; i++)
    {
        if(tab[i]>maxn){
            maxn=tab[i];
            index=i;
        }
    }
    char c='a'+index;
    cout<<c<<" "<<tab[index];
    return 0;
}
