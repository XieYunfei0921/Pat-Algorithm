#include <iostream>
#include <algorithm>
using namespace std;
int t[101]={0};
int main(int argc, char const *argv[])
{
    int n,score,k;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>score;
        t[score]+=1;
    }
    cin>>k;
    for (int i = 0; i < k; i++)
    {
        cin>>score;
        if(i!=k-1)
            cout<<t[score]<<" ";
        else
            cout<<t[score];
    }
    return 0;
}
