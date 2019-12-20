#include <iostream>
#include <map>
using namespace std;
struct Node{
    string name;
    string id;
    void show(){
        cout<<this->name<<" "<<this->id<<"\n";
    }
};
map<int,Node> mp;
int main(int argc, char const *argv[]){
    int n,score,low,up;string name,id;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>name>>id>>score;
        mp[score]=Node{name,id};
    }
    bool flag=true;
    cin>>low>>up;
    for (int i = up; i >= low; i--){
        if(mp.count(i)!=0){
            mp[i].show();
            flag=false;
        }
    }
    if(flag)
        cout<<"NONE";
    return 0;
}
