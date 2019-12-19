#include <iostream>
#include <algorithm>
using namespace std;
/*
注意去除前导零
    题目没有把多个前导零的情况排除在外
*/
string toString(int x){
    string s="";
    while (x>0){
        s+=x%10+'0';
        x/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}
string translate(string s,int n){
    string ans;
    if(s=="0"){
        ans="";
        for (int i = 0; i < n; i++)
            ans.append("0");
        return "0."+ans+"*10^0";
    }
    // 去除前导零
    int point=0;
    while (s[0]=='0' && s[1]!='.'){
        s.erase(s.begin());
    }
    if(s=="") s="0";
    string temp="";
    int p=0,index=-1;
    if(s[0]>='1'){
        while (p<s.length()){
            if(s[p]=='.'){
                index=p;
            }else{
                temp+=s[p];
            }
            p++;
        }
    }else{
        p=2;bool flag=false;
        while (p<s.length()){
            if(!flag && s[p]!='0'){
                index=p;
                flag=true;
            }
            if(flag){
                temp+=s[p];
            }
            p++;
        }
        if(index!=-1)
            index=index-2;
    }
    if(n<=temp.size()){
        int v=index==-1?s.length():index;
        string str;
        if(s[0]=='0'){
            if(v==0 || v==-1) str="0";
            else str="-"+toString(v);
            ans="0."+temp.substr(0,n)+"*10^"+str;
        }
        else{
            str=toString(v);
            ans="0."+temp.substr(0,n)+"*10^"+str;
        }
    }else{
        int cur=temp.size();
        for (int i = cur; i < n; i++)
            temp.append("0");
        int v=index==-1?s.length():index;
        string str;
        if(s[0]=='0'){
            v=index==-1?0:index;
            if(v==0) str="0";
            else str="-"+toString(v);
            ans="0."+temp.substr(0,n)+"*10^"+str;
        }
        else{
            str=toString(v);
            ans="0."+temp.substr(0,n)+"*10^"+str;
        }
    }
    return ans;
}
int main(int argc, char const *argv[]){
    int n;
    string a,b;
    cin>>n>>a>>b;
    string s1=translate(a,n);
    string s2=translate(b,n);
    if(s1==s2) cout<<"YES"<<" "<<s1;
    else cout<<"NO"<<" "<<s1<<" "<<s2;
    return 0;
}
