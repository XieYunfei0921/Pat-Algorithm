#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(int argc, char const *argv[])
{
    int n,m;int cnt=0,sum=0,sa=0;
    cin>>n>>m;
    int stu[n][n];
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            cin>>stu[i][j];
    }
    int maxn=0,minu=m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if(j==0) {sa=stu[i][j];continue;}
            if(stu[i][j]<=m && stu[i][j]>=0){
                if(maxn<stu[i][j]) maxn=stu[i][j];
                if(minu>stu[i][j]) minu=stu[i][j];
                sum+=stu[i][j];
                cnt++;
            }
        }
        int x=round((double)((sum-maxn-minu)/(cnt-2)+sa)/2);
        std::cout << x << std::endl;
        sum=sa=0;
        maxn=cnt=0;
        minu=m;
    }
    
    
    return 0;
}
