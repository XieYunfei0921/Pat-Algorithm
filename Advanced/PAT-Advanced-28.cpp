#include <iostream>
#include <algorithm>
using namespace std;
string getSuffix(string s,string suffix){
    int index;
    reverse(s.begin(),s.end());
    reverse(suffix.begin(),suffix.end());
    if(suffix.length()>s.length()) swap(suffix,s);
    string st=suffix;
    for (int i = 0; i < suffix.length(); i++)
        if(s[i]!=suffix[i]) {st=suffix.substr(0,i);index=i;break;}
    reverse(st.begin(),st.end());
    return st;
}
int main(int argc, char const *argv[])
{
    int n,index;
    string suffix,s;
    cin>>n;
    cin.ignore();
    getline(cin,s);
    suffix=s;
    for (int i = 0; i < n-1; i++)
    {
        getline(cin,s);
        suffix=getSuffix(s,suffix);
    }
    if(suffix.length()==0) {std::cout << "nai" << std::endl;return 0;}
    std::cout << suffix << std::endl;
    return 0;
}
