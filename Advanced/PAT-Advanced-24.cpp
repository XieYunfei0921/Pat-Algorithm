#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
/*
    坑点: 注意两个过大的数相加,加的结果可能结果超出限制,导致截取的情况发送
    正数: [-maxn -->0)
    负数: [0,maxn]
*/
int main(int argc, char const *argv[])
{
    int n;long long a,b,c;
    long long temp;
    scanf("%d",&n);
    for (int i = 0; i < n; i++)
    {
        scanf("%lld %lld %lld",&a,&b,&c);
        temp=a+b;
        if(a>0 && b>0 && temp<0) {printf("Case #%d: true\n",i+1);continue;}
        if(a<0 && b<0 && temp>=0) {printf("Case #%d: false\n",i+1);continue;}
        if(temp>c) printf("Case #%d: true\n",i+1);
        else printf("Case #%d: false\n",i+1);continue;
    }
    return 0;
}
