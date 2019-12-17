#include <iostream>
#include <stdio.h>
#include <set>
#include <math.h>
using namespace std;
/*
    待完善： 重新考虑边界条件

*/
set<char> sc;
void init(){
    string s="0123456789.-";
    for (int i = 0; i < s.length(); i++)
        sc.insert(s[i]);
}
double toDouble(string s){
    int num=0;
    int div=1;
    bool flag=true;
    if(s[0]=='-') flag=false;
    else num=s[0]-'0';
    if(s[s.length()-3]=='.') div=100;
    if(s[s.length()-2]=='.') div=10;
    for (int i = 1; i < s.length(); i++)
    {
        if(s[i]=='.') continue;
        num=num*10+s[i]-'0';
    }
    if(!flag) num=-num;
    return (double)num/div;
}
bool isLegal(string s){
    int cntP=0,cntT=0,index=-1;
    if(s[0]!='-' && !isdigit(s[0])){return false;} 
    if(s[s.length()-1]=='.'){return false;} 
    for (int i = 1; i < s.length(); i++){
        if(sc.count(s[i])==0) {return false;}
        if(s[i]=='.' && !isdigit(s[i-1])) return false;
        if(s[i]=='.') {cntP++;index=i;}
        if(s[i]=='-') cntT++;
    }
    if(cntT>0 || cntP>1) {return false;}
    if(index<s.length()-3) return false;
    return true;
}
int main(int argc, char const *argv[])
{
    init();
    int n,cnt=0;string s;double sum=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {   
        cin>>s;
        if(isLegal(s)){
            if(toDouble(s)<1001 && toDouble(s)>-1001){
                sum+=toDouble(s);
                cnt++;
            }else{
                std::cout << "ERROR: "<< s <<" is not a legal number" << std::endl;
            }
        }
        else
            std::cout << "ERROR: "<< s <<" is not a legal number" << std::endl;
    }
    if(cnt==0) {
        std::cout << "The average of 0 numbers is Undefined" << std::endl;
    }else if (cnt==1)
    {
        printf("The average of 1 number is %.2f",sum);
    }else{
        printf("The average of %d numbers is %.2f",cnt,sum/cnt);
    }
    return 0;
}
