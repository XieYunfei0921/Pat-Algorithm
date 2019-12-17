#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,m,sc;
    cin>>n>>m;
    int value[m],correct[m],sum[n];
    fill(sum,sum+n,0);
    for (int i = 0; i < m; i++)
        cin>>value[i];
    for (int i = 0; i < m; i++)
        cin>>correct[i];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            int x;
            cin>>x;
            sc=x;
            if(sc==correct[j]) 
                sum[i]+=value[j];
        }
    }
    for (int i = 0; i < n; i++)
        std::cout << sum[i] << std::endl;
    return 0;
}
