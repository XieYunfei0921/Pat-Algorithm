#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
/*
考虑其他情况
    排名的处理
*/
struct Node{
    string id;
    int num;
    int rank;
    bool flag;
};
bool cmp(Node n1,Node n2){
    return n1.num>n2.num;
}
void minNode(Node* n){
    string s=n->id;
    int num=n->num;
    int MIN=999999;
    int index=-1;
    for (int i = 0; i < 4; i++)
    {
        if((n+i)->flag==false && (n+i)->rank<MIN ){
            MIN=(n+i)->rank;
            index=i;
        }
    }
    char c;
    if(index==0) c='A';
    else if(index==1) c='C';
    else if(index==2) c='M';
    else c='E';
    std::cout << MIN<<" "<<c << std::endl;
}
int main(int argc, char const *argv[])
{
    int n,m,c,k,e,a;
    string s;
    vector<Node> v1,v2,v3,v4;
    Node temp;
    cin>>n>>m;
    for (int i = 0; i < n; i++)
    {
        cin>>s>>c>>k>>e;
        a=(c+k+e)/3;
        v1.push_back(Node{s,c,0,false});
        v2.push_back(Node{s,k,0,false});
        v3.push_back(Node{s,e,0,false});
        v4.push_back(Node{s,a,0,false});
    }
    sort(v1.begin(),v1.end(),cmp);
    sort(v2.begin(),v2.end(),cmp);
    sort(v3.begin(),v3.end(),cmp);
    sort(v4.begin(),v4.end(),cmp);
    v1[0].rank=1;
    v2[0].rank=1;
    v3[0].rank=1;
    v4[0].rank=1;
    for (int i = 1; i < v1.size(); i++){
        if(v1[i].num==v1[i-1].num) {v1[i].rank=v1[i-1].rank;v1[i].flag=true;v1[i-1].flag=true;}
        else v1[i].rank=v1[i-1].rank+1;
    }
    for (int i = 1; i < v2.size(); i++){
        if(v2[i].num==v2[i-1].num) {v2[i].rank=v2[i-1].rank;v2[i].flag=true;v2[i-1].flag=true;}
        else v2[i].rank=v2[i-1].rank+1;
    }
    for (int i = 1; i < v3.size(); i++){
        if(v3[i].num==v3[i-1].num) {v3[i].rank=v3[i-1].rank;v3[i].flag=true;v3[i-1].flag=true;}
        else v3[i].rank=v3[i-1].rank+1;
    }
    for (int i = 1; i < v4.size(); i++){
        if(v4[i].num==v4[i-1].num) {v4[i].rank=v4[i-1].rank;v4[i].flag=true;v4[i-1].flag=true;}
        else v4[i].rank=v4[i-1].rank+1;
    }
    Node n1,n2,n3,n4;
    Node nodes[4];
    for (int j = 0; j < m; j++){
        cin>>s;
        bool flag=true;
        for (int i = 0; i < v1.size(); i++)
            if(v1[i].id==s) {n1=v1[i];flag=false;break;}
        for (int i = 0; i < v2.size(); i++)
            if(v2[i].id==s) {n2=v2[i];flag=false;break;}
        for (int i = 0; i < v3.size(); i++)
            if(v3[i].id==s) {n3=v3[i];flag=false;break;}
        for (int i = 0; i < v4.size(); i++)
            if(v4[i].id==s) {n4=v4[i];flag=false;break;}
        if(flag) {
            std::cout << "N/A" << std::endl;
            continue;
        }
        nodes[0]=n4;nodes[1]=n1;nodes[2]=n2;nodes[3]=n3;
        minNode(nodes);
    }
    return 0;
}
