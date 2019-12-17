#include <algorithm>
#include <iostream>
#include <stdio.h>
using namespace std;
int gdb(int a,int b){
    return b==0?a:gdb(b,a%b);
}
struct Node{
    int s;
    int m;
    void add(Node n){
        int a=this->m,b=this->s;
        this->s=a*n.s+b*n.m;
        this->m=n.m*a;
    }
    void sub(Node n){
        int a=this->m,b=this->s;
        this->s=b*n.m-a*n.s;
        this->m=a*n.m;
    }
    void mul(Node n){
        this->s=this->s*n.s;
        this->m=this->m*n.m;
    }
    void div(Node n){
        this->s=this->s*n.m;
        this->m=this->m*n.s;
    }
    void simplize(){
        if(this->s==0 && this->m==0) return;
        int fd=gdb(this->s,this->m);
        this->s/=fd;
        this->m/=fd;
    }
    void show(){
        if(this->m==0){
            cout<<"Inf";
            return;
        }
        if(this->s==0){
            std::cout << "0" ;
            return;
        }
        if(this->m<0){
            this->m*=-1;
            this->s*=-1;
        }
        if(this->s<0){
            if(this->s%this->m==0){
                std::cout <<"("<< this->s/this->m<<")";
                return;
            }
            if(abs(this->s)<this->m){
                std::cout<<"(" << this->s<<"/"<<this->m<<")";
                return;
            }    
            std::cout<<"(-" << abs(this->s)/this->m<<" "<<abs(this->s)%this->m<<"/"<<this->m<<")";
        }else{
            if(this->s%this->m==0){
                std::cout << this->s/this->m;
                return;
            }
            if(this->s<this->m){
                std::cout << this->s<<"/"<<this->m;
                return;
            }    
            std::cout << this->s/this->m<<" "<<this->s%this->m<<"/"<<this->m ;
        }
    }
}n1,n2,n3;
int main(int argc, char const *argv[])
{   
    long long a1,b1,a2,b2;
    scanf("%lld/%lld %lld/%lld",&a1,&b1,&a2,&b2);
    n1={a1,b1};
    n3={a1,b1};
    n2={a2,b2};
    n1.simplize();
    n2.simplize();
    n1.show();
    cout<<" + ";
    n2.show();
    cout<<" = ";
    n3.add(n2);
    n3.simplize();
    n3.show();
    std::cout << "" << std::endl;
    n3={a1,b1};
    n1.show();
    cout<<" - ";
    n2.show();
    cout<<" = ";
    n3.sub(n2);
    n3.simplize();
    n3.show();
    std::cout << "" << std::endl;
    n3={a1,b1};
    n1.show();
    cout<<" * ";
    n2.show();
    cout<<" = ";
    n3.mul(n2);
    n3.simplize();
    n3.show();
    std::cout << "" << std::endl;
    n3={a1,b1};
    n1.show();
    cout<<" / ";
    n2.show();
    cout<<" = ";
    n3.div(n2);
    n3.simplize();
    n3.show(); 
    return 0;
}
