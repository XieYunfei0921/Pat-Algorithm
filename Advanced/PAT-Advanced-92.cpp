#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Node{
    string id;
    string name;
    int grade;
    void show(){
        cout<<this->id<<" "<<this->name<<" "<<this->grade<<"\n";
    }
};
bool cmp1(Node n1,Node n2){
    return n1.id<n2.id;
}
bool cmp2(Node n1,Node n2){
    if(n1.name==n2.name) return n1.id<n2.id;
    return n1.name<n2.name;
}
bool cmp3(Node n1,Node n2){
    if(n1.grade==n2.grade) return n1.id<n2.id;
    return n1.grade<n2.grade;
}
vector<Node> v;
int main(int argc, char const *argv[]){
    int n,c,grade;
    string id,name;
    cin>>n>>c;
    for (int i = 0; i < n; i++){
        cin>>id>>name>>grade;
        v.push_back(Node{id,name,grade});
    }
    if(c==1)
        sort(v.begin(),v.end(),cmp1);
    if(c==2)
        sort(v.begin(),v.end(),cmp2);
    if(c==3)
        sort(v.begin(),v.end(),cmp3);
    for (int i = 0; i < v.size(); i++)
        v[i].show();
    return 0;
}
