#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
int MINU=1000000001;int MAXN=0;
int main(int argc, char const *argv[])
{ 
    int n;
    cin>>n;
    int arr[n];
    bool status[n];
    priority_queue<int,vector<int>,greater<int> > q;
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    for (int i = 0; i < n; i++)
    {
        if(arr[i]>=MAXN) {status[i]=true;MAXN=arr[i];}
        else status[i]=false;
    }
    for (int i = n-1; i >=0; i--)
    {
        if(arr[i]<=MINU) {status[i]&=true;MINU=arr[i];}
        else status[i]&=false;
    }
    for (int i = 0; i < n; i++)
        if(status[i]==true) q.push(arr[i]);
    std::cout << q.size() << std::endl;
    while (!q.empty())
    {
        if(q.size()==1) cout<<q.top();
        else cout<<q.top()<<"*";
        q.pop();
    }
    return 0;
}
