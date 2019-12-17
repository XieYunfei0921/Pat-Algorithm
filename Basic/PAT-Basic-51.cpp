#include <iostream>
#include <algorithm>
using namespace std;
int tab[2];
bool isChar(char c){
    if((c<='Z'&&c>='A')||(c<='z'&& c>='a'))
        return true;
    return false;
}
int getId(char c){
    if(c<='Z' && c>='A') return c-'A'+1;
    else return c-'a'+1;
}
int main(int argc, char const *argv[])
{
    string s;int sum=0;
    getline(cin,s);
    for (int i = 0; i < s.length(); i++)
        if(isChar(s[i])) sum+=getId(s[i]);
    while (sum!=0)
    {
        tab[sum%2]+=1;
        sum/=2;
    }
    std::cout << tab[0]<<" "<<tab[1] << std::endl;
    return 0;
}
