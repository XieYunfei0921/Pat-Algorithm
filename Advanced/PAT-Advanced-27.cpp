#include <iostream>
#include <algorithm>
using namespace std;
string move(string opt,string bits){
    int sign=bits[0]=='+'?1:-1;
    int num=0;
    string s="";
    for (int i = 1; i < bits.length(); i++)
        num=num*10+bits[i]-'0';
    num*=sign;
    if(num==0) return opt;
    if(num>0){
        s+=opt[0];s+=opt[2];
        int index=2;
        num--;
        while (num>0)
        {   
            index++;
            if(index<opt.length())
                s+=opt[index];
            else
                s+='0';
            num--;
        }
        for (int i = index+1; i < opt.length(); i++)
        {
            if(i==index+1) {s+='.';s+=opt[i];}
            else s+=opt[i];
        }
    }else{
        num=-num;
        for (int i = opt.length()-1; i >=0; i--)
            if(opt[i]!='.') s+=opt[i];
        num--;
        while (num>0)
        {
            s+='0';
            num--;
        }
        s+=".0";
        reverse(s.begin(),s.end());
    }
    return s;
}
int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    string sign=s[0]=='+'?"":"-";
    string opt=s.substr(1,s.find('E')-1);
    string bits=s.substr(s.find('E')+1,s.length()-s.find('E'));
    std::cout << sign<<move(opt,bits) << std::endl;
    return 0;
}
