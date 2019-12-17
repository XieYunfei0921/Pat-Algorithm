#include <iostream>
#include <algorithm>
using namespace std;
string low[13]={"tret","jan","feb","mar","apr","may","jun","jly","aug","sep","oct","nov","dec"};
string high[13]={"","tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
string toMars(string s){
    int num=0;string st="";
    for (int i = 0; i < s.length(); i++)
        num=num*10+s[i]-'0';
    if(num/13!=0){
        st+=high[num/13];
        if(num%13!=0){
            st+=" ";
            st+=low[num%13];
        }
    }
    else
        st+=low[num%13];
    return st;
}
int toEarth(string s){
    int ans=0;
    if(s.find(" ")==string::npos){
        for (int i = 0; i < 13; i++)
        {
            if(low[i]==s){
                ans+=i;
                break;
            }
        }
        for (int i = 0; i < 13; i++)
        {
            if(high[i]==s){
                ans+=i*13;
                break;
            }
        }
    }else{
        string h=s.substr(0,s.find(" "));
        for (int i = 0; i < 13; i++)
        {
            if(high[i]==h){
                ans+=i*13;
                break;
            }
        }
        string l=s.substr(s.find(" ")+1,s.length()-s.find(" ")+1);
        for (int i = 0; i < 13; i++)
        {
            if(low[i]==l){
                ans+=i;
                break;
            }
        }
    }
    return ans;
}
int main(int argc, char const *argv[])
{
    int n;string s;
    cin>>n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        getline(cin,s);
        if(s[0]<='9' && s[0]>='0'){
            std::cout << toMars(s) << std::endl;
        }else
        {
            std::cout << toEarth(s) << std::endl;
        }
        
    }
    
    return 0;
}
