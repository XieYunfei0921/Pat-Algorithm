#include <iostream>
#include <cstdio>
using namespace std;
int nextval[100000]={0};
bool vis[100000]={false};
int toInt(string s){
    if(s=="-1") return -1;
    int num=0;
    for (int i = 0; i < s.length(); i++)
        num=num*10+s[i]-'0';
    return num;
}
int main(int argc, char const *argv[]){
    string st1,st2,x1,x2;int n;string c;
    cin>>st1>>st2>>n;
    int ans=-1;
    for (int i = 0; i < n; i++){
        cin>>x1>>c>>x2;
        nextval[toInt(x1)]=toInt(x2);
    }
    int sst1=toInt(st1),sst2=toInt(st2);
    while (sst1!=-1){
        vis[sst1]=true;
        sst1=nextval[sst1];
    }
    while (sst2!=-1){
        if(vis[sst2]==true) {ans=sst2;break;}
        vis[sst2]=true;
        sst2=nextval[sst2];
    }
    if(ans==-1) printf("-1");
    else printf("%05d",ans);
    return 0;
}
