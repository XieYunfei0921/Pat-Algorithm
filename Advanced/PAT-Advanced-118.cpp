#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
/*
    测试点2 TLE
*/
struct Node{
    string name;
    int age;
    int worth;
    void show(){
        cout<<this->name<<" "<<this->age<<" "<<this->worth<<"\n";
    }
};
bool cmp(Node n1,Node n2){
    if(n1.worth==n2.worth && n1.age==n2.age) return n1.name<n2.name;
    if(n1.worth==n2.worth) return n1.age<n2.age;
    return n1.worth>n2.worth;
}
vector<Node> temp,v;
int main(int argc, char const *argv[]){
    int n,k,m,age,worth,low,upper;string id;
    cin>>n>>k;
    for (int i = 0; i < n; i++){
        cin>>id>>age>>worth;
        v.push_back(Node{id,age,worth});
    }
    int cnt=1;
    for (int i = 0; i < k; i++){
        cin>>m>>low>>upper;
        for (int jj = 0; jj < v.size(); jj++)
            if(v[jj].age<=upper && v[jj].age>=low) temp.push_back(v[jj]);
        sort(temp.begin(),temp.end(),cmp);
        cout<<"Case #"<<cnt<<":\n";
        cnt++;
        if(temp.size()==0) 
            cout<<"None\n";
        else{
            for (int i = 0; i < temp.size() && i<m; i++)
                temp[i].show();
            temp.clear();
        }
    }
    return 0;
}
