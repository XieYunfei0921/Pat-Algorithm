#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
struct Node{
    char c;
    int num;
    void show(){
        if(this->num!=1) cout<<this->num<<this->c;
        else cout<<this->c;
    }
    void decode(){
        for (int i = 0; i < this->num; i++)
            cout<<this->c;
    }
};
vector<Node> v;
void compress(string s){
    int left=0,right=0,cnt=0;
    while (left<s.length())
    {
        if(left==s.length()-1) {Node n={s[left],1};v.push_back(n);break;}
        if(right==s.length()-1 && s[left]==s[right]) {Node n={s[left],right-left};v.push_back(n);break;}
        if(s[left]==s[right]){
            right++;
        }
        else{
            Node n={s[left],right-left};
            v.push_back(n);
            left=right;
        }
    }
    for (int i = 0; i < v.size(); i++)
        v[i].show();
}
Node translate(string s){
    char c=s[s.length()-1];
    int num=0;
    if(s.size()!=1){
        for (int i = 0; i < s.length()-1; i++)
            num=num*10+s[i]-'0';
    }
    else num=1;
    Node n={c,num};
    return n;
}
void depress(string s){
    int left=0,right=0;
    while (left<s.length())
    {
        if(!(s[right]<='9' && s[right]>='0')){
            Node n=translate(s.substr(left,right-left+1));
            left=right+1;
            right=left;
            v.push_back(n);
        }else{
            right++;
        }
    }
    for (int i = 0; i < v.size(); i++)
        v[i].decode();
}

int main(int argc, char const *argv[])
{
    char type;string s;
    cin>>type;
    cin.ignore();
    getline(cin,s);
    if(type=='C') compress(s);
    if(type=='D') depress(s);
    return 0;
}
