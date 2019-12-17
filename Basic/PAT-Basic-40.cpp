#include <iostream>
#include <algorithm>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{
    int a1,b1,c1,a2,b2,c2;
    scanf("%d.%d.%d %d.%d.%d",&a1,&b1,&c1,&a2,&b2,&c2);
    int P=a1*17*29+b1*29+c1;
    int A=a2*17*29+b2*29+c2;
    int lost=A-P;
    int a3=lost/(29*17);
    int b3=lost%(29*17)/29;
    int c3=lost%(29*17)%29;
    lost>=0?printf("%d.%d.%d",a3,b3,c3):printf("-%d.%d.%d",abs(a3),abs(b3),abs(c3));
    return 0;
}
