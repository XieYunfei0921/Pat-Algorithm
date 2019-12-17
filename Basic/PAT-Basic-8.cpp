#include <cstdio>
#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

void caculate(double R1,double P1,double R2,double P2){
    double r=R1*R2;
    double p=P1+P2;
    double a=r*cos(p);
    double b=r*sin(p);

    if(a+0.005>0 && a<0)
        printf("%.2f",0.00);
    else{
        printf("%.2f",a);
    }

    if(b+0.005>0 && b<0)
        b=0.00;

    if(b>=0){
        printf("+%.2fi",b);
    }else
    {
        printf("%.2fi",b);        
    }
}   

int main(int argc, char const *argv[])
{   
    double r1,p1,r2,p2;
    cin>>r1>>p1>>r2>>p2;
    caculate(r1,p1,r2,p2);
    return 0;
}
