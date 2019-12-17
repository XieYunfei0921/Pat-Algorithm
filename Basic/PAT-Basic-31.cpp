#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;
struct Born{
    string name;
    string year;
    string month;
    string day;
};
bool cmp(Born b1,Born b2){
    if(b1.year.compare(b2.year)==0 && b1.month.compare(b2.month)==0) return b1.day.compare(b2.day)>0;
    else if(b1.year.compare(b2.year)==0) return b1.month.compare(b2.month)>0;
    else return b1.year.compare(b2.year)>0;
}
bool isLegal(Born b1){
    Born b={"","2014","09","06"};
    Born b2={"","1814","09","05"};
    if(cmp(b,b1)==true && cmp(b1,b2)==true) return true; 
    return false;
}
const int MAXN=100001;
Born table[MAXN];

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    string name,info;
    int cnt=0;
    for (int i = 0; i < n; i++)
    {
        cin>>name>>info;
        Born b={name,info.substr(0,4),info.substr(5,2),info.substr(8,2)};
        if(isLegal(b)) {table[cnt]=b;cnt++;}
    }
    sort(table,table+cnt,cmp);
    cout<<cnt<<" "<<table[cnt-1].name<<" "<<table[0].name;
    return 0;
}
