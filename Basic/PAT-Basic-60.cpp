#include <iostream>
#include <algorithm>
using namespace std;
bool status[10000]={false};
int getNumber(string s){
    int num=0;
    for (int i = 0; i <s.length(); i++)
        num=num*10+s[i]-'0';
    return num;
}
int main(int argc, char const *argv[])
{
    int n,m,k,ss=0,cnt=0;
    bool flag;
    cin>>n>>m;
    for (int i = 0; i < m; i++)
    {
        string s1;
        cin>>s1;
        status[getNumber(s1)]=true;
    }
    for (int i = 0; i < n; i++)
    {
        string name;
        string str="";
        cin>>name>>k;
        flag=false;
        for (int j = 0; j < k; j++)
        {
            string id;
            cin>>id;
            if(status[getNumber(id)]==true){
                cnt++;
                flag=true;
                str+=" ";
                str+=id;
            }
        }
        if(flag) {ss++;std::cout << name<<":"<<str << std::endl;}
        str.clear();
    }
    std::cout << ss<<" "<<cnt << std::endl;
    return 0;
}
