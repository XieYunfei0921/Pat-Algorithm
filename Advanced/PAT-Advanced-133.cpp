#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
string toLow(string s){
    for (int i = 0; i < s.length(); i++){
        if(s[i]<='Z' && s[i]>='A') s[i]=s[i]-'A'+'a';
    }
    return s;
}
struct Node{
    string s;
    int sc;
    int num;
};
bool cmp(Node n1,Node n2){
    if(n1.sc==n2.sc && n1.num==n2.num) return n1.s<n2.s;
    if(n1.sc==n2.sc) return n1.num<n2.num;
    return n1.sc>n2.sc;
}
map<string,float> mp;
map<string,int> cnt;
vector<Node> v;
int main(int argc, char const *argv[]){
    int n;
    string id,code;int sc;
    float val;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>id>>sc>>code;
        if(id[0]=='B') val=sc/1.5;
        else if(id[0]=='A') val=sc;
        else if(id[0]=='T') val=sc*1.5;
        if(mp.count(toLow(code))==0) {
            mp[toLow(code)]=val;
            cnt[toLow(code)]=1;
        }else {
            mp[toLow(code)]+=val;
            cnt[toLow(code)]++;
        }
    }
    for (map<string,float>::iterator i = mp.begin(); i != mp.end(); i++)
        v.push_back(Node{i->first,(int)i->second,cnt[i->first]});
    sort(v.begin(),v.end(),cmp);
    cout<<v.size()<<"\n";
    cout<<1<<" "<<v[0].s<<" "<<v[0].sc<<" "<<v[0].num<<"\n";
    int cntx=2,cur=1;
    for (int i = 1; i < v.size(); i++){
        if(v[i].sc==v[i-1].sc){
            cout<<cur<<" "<<v[i].s<<" "<<(int)v[i].sc<<" "<<v[i].num<<"\n";
        } else{
            cout<<cntx<<" "<<v[i].s<<" "<<(int)v[i].sc<<" "<<v[i].num<<"\n";
            cur=cntx;
        }
        cntx++;
    }
    return 0;
}
