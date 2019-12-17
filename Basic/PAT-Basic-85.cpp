#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
struct Node{
    string name;
    double sum;
    int cnt;
};
bool cmp(Node n1,Node n2){
    if(n1.sum==n2.sum && n1.cnt==n2.cnt) return n1.name<n2.name;
    if(n1.sum==n2.sum) return n1.cnt<n2.cnt;
    return n1.sum>n2.sum;
}
map<string,Node> smap;
void toLowCase(string &s)
{   
    for (int i = 0; i < s.length(); i++)
    {
        if(s[i]<='Z' && s[i]>='A')
            s[i]=s[i]-'A'+'a';
    }
}
void update(string name,int score,string id){
    double num=0.0;
    if(id[0]=='B') num=(double)score/1.5;
    if(id[0]=='A') num=(double)score;
    if(id[0]=='T') num=1.5*(double)score;
    toLowCase(name);
    if(smap.count(name)==0){
        Node node={name,num,1};
        smap[name]=node;
    }
    else{
        smap.find(name)->second.sum+=num;
        smap.find(name)->second.cnt++;
    }
}
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        string id,name;int score;
        cin>>id>>score>>name;
        update(name,score,id);
    }
    vector<Node> v;
    for (map<string,Node>::iterator i = smap.begin(); i != smap.end(); i++)
        v.push_back(i->second);
    sort(v.begin(),v.end(),cmp);
    std::cout << v.size() << std::endl;
    int lastNum=1,realNum=1;
    std::cout << lastNum<<" "<<v[0].name<<" "<<(int)v[0].sum<<" "<<v[0].cnt << std::endl;
    for (int i = 1; i < v.size(); i++)
    {   
        realNum++;
        if((int)v[i].sum!=(int)v[i-1].sum){
            std::cout << realNum<<" "<<v[i].name<<" "<<(int)v[i].sum<<" "<<v[i].cnt << std::endl;
            lastNum=realNum;
        }
        else{
            std::cout << lastNum<<" "<<v[i].name<<" "<<(int)v[i].sum<<" "<<v[i].cnt << std::endl;
        }

    }
    return 0;
}
