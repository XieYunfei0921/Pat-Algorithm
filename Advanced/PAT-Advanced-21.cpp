#include <iostream>
#include <set>
using namespace std;
int main(int argc, char const *argv[])
{
    string s1,s2;
    set<char> s;
    getline(cin,s1);
    getline(cin,s2);
    for (int i = 0; i < s2.length(); i++)
        s.insert(s2[i]);
    for (int i = 0; i < s1.length(); i++)
        if(s.count(s1[i])==0) cout<<s1[i];  
    return 0;
}
