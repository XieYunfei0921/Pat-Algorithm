#include <iostream>
#include <map>
using namespace std;
int main(int argc, char const *argv[])
{   
    string a,b;
    getline(cin,a);
    getline(cin,b);
    map<char,bool> smap;
    for (int i = 0; i < a.length(); i++)
    {
        if (smap.find(a[i])->second==false)
        {
            cout<<a[i];
            smap[a[i]]=true;
        }
    }
    for (int i = 0; i < b.length(); i++)
    {
        if (smap.find(b[i])->second==false)
        {
            cout<<b[i];
            smap[b[i]]=true;
        }
    }
    return 0;
}
