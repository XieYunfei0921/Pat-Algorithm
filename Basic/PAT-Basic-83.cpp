#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
/*
    时间复杂度太高
    代码太长
*/
struct Node{
    string id;
    int score;
    string getLevel(){
        return this->id.substr(0,1);
    }
    string getSpaceId(){
        return this->id.substr(1,3);
    }
    string getDate(){
        return this->id.substr(4,6);
    }
    string getId(){
        return this->id.substr(10,3);
    }
    void show(){
        std::cout <<this->id<<" "<<this->score  << std::endl;
    }
};
struct Space{
    string sid;
    int cnt;
    void show(){
        std::cout << this->sid<<" "<<this->cnt << std::endl;
    }
};
bool cmp(Node n1,Node n2){
    if(n1.score==n2.score) return n1.id<n2.id;
    return n1.score>n2.score;
}
bool cmpSpace(Space s1,Space s2){
    if(s1.cnt==s2.cnt) return s1.sid<s2.sid;
    return s1.cnt>s2.cnt;
}
Node nodes[10001];
void functionOne(string order,int n,int num){
    vector<Node> v;
    for (int i = 0; i < n; i++)
    {
        if(nodes[i].getLevel()==order){
            v.push_back(nodes[i]);
        }
    }
    sort(v.begin(),v.end(),cmp);
    if(v.size()==0) {std::cout << "NA" << std::endl;return;}
    std::cout << "Case "<<num<<": 1 "<<order << std::endl;
    for (int i = 0; i < v.size(); i++)
        v[i].show();
}
void functionTwo(string order,int n,int num){
    int cnt=0,sum=0;
    for (int i = 0; i < n; i++)
    {
        if(nodes[i].getSpaceId()==order){
            cnt++;
            sum+=nodes[i].score;
        }
    }
    std::cout << "Case "<<num<<": 2 "<<order << std::endl;
    if(cnt==0 && sum==0){std::cout << "NA" << std::endl;return;}
    std::cout << cnt<<" "<<sum << std::endl;
}
void functionThree(string order,int n,int num){
    vector<Space> v;
    map<string,int> smap;
    for (int i = 0; i < n; i++)
    {
        if(nodes[i].getDate()==order){
            if(smap.count(nodes[i].getSpaceId())==0)
                smap[nodes[i].getSpaceId()]=1;
            else
                smap[nodes[i].getSpaceId()]++;
        }
    }
    std::cout << "Case "<<num<<": 3 "<<order << std::endl;
    if(smap.size()==0){std::cout << "NA" << std::endl;return;}
    for (map<string,int>::iterator i = smap.begin(); i != smap.end(); i++)
    {
        Space s={i->first,i->second};
        v.push_back(s);
    }
    sort(v.begin(),v.end(),cmpSpace);
    for (int i = 0; i < v.size(); i++)
        v[i].show();
}

void function(int type,string order,int n,int num){
    switch (type)
    {
        case 1:functionOne(order,n,num);break;
        case 2:functionTwo(order,n,num);break;
        case 3:functionThree(order,n,num);break;
    }
}

int main(int argc, char const *argv[])
{
    int n,m;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        string id;int score;
        cin>>id>>score;
        nodes[i]={id,score};
    }
    int num=1;
    for (int i = 0; i < m; i++)
    {
        int type;string order;
        cin>>type>>order;
        function(type,order,n,num);
        num++;
    }
    return 0;
}
