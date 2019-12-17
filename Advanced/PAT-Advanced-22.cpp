#include <iostream>
#include <algorithm>
#include <map>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,m,point,cnt=0;
    cin>>n>>m;
    map<int,int> imap;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin>>point;
            if(imap.count(point)==0)
                imap[point]=1;
            else
                imap[point]++;
            cnt++;
        }
    }
    int maxn=0,color=0;
    for (map<int,int>::iterator i = imap.begin(); i != imap.end(); i++)
    {
        if(i->second>maxn){
            maxn=i->second;
            color=i->first;
        }
    }
    if(2*maxn>=cnt){
        cout<<color;
    }
    return 0;
}
