#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int matrix[1001][1001];
void init(){
    for (int i = 1; i <= 1000; i++)
        for (int j = 1; j <= 1000; j++)
            matrix[i][j]=0;
}
void setZero(int x){
    for (int i = 1; i <= 1000; i++){
        matrix[x][i]=0;
        matrix[i][x]=0;
    }
}
void setOne(int x){
    for (int i = 1; i <= 1000; i++){
        matrix[x][i]=1;
        matrix[i][x]=1;
    }
}
int getGroups(int ele[],int n,int x){

}

int main(int argc, char const *argv[])
{
    int n,m,k,start,end,pos;
    init();
    cin>>n>>m>>k;
    int ele[k];
    for (int i = 0; i < m; i++)
    {
        cin>>start>>end;
        matrix[start][end]=1;
    }
    for (int i = 0; i < k; i++)
        cin>>ele[k];
    for (int i = 0; i < k; i++)
    {
        setZero(ele[i]);
        int n=getGroups(ele,k);
        setOne(ele[i]);
        std::cout << n << std::endl;
    }
    return 0;
}
