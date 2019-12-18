#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
    string name;
    string id;
    int grade;
    void show(){
        cout<<this->name<<" "<<this->id<<"\n";
    }
};
vector<Node> male;
vector<Node> female;
bool cmp1(Node n1,Node n2){
    return n1.grade>n2.grade;
}
bool cmp2(Node n1,Node n2){
    return n1.grade<n2.grade;
}
int main(int argc, char const *argv[]){
    int n,grade;string name,id;char gender;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>name>>gender>>id>>grade;
        if(gender=='M')
            male.push_back(Node{name,id,grade});
        else
            female.push_back(Node{name,id,grade});
    }
    int m=0,f=0;
        if(female.size()==0){
        cout<<"Absent\n";
        f=-1;
    } else{
        sort(female.begin(),female.end(),cmp1);
        female[0].show();
        f=female[0].grade;
    }
    if(male.size()==0){
        cout<<"Absent\n";
        m=-1;
    } else{
        sort(male.begin(),male.end(),cmp2);
        male[0].show();
        m=male[0].grade;
    }
    if(m==-1 || f==-1)
        cout<<"NA\n";
    else
        cout<<f-m<<"\n";
    return 0;
}
