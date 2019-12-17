#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
struct Node{
    string id;
    int high;
    friend bool operator< (Node n1, Node n2)
    {
        return n1.high < n2.high;
    }
};
void printLine(vector<Node> nodes){
    int num=nodes.size();
    Node ans[num];
    for (int i = 0; i < num/2; i++)
        ans[i]=nodes[num-2*(i+1)];
    for (int i =num-1; i >= num/2; i--)
        ans[i]=nodes[2*i-num+1];
    for (int i = num-1; i >=0; i--)
    {   
        if(i!=0) cout<<ans[i].id<<" ";
        else cout<<ans[i].id<<"\n";
    }
}
int main(int argc, char const *argv[])
{
    int n,k;
    cin>>n>>k;
    vector<Node> v;
    priority_queue<Node> qs;
    for (int i = 0; i < n; i++)
    {
        string id;int high;
        cin>>id>>high;
        qs.push(Node{id,high});
    }
    int first=n/k+n%k;
    int avg=n/k;
    int cnt=0;
    while (cnt<first)
    {
        v.push_back(qs.top());
        qs.pop();
        cnt++;
    }
    printLine(v);
    v.clear();
    while (!qs.empty())
    {
        cnt=0;
        while (cnt<avg)
        {
            v.push_back(qs.top());
            qs.pop();
            cnt++;
        }
        printLine(v);
        v.clear();
    }
    

    return 0;
}
