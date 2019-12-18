#include <iostream>
#include <set>
using namespace std;
const int MAXN=26*26*26*10+10;
set<int> mp[MAXN];
int getId(string s){
    return ((s[0]-'A')*26*26+(s[1]-'A')*26+(s[2]-'A'))*10+s[3]-'0';
}
int main(int argc, char const *argv[]){
    int n,k,id,nums;string name,que;
    cin>>n>>k;
    for (int i = 1; i <= k; i++){
        cin>>id>>nums;
        for (int i = 0; i < nums; i++){
            cin>>name;
            mp[getId(name)].insert(id);
        }
    }
    for (int i = 0; i < n; i++){
        cin>>que;
        set<int> s=mp[getId(que)];
        if(s.size()==0)
            cout<<que<<" "<<0<<"\n";
        else{
            cout<<que<<" "<<s.size();
            for (set<int>::iterator i = s.begin(); i != s.end(); i++)
                cout<<" "<<*i;
            cout<<"\n";
        }
    }
    return 0;
}
