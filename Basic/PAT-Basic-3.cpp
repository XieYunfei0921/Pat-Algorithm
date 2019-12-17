#include <cstdio>
#include <cstring>
using namespace std;

int getP(long long x,int target){
    int cnt=0;
    int res=0;
    while (x!=0)
    {
        if(x%10==target){
            cnt++;
        }
        x/=10;
    }
    while (cnt>0)
    {
        res=res*10+target;
        cnt--;
    }
    return res;
}

int main(int argc, char const *argv[])
{
    long long A,B;
    int da,db;
    scanf("%lld%d%lld%d",&A,&da,&B,&db);
    printf("%d",getP(A,da)+getP(B,db));
    return 0;
}
