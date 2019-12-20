#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
// small man理解出入
struct Node{
    string id;
    int de;
    int cai;
    void show(){cout<<this->id<<" "<<this->de<<" "<<this->cai<<"\n";}
};
bool cmp(Node a,Node b){
    if ((a.de + a.cai) != (b.de + b.cai))
        return (a.de + a.cai) > (b.de + b.cai);
    else if (a.de != b.de)
        return a.de > b.de;
    else
        return a.id < b.id;
}
int main(int argc, char const *argv[]){
    int n,low,up,de,cai;
    string id;
    cin>>n>>low>>up;
    vector<Node> sages;
    vector<Node> nobleman;
    vector<Node> fool;
    vector<Node> small;
    for (int i = 0; i < n; i++){
        cin>>id>>de>>cai;
        if(de<low || cai<low) continue;
        if(de>=up && cai>=up)
            sages.push_back(Node{id,de,cai});
        else if(cai<up && de>=up)
            nobleman.push_back(Node{id,de,cai});
        else if(cai<up && de<up && cai>=de)
            fool.push_back(Node{id,de,cai});
        else
            small.push_back(Node{id,de,cai});
    }
    sort(sages.begin(),sages.end(),cmp);
    sort(nobleman.begin(),nobleman.end(),cmp);
    sort(fool.begin(),fool.end(),cmp);
    sort(small.begin(),small.end(),cmp);
    cout<<sages.size()+nobleman.size()+fool.size()+small.size()<<"\n";
    for (int i = 0; i < sages.size(); i++)
        sages[i].show();
    for (int i = 0; i < nobleman.size(); i++)
        nobleman[i].show();
    for (int i = 0; i < fool.size(); i++)
        fool[i].show(); 
    for (int i = 0; i < small.size(); i++)
        small[i].show();
    return 0;
}
