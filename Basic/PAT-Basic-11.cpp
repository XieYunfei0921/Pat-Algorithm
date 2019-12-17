#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

string change(int val,int upper,int lower,int target){
    string s="000";
    int x;
    if(val<=upper &&val>=lower)
        x=target;
    else
        x=val;
    s[0]=x/100+'0';
    s[1]=x%100/10+'0';
    s[2]=x%10+'0';
    return s;
}

int main(int argc, char const *argv[])
{
    int m,n,lower,upper,target,sc;
    cin>>m>>n>>lower>>upper>>target;
    string val[m][n];
    for (int i = 0; i < m; i++)
    {   
        for (int j = 0; j < n; j++)
        {
            int x;
            cin>>x;
            sc=x;
            val[i][j]=change(sc,upper,lower,target);
        }
    }
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(j==n-1)
                cout<<val[i][j]<<"\n";
            else
                cout<<val[i][j]<<" ";
        }
    }
    return 0;
}
