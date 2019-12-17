#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int gdb(int a,int b){
    return b==0?a:gdb(b,a%b);
}
struct Fraction{
    int s;
    int m;
    void add(Fraction f){
        this->s=this->m*f.s+this->s*f.m;
        this->m=f.m*this->m;
    }
    void simplize(){
        int gd=gdb(this->s,this->m);
        this->s/=gd;
        this->m/=gd;
    }
    void show(){
        if(this->m<0){this->m*=-1;this->s*=-1;}
        if(this->s%this->m==0) {std::cout << this->s/this->m << std::endl;return;}
        if(abs(this->s)/this->m>=1) {
            if(this->s/this->m>0)
                std::cout << this->s/this->m<<" "<<this->s%this->m<<"/"<<this->m << std::endl;
            else
                std::cout <<"-" <<abs(this->s)/this->m<<" "<<abs(this->s)%this->m<<"/"<<this->m << std::endl;
            return;
        }
        std::cout << this->s<<"/"<<this->m << std::endl;
    }
};
int main(int argc, char const *argv[])
{
    int n;
    long long a,b;
    scanf("%d",&n);
    scanf("%lld/%lld",&a,&b);
    Fraction f={a,b};
    for (int i = 0; i < n-1; i++)
    {
        scanf("%lld/%lld",&a,&b);
        f.add(Fraction{a,b});
        f.simplize();
    }
    f.simplize();
    f.show();
    return 0;
}
