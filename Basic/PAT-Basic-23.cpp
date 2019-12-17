#include <iostream>
#include <algorithm>
#include <math.h>
#include <map>
using namespace std;
string table[7]={"MON","TUE","WED","THU","FRI","SAT","SUN"};
void getDayHour(string s1, string s2){
    int len=min(s1.length(),s2.length());
    int day,hour;
    int cnt=0;
    for (int i = 0; i < len; i++)
    {
        if(s1[i]==s2[i] && cnt==0 && (s1[i]>='A' && s1[i]<='G')) {day=s1[i]-'A'+1;cnt++;continue;}
        if(s1[i]==s2[i] && cnt==1 && (s1[i]>='A' && s1[i]<='N')) {hour=s1[i]-'A'+10;break;}
        if(s1[i]==s2[i] && cnt==1 && (s1[i]>='0' && s1[i]<='9')) {hour=s1[i]-'0';break;}
    }
    if(hour>=10) cout<<table[day-1]<<" "<<hour<<":";
    else std::cout <<table[day-1]<<" 0"<<hour<<":";
}
void getMinute(string s3,string s4){
    int len=min(s3.length(),s4.length());
    int minute;
    int index;
    for (int i = 0; i < len; i++)
    {
        if(s3[i]==s4[i] && (s3[i]<='Z' && s3[i]>='A')) {index=i;break;}
        if(s3[i]==s4[i] && (s3[i]<='z' && s3[i]>='a')) {index=i;break;}
    }
    if(index<10) cout<<"0"<<index;
    else cout<<index;
}

int main(int argc, char const *argv[])
{
    string s1,s2,s3,s4;
    cin>>s1>>s2>>s3>>s4;
    getDayHour(s1,s2);
    getMinute(s3,s4);

    return 0;
}
