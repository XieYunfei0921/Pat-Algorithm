#include <cstdio>
#include <math.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    scanf("%d",&n);
    int maxn=0;
    for (int i = 0; i < n; i++)
    {
        int a,b;
        scanf("%d %d",&a,&b);
        if(a*a+b*b>maxn)
            maxn=a*a+b*b;
    }
    printf("%.2f",sqrt(maxn));
    return 0;
}
