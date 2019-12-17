#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main(int argc, char const *argv[])
{
    string s1,s2;
    cin>>s1>>s2;
    bool flag=true;
    int num=0,cnt=0;
    map<char,int> countMap;
    for (int i = 0; i < s2.length(); i++)
        countMap[s2[i]]-=1;
    for (int i = 0; i < s1.length(); i++)
        countMap[s1[i]]+=1;
    for (map<char,int>::iterator i = countMap.begin(); i != countMap.end(); i++)
    {
        if(i->second<0){
            flag=false;
            num+=i->second;
        }
    }
    if(!flag) {std::cout << "No "<<-num << std::endl;return 0;}
    for (map<char,int>::iterator i = countMap.begin(); i != countMap.end(); i++)
        cnt+=i->second;
    std::cout << "Yes "<<cnt << std::endl;
    return 0;
}
