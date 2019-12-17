#include <iostream>
#include <cstdio>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int a1,a2,b1,b2,c1,c2;
    int sign=0;
    scanf("%d.%d.%d",&a1,&b1,&c1);
    scanf("%d.%d.%d",&a2,&b2,&c2);
    int c=c1+c2>=29?c1+c2-29:c1+c2;
    sign=c1+c2>=29?1:0;
    int b=b1+b2+sign>=17?b1+b2+sign-17:b1+b2+sign;
    sign=b1+b2+sign>=17?1:0;
    int a=a1+a2+sign;
    printf("%d.%d.%d",a,b,c);
    return 0;
}
