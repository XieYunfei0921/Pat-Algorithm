#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
/*
    考虑不全面
    考虑n1<n2的两个日期
    TODO 通过从n1加到n2的方式来计算话费
*/
struct Node{
    string name;
    int mon;int day;int h;int m;
    string sta;
    void show(){
        cout<<name<<" "<<mon<<":"<<day<<":"<<h<<":"<<m<<" "<<sta<<"\n";
    }
};
int charge[24];
bool cmp(Node n1,Node n2){
    if(n1.name==n2.name && n1.mon==n2.mon && n1.day==n2.day && n1.h==n2.h) return n1.m<n2.m;
    if(n1.name==n2.name && n1.mon==n2.mon && n1.day==n2.day) return n1.h<n2.h;
    if(n1.name==n2.name && n1.mon==n2.mon) return n1.day<n2.day;
    if(n1.name==n2.name) return n1.mon<n2.mon;
    return n1.name<n2.name;
}
struct Result{
    double val;
    int minutes;
    void show(){
        printf("%d $%.2f\n",this->minutes,this->val);
    }
};
map<string,double> mp;
vector<Node> v;
Result caculate(Node n1,Node n2){
    // 计算时差 不考虑跨日期
    int h1,h2,minutes=0,basem=0;
    int cost=0;
    int temp=0;
    bool flag=false;
    double res;
    int base=n2.day-n1.day;
    if(base!=0){
        for (int i = 0; i < 24; i++)
            temp+=60*charge[i];
        basem=base*24*60;
        base=base*temp;
    }
    if(n1.h>n2.h){
        swap(n1,n2);
        flag=true;
    }
    if(n1.m==0)
        h1=n1.h;
    else    
        h1=n1.h+1;
    h2=n2.h;
    for (int i = h1; i < h2; i++){
        cost+=60*charge[i];
        minutes+=60;
    }
    cost+=n2.m*charge[h2];
    minutes+=n2.m;
    cost+=(60-n1.m)*charge[h1-1];
    minutes+=(60-n1.m);
    if(flag){
        minutes=basem-minutes;
        cost=base-cost;
    }
    else{
        minutes=basem+minutes;
        cost+=base;
    }
    res=(double)cost/100;
    return Result{res,minutes};
}
int main(int argc, char const *argv[])
{
    string id,sta;
    int mon,day,h,m;
    for (int i = 0; i < 24; i++)
        scanf("%d",&charge[i]);
    int n;
    scanf("%d",&n);
    for (int i = 0; i < n; i++){
        cin>>id;
        scanf("%02d:%02d:%02d:%02d",&mon,&day,&h,&m);
        cin>>sta;
        v.push_back(Node{id,mon,day,h,m,sta});
    }
    sort(v.begin(),v.end(),cmp);
    for (int i = 0; i < v.size()-1; i++){
        if((i!=0 && v[i-1].name!=v[i].name) || i==0){
            cout<<v[i].name;
            printf(" %02d\n",v[i].mon);
        }
        if(v[i].name==v[i+1].name && v[i].sta=="on-line" && v[i+1].sta=="off-line" && v[i].mon){
            printf("%02d:%02d:%02d %02d:%02d:%02d ",v[i].day,v[i].h,v[i].m,v[i+1].day,v[i+1].h,v[i+1].m);
            Result res=caculate(v[i],v[i+1]);
            res.show();
            mp[v[i].name]+=res.val;
        }
        if((v[i].name!=v[i+1].name || i==v.size()-2)){
            printf("Total amount: $%.2f\n",mp[v[i].name]);
        }
    }
    return 0;
}
