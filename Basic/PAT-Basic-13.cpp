#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;

int translate(string s){
    int code=0;
    for (int i = 2; i < s.length(); i+=4)
    {
        if(s[i]=='T')
            code=s[i-2]-'A'+1;
    }
    return code;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    string s;
    int table[n];
    cin.ignore();
    for (int i = 0; i < n; i++){
        getline(cin,s);
        if(s.length()==15)
            table[i]=translate(s);
    }
    for (int i = 0; i < n; i++)
        cout<<table[i];
    return 0;
}
