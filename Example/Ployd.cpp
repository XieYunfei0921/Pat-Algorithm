#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;
const int MAXV=200;
const int INF=999999;
int dis[MAXV][MAXV];

/*
    多源最短路径求法
    对于任意一点k,使之成为中介点,
    枚举另外两点i,j由于k的存在使得路径缩短
*/
void floyd(int n){
    for (int k = 0; k < n; k++)
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if(dis[i][k]!=INF && dis[j][k]!=INF && dis[i][k]+dis[j][k]<dis[i][j])
                    dis[i][j]=dis[i][k]+dis[j][k]<dis[i][j];
            }
            
        }
        
    }
    
}

int main(int argc, char const *argv[])
{
    
    return 0;
}
