#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student{
    string id;
    int de;
    int cai;
    void show(){
        std::cout << this->id<<" "<<this->de<<" "<<this->cai << std::endl;
    }
}s1;
bool cmp(Student s1,Student s2){
    if((s1.de+s1.cai)==(s2.de+s2.cai) && s1.de==s2.de) return s1.id<s2.id;
    if((s1.de+s1.cai)==(s2.de+s2.cai) && s1.de!=s2.de) return s1.de>s2.de;
    return (s1.de+s1.cai)>(s2.de+s2.cai);
}

int main(int argc, char const *argv[])
{
    int n,lower,higher;
    cin>>n>>lower>>higher;
    string s;int de,cai;
    vector<Student> v1;
    vector<Student> v2;
    vector<Student> v3;
    vector<Student> v4;
    for (int i = 0; i < n; i++)
    {
        cin>>s>>de>>cai;
        s1={s,de,cai};
        if(de<lower || cai<lower){continue;}
        if(de>=higher && cai>=higher){v1.push_back(s1);continue;}
        if(de>=higher && cai<higher && cai>=lower){v2.push_back(s1);continue;}
        if(de<higher && de>=lower && cai<higher && cai>=lower && de>=cai){v3.push_back(s1);continue;}
        else{v4.push_back(s1);continue;}
    }
    sort(v1.begin(),v1.end(),cmp);
    sort(v2.begin(),v2.end(),cmp);
    sort(v3.begin(),v3.end(),cmp);
    sort(v4.begin(),v4.end(),cmp);
    std::cout << v1.size()+v2.size()+v3.size()+v4.size() << std::endl;
    for (int i = 0; i < v1.size(); i++)
        v1[i].show();
    for (int i = 0; i < v2.size(); i++)
        v2[i].show();
    for (int i = 0; i < v3.size(); i++)
        v3[i].show();
    for (int i = 0; i < v4.size(); i++)
        v4[i].show();
    return 0;
}
