#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Node{
    string name;
    string kaishi;
    string jieshu;
};
bool cmp(Node n1,Node n2){
    return n1.kaishi<n2.kaishi;
}
bool cmp2(Node n1,Node n2){
    return n1.jieshu>n2.jieshu;
}
int main(int argc, char const *argv[])
{
    int m;
    vector<Node> v;
    string s,start,finish;
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        cin>>s>>start>>finish;
        v.push_back(Node{s,start,finish});
    }
    sort(v.begin(),v.end(),cmp);
    cout<<v[0].name<<" ";
    sort(v.begin(),v.end(),cmp2);
    std::cout << v[0].name << std::endl;
    return 0;
}
