#include <iostream>
#include <algorithm>
using namespace std;

string simplize(string s){
    string ans="";
    bool flag=false;
    string mid;
    if(s[0]=='-'){
        ans+='-';
        mid=s.substr(1,s.find('.')-1);
        for (int i = 0; i < mid.length(); i++)
        {
            if(flag==false && mid[i]=='0') continue;
            ans+=mid[i];
            flag=true;
        }
        if(ans=="-") ans+='0';
        for (int i = s.find('.'); i < s.length(); i++)
            ans+=s[i];
        return ans;
    }else
    {
        mid=s.substr(0,s.find('.')-1);
        for (int i = 0; i < mid.length(); i++)
        {
            if(flag==false && mid[i]=='0') continue;
            ans+=mid[i];
            flag=true;
        }
        if(ans=="") ans+='0';
        for (int i = s.find('.'); i < s.length(); i++)
            ans+=s[i];
        return ans;
    }
}

void translate(string s){
    string mid,ans="",num;
    int pos=0;
    int cnt=0;
    mid=s.substr(1,s.find('E')-2);
    num=s.substr(s.find('E')+2,s.length()-s.find('E')-1);
    for (int i = 0; i < num.length(); i++)
        pos=pos*10+num[i]-'0';
    if(pos==0) {
        if(s[0]=='+')
            std::cout << s.substr(1,s.find('E')-1) << std::endl;
        else
            std::cout <<"-"<< s.substr(1,s.find('E')-1) << std::endl;
        return;
    }
    if(s[0]=='+' && s[s.find('E')+1]=='+'){
        ans+=s[1];
        for (int i = 3; i < s.find('E'); i++)
        {   
            ans+=s[i];
            cnt++;
            if(cnt==pos){
                ans+=s[i];
                ans+=".";
            } 
        }
        while (cnt<pos)
        {
            ans+='0';
            cnt++;
        }
        std::cout << simplize(ans) << std::endl;
        return;
    }
    if(s[0]=='+' && s[s.find('E')+1]=='-'){
        for (int i = s.find('E')-1; i >= 1; i--)
            if(s[i]!='.') ans+=s[i];
        while (cnt<(pos-1))
        {
            ans+='0';
            cnt++;
        }
        ans+='.';
        ans+='0';
        reverse(ans.begin(),ans.end());
        std::cout << ans << std::endl;
        return;
    }
    if (s[0]=='-' && s[s.find('E')+1]=='+')
    {
        ans+='-';
        ans+=s[1];
        for (int i = 3; i < s.find('E'); i++)
        {   
            ans+=s[i];
            cnt++;
            if(cnt==pos && s[1]=='0'){
                ans+=s[i];
                ans+=".";
            } 
            if (cnt==pos && s[1]!='0')
            {
                ans+=".";
                ans+=s[i];
            }
        }
        while (cnt<pos)
        {
            ans+='0';
            cnt++;
        }
        std::cout << simplize(ans) << std::endl;
        return;
    }
    if (s[0]=='-' && s[s.find('E')+1]=='-')
    {
        for (int i = s.find('E')-1; i >= 1; i--)
            if(s[i]!='.') ans+=s[i];
        while (cnt<(pos-1))
        {
            ans+='0';
            cnt++;
        }
        ans+='.';
        ans+='0';
        ans+='-';
        reverse(ans.begin(),ans.end());
        std::cout << ans << std::endl;
        return;
    }
}
int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    translate(s);
    return 0;
}
