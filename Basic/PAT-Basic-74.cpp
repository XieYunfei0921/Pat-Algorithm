#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
bool judge(string s){
    bool pt[2]={false,false};
    int left=-1,right=-1;
    // 寻找唯一的PT的位置 ,有之前的判定,其他位置必定是A
    // 确保PT的唯一性
    for (int i = 0; i < s.length(); i++)
    {
        if(pt[0]==false && s[i]=='P') {left=i;pt[0]=true;}
        if(pt[1]==false && s[i]=='T') {right=i;pt[1]=true;}
    }
    if(right<left+2) return false;
    int ANum=right-left-2;
    int front=left;
    for (int i = left+1; i < s.length()-ANum; i++)
        s[i]=s[i+ANum];
    s=s.substr(0,s.length()-ANum);
    string words=s.substr(0,s.length()-ANum*left);
    int newleft,newright;
    for (int i = 0; i < words.length(); i++)
    {
        if(s[i]=='P') newleft=i;
        if(s[i]=='T') newright=i;
    }
    if(newleft!=words.length()-1-newright) return false;
    return true; 
}
int main(int argc, char const *argv[])
{
    int n;bool flag;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin>>str;
        flag=true;
        for (int i = 0; i < str.length(); i++)
            if(str[i]!='P' && str[i]!='A' && str[i]!='T') flag=false;
        if(!flag) {std::cout << "NO" << std::endl;continue;}
        else{
            if(judge(str)) {std::cout << "YES" << std::endl;continue;}
            else {std::cout << "NO" << std::endl;continue;}
        }
    }
    return 0;
}
