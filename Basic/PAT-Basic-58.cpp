#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int m,n,TOL;
    cin>>m>>n>>TOL;
    int table[n][m];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
            cin>>table[i][j];
    }
    int row=-1,col=-1,val=0;
    for (int i = 1; i < n-1; i++)
    {
        for (int j = 1; j < m-1; j++)
        {
            if(table[i][j]-table[i][j-1]>TOL && table[i][j]-table[i][j+1]>=TOL && 
               table[i][j]-table[i-1][j-1]>=TOL && table[i][j]-table[i-1][j+1]>=TOL && 
               table[i][j]-table[i-1][j]>=TOL && table[i][j]-table[i+1][j-1]>=TOL && 
               table[i][j]-table[i+1][j+1]>=TOL && table[i][j]-table[i+1][j]>=TOL)
            {
                if(row!=-1 || col!=-1){cout<<"Not Unique\n";return 0;}
                row=j;col=i;val=table[i][j];
            }
        }
    }
    if(row==-1) std::cout << "Not Exist" << std::endl; 
    else std::cout <<"("<< row+1<<", "<<col+1<<"): "<<val << std::endl;   
    return 0;
}
