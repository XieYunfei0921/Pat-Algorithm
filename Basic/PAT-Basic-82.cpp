#include <algorithm>
#include <iostream>
#include <map>
#include <vector>
using namespace std;
// 使用并查集的思想设置对象数组 lover[]
int lover[100000];
int status[100000];
void init(){
    for (int i = 0; i <= 100000; i++){
        lover[i]=-1;
        status[i]=false;
    }
}
int toInt(string s){
    int num=0;
    for (int i = 0; i < s.length(); i++)
        num=10*num+s[i]-'0';
    return num;
}
int main(int argc, char const *argv[])
{
    init();
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        string sa,sb;
        cin>>sa>>sb;
        lover[toInt(sa)]=toInt(sb);
        lover[toInt(sb)]=toInt(sa);
    }
    int m;
    cin>>m;
    vector<string> v,ans; 
    for (int i = 0; i < m; i++)
    {
        string s;
        cin>>s;
        v.push_back(s);           
        status[toInt(s)]=true;
    }
    for (int i = 0; i < v.size(); i++)
    {   
        if(lover[toInt(v[i])]==-1) {ans.push_back(v[i]);}
        else if(lover[toInt(v[i])]!=-1 && status[lover[toInt(v[i])]]==false) {ans.push_back(v[i]);}
        else continue;
    }
    std::cout << ans.size() << std::endl;
    sort(ans.begin(),ans.end());
    for (int i = 0; i < ans.size(); i++)
    {
        if(i!=ans.size()-1) cout<<ans[i]<<" ";
        else cout<<ans[i];
    }
    return 0;
}
