#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
#include <stdio.h>
using namespace std;
/*
    离线计算
    试着去降低数据分布的时间复杂度这里很糟糕的达到了n^3
*/
const int MAXN=88000;
struct Node{
    string id;
    int from;
    int to;
};
bool cmp2(Node n1,Node n2){
    return (n1.to-n1.from)>(n2.to-n2.from);
}
struct Info{
    string id;
    int t;
    string sign;
};
bool cmp(Info i1,Info i2){
    return i1.t<i2.t;
}
map<string,vector<Node> > mp; 
int stamp[MAXN]={0};
int toInt(string st){
    int h=(st[0]-'0')*10+(st[1]-'0');
    int m=(st[3]-'0')*10+(st[4]-'0');
    int s=(st[6]-'0')*10+(st[7]-'0');
    return h*3600+m*60+s;
}
int main(int argc, char const *argv[]){
    int n,k;string s,t,sign;
    scanf("%d %d",&n,&k);
    vector<Info> vs;
    for (int i = 0; i < n; i++){
        cin>>s>>t>>sign;
        vs.push_back(Info{s,toInt(t),sign});
    }
    sort(vs.begin(),vs.end(),cmp);
    for (int i = 0; i < vs.size(); i++){
        string stemp=vs[i].id;int tt=vs[i].t;
        if(vs[i].sign=="in"){
            if(mp.count(stemp)==0 || (mp.count(stemp)!=0 && mp[stemp][mp[stemp].size()-1].to!=MAXN))
                mp[stemp].push_back(Node{stemp,tt,MAXN});
            else if((mp.count(stemp)!=0 && mp[stemp][mp[stemp].size()-1].to==MAXN))
                mp[stemp][mp[stemp].size()-1].from=tt;
        }
        if(vs[i].sign=="out"){
            if(mp.count(stemp)!=0 && mp[stemp][mp[stemp].size()-1].to==MAXN)
                mp[stemp][mp[stemp].size()-1].to=tt;
        }
    }
    // 形成分布列表
    map<int,vector<string>,greater<int> > ans;
    for (map<string,vector<Node> >::iterator i = mp.begin(); i != mp.end(); i++){
        if(i->second[i->second.size()-1].to==MAXN)
            i->second.pop_back();
        int cnt=0;
        for (int j = 0; j < i->second.size(); j++){
            cnt+=i->second[j].to-i->second[j].from;
            for (int g = i->second[j].from; g < i->second[j].to; g++)
                stamp[g]++;
        }
        ans[cnt].push_back(i->first);
    }
    for (int i = 0; i < k; i++){
        cin>>t;
        int x=toInt(t);
        printf("%d\n",stamp[x]);
    }
    int tes=ans.begin()->first;
    for (int i = 0; i < ans.begin()->second.size(); i++){
        if(i!=0) printf(" ");
        cout<<ans.begin()->second[i];
    }
    printf(" %02d:%02d:%02d\n",tes/3600,tes%3600/60,tes%60);
    return 0;
}
