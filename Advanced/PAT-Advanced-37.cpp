#include <iostream>
#include <map>
#include <set>
#include <vector>
using namespace std;
bool isLegal(string s){
    char c=s[0];
    if(s.length()==1) return true;
    for (int i = 1; i < s.length(); i++)
        if(s[i]!=c) return false;
    return true;
}
struct Node{
    char c;
    int num;
};
/*
    坏键条件:
    最长连续相同字符串长度是给定长度的正整数倍
*/
int main(int argc, char const *argv[]){
    int k;string s,temp;
    set<char> ok;
    vector<Node> v;
    vector<char> v1,v2;
    cin>>k>>s;
    int left=0,step=1;
    while (left+step<s.length())
    {
        temp=s.substr(left,step);
        if(isLegal(temp)==true){
            step++;
        }else{
            v.push_back(Node{s[left],--step});
            left++;
            step=1;
        }
    }
    while (left<s.length())
    {
        v.push_back(Node{s[left],1});
    }
    
    for (int i = 0; i < v.size(); i++)
    {
        if(v[i].num%k==0 && ok.count(v[i].c)==0){
            v1.push_back(v[i].c);
        }else{
            std::cout << "Put "<<v[i].c<<"\tNum= "<<v[i].num << std::endl;
            v2.push_back(v[i].c);
            ok.insert(v[i].c);
        }
    }
    
    for (int i = 0; i < v1.size(); i++)
        cout<<v1[i];
    cout<<"\n";
    for (int i = 0; i < v2.size(); i++)
        cout<<v2[i];
    return 0;
}