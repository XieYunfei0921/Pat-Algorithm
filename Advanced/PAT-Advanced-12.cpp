#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
bool change(string &s){
    bool flag=true;
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]=='1') {s[i]='@';flag=false;}
        if(s[i]=='l') {s[i]='L';flag=false;}
        if(s[i]=='0') {s[i]='%'; flag=false;}
        if(s[i]=='O') {s[i]='o';flag=false;}
    }
    return flag;
}
int main(int argc, char const *argv[])
{
    int n,cnt=0;string id,pwd,ans="";
    cin>>n;
    vector<string> v;
    for (int i = 0; i < n; i++)
    {
        cin>>id>>pwd;
        if(!change(pwd)){
            ans=id+" "+pwd;
            v.push_back(ans);
            cnt++;
        }
    }
    if(cnt==0){
        if(n==1) std::cout << "There is 1 account and no account is modified" << std::endl;
        else std::cout <<"There are "<< n <<" accounts and no account is modified" << std::endl;
    }else
    {
        std::cout << cnt << std::endl;
        for (int i = 0; i < v.size(); i++)
            std::cout << v[i] << std::endl;
    }
    return 0;
}
