#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
struct Node{
    string id;
    int biancheng,midterm,final,mixed;
    void caculate(){
        if(this->midterm>this->final) this->mixed=(int)(0.4*(double)this->midterm+0.6*(double)this->final+0.5);
        else this->mixed=this->final;
    }
    void show(){
        this->biancheng=this->biancheng==0?-1:this->biancheng;
        this->midterm=this->midterm==0?-1:this->midterm;
        this->final=this->final==0?-1:this->final;
        std::cout << this->id<<" "<<this->biancheng<<" "<<this->midterm<<" "<<this->final<<" "<<this->mixed << std::endl;
    }
};
bool cmp(Node n1,Node n2){
    if(n1.mixed==n2.mixed) return n1.id<n2.id;
    return n1.mixed>n2.mixed;
}
map<string,Node> smap;
int main(int argc, char const *argv[])
{
    int p,m,n;
    string id;int score;
    cin>>p>>m>>n;
    for (int i = 0; i < p; i++)
    {
        cin>>id>>score;
        if(score<200) continue;
        smap[id]=Node{id,score,0,0,0};
    }
    for (int i = 0; i < m; i++)
    {
        cin>>id>>score;
        if(smap.count(id)!=0)
            smap[id].midterm=score;
    }
    for (int i = 0; i < n; i++)
    {
        cin>>id>>score;
        if(smap.count(id)!=0)
            smap[id].final=score;
    }
    vector<Node> v;
    for (map<string,Node>::iterator i = smap.begin(); i != smap.end(); i++)
    {
        i->second.caculate();
        if(i->second.mixed>=60)
            v.push_back(i->second);
    }
    sort(v.begin(),v.end(),cmp);
    for (int i = 0; i < v.size(); i++)
        v[i].show();
    return 0;
}
