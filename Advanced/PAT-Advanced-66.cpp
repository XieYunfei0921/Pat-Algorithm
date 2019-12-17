#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
/*
    OJ上有两个WA
*/
int toInt(string s){
    return (s[0]-'0')*10+(s[1]-'0');
}
string toString(int x){
    string s="";
    if(x>=10)
        s+=x/10+'0';
    s+=x%10+'0';
    return s;
}
struct Node{
    int id;
    vector<int> sons;
    int val;
};
int n,m,target,k,temp;
string start,finish;
bool isLeaf[100];
int father[100];
Node w[100];
vector<int> leafs;
void DFS(int root,int target){
    if(target<0) return;
    if(isLeaf[root]==true && target==w[root].val)
        leafs.push_back(root);
    for (int i = 0; i < w[root].sons.size(); i++)
        DFS(w[root].sons[i],target-w[root].val);
}
string getPath(int leaf){
    if(leaf==0){
        string s=toString(w[0].val);
        reverse(s.begin(),s.end());
        return s;
    } 
    string s1=toString(w[leaf].val);
    reverse(s1.begin(),s1.end());
    return s1+" "+getPath(father[leaf]);
}

int main(int argc, char const *argv[])
{
    cin>>n>>m>>target;
    fill(isLeaf,isLeaf+100,true);
    for (int i = 0; i < n; i++){
        cin>>temp;
        w[i].id=i;
        w[i].val=temp;
    }
    if(target<w[0].val) return 0;
    for (int i = 0; i < m; i++){
        cin>>start>>k;
        for (int j = 0; j < k; j++){
            cin>>finish;
            // 建立依赖关系
            isLeaf[toInt(start)]=false;
            w[toInt(start)].sons.push_back(toInt(finish));
            father[toInt(finish)]=toInt(start);
        }
    }
    // 建立一棵树 算的是根节点到叶子节点距离
    int root=0;
    DFS(root,target);
    string st;
    priority_queue<string> ps;
    for (int i = 0; i < leafs.size(); i++){
        st=getPath(leafs[i]);
        reverse(st.begin(),st.end());
        ps.push(st);
    }
    while (!ps.empty()){
        std::cout << ps.top() << "\n";
        ps.pop();
    }
    return 0;
}
