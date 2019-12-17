#include <iostream>
#include <map>
using namespace std;
int main(int argc, char const *argv[])
{
    string s1,s2;
    cin>>s1>>s2;
    map<char,int> cmap;
    for (int i = 0; i < s1.length(); i++){
        if(cmap.count(s1[i])==0) cmap[s1[i]]=1;
        else cmap[s1[i]]++;
    }
    for (int i = 0; i < s2.length(); i++){
        if(cmap.count(s2[i])==0) cmap[s2[i]]=-1;
        else cmap[s2[i]]--;
    }
    int pos=0,neg=0;
    for (map<char,int>::iterator i = cmap.begin(); i != cmap.end(); i++)
    {
        if(i->second>0) pos+=i->second;
        if(i->second<0) neg+=i->second;
    }
    
    if(neg!=0)
        std::cout << "No " <<-neg;
    else
        std::cout << "Yes " <<pos;
    return 0;
}
