#include <iostream>
#include <cstring>
#include <stdio.h>
using namespace std;
int pow(int base,int times){
    int mul=1;
    while (times--)
        mul=mul*base;
    return mul;
}
int main(int argc, char const *argv[])
{
    int n;string s;double sum=0.0;int cnt=0,num=0;bool flag;
    string str="0123456789-.";
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>s;
        flag=true;
        int index=-1,sign=1,mul=0;
        for (int i = s.length()-1; i >=0; i--)
        {   
            if(str.find(s[i])==string::npos) {flag=false;break;}
            if((s[i]=='.' && i<s.length()-3 && i!=s.length()-1) || (s[i]=='.' && index!=-1)) {flag=false;break;}
            if(s[i]=='-' && i!=0){flag=false;break;}
            if(s[0]=='-' && s[1]=='0' && s.length()>2 && s[2]!='.'){flag=false;break;}
            if(s[i]=='0' && i==0 && s[1]!='.'){flag=false;break;}
            if(s[i]=='.' && index==-1){index=i;continue;}
            if(i!=0) mul=mul+(s[i]-'0')*pow(10,cnt);
            else {
                if(s[i]=='-') mul=-mul;
                else mul=mul+(s[i]-'0')*pow(10,cnt);
            }
            cnt++;
        }
        cnt=0;
        if(flag) {
            double res=index==-1?(double)mul:(double)mul/pow(10,s.length()-1-index);
            if(res>1000 || res<-1000) {flag=false;std::cout<<"ERROR: " << s<<" is not a legal number" << std::endl;}
            if(flag==true) {sum+=res;num++;}
        }else
            std::cout<<"ERROR: " <<s <<" is not a legal number" << std::endl;
    }
    if(num==1) printf("The average of 1 number is %.2f",sum);
    else if(num!=0) printf("The average of %d numbers is %.2f",num,sum/num);
    else printf("The average of 0 numbers is Undefined");
    return 0;
}