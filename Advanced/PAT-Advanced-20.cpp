#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,m,start,finish;
    cin>>n;
    int dis[n],sum[n+1],total=0;
    for (int i = 0; i < n; i++){
        cin>>dis[i];
        total+=dis[i];
    }
    sum[0]=0;
    for (int i = 0; i < n; i++)
        sum[i+1]=sum[i]+dis[i];
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        cin>>start>>finish;
        int part=sum[max(start,finish)-1]-sum[min(start,finish)-1];
        std::cout <<min(part,total-part)  << std::endl;
    }
    return 0;
}
