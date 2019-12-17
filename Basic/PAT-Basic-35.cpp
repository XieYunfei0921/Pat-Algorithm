#include <algorithm>
#include <cstdio>
#include <string>
using namespace std;

int gdb(int a,int b){
    return b==0?a:gdb(b,a%b);
}

struct Fraction{
    int son;
    int mather;
}f1,f2;
Fraction add(Fraction f1,Fraction f2){
    Fraction f;
    f.son=f1.son*f2.mather+f2.son*f1.mather;
    f.mather=f1.mather*f2.mather;
    return f;
}
Fraction sub(Fraction f1,Fraction f2){
    Fraction f;
    f.son=f1.son*f2.mather-f2.son*f1.mather;
    f.mather=f1.mather*f2.mather;
    return f;
}
Fraction multi(Fraction f1,Fraction f2){
    Fraction f;
    f.son=f1.son*f2.son;
    f.mather=f1.mather*f2.mather;
    return f;
}
Fraction divide(Fraction f1,Fraction f2){
    Fraction f;
    if(f2.son==0){
        f.son=1;f.mather=0;
        return f;
    }
    f.son=f1.son*f2.mather;
    f.mather=f1.mather*f2.son;
    if(f.mather<0){
        f.mather=-f.mather;
        f.son=-f.son;
    }
    return f;
}
void show(Fraction f){
    int factor=gdb(f.son,f.mather);
    f.son/=abs(factor);
    f.mather/=abs(factor);
    if(f.mather==0) {printf("Inf");return;}
    if(f.son<0){
        if(f.mather==1) {printf("(%d)",f.son);return;}
        if(abs(f.son)<f.mather) {printf("(%d/%d)",f.son,f.mather);return;}
        if(abs(f.son)>f.mather) {printf("(-%d %d/%d)",abs(f.son)/f.mather,abs(f.son)%f.mather,f.mather);return;}
    }else
    {
        if(f.mather==1) {printf("%d",f.son);return;}
        if(f.son<f.mather) printf("%d/%d",f.son,f.mather);
        if(f.son>f.mather) printf("%d %d/%d",f.son/f.mather,f.son%f.mather,f.mather);
    }
}

int main(int argc, char const *argv[])
{
    int a1,b1,a2,b2;
    scanf("%d/%d %d/%d",&a1,&b1,&a2,&b2);
    f1.son=a1;f1.mather=b1;f2.son=a2;f2.mather=b2;
    show(f1);printf(" + ");show(f2);printf(" = ");show(add(f1,f2));printf("\n");
    show(f1);printf(" - ");show(f2);printf(" = ");show(sub(f1,f2));printf("\n");
    show(f1);printf(" * ");show(f2);printf(" = ");show(multi(f1,f2));printf("\n");
    show(f1);printf(" / ");show(f2);printf(" = ");show(divide(f1,f2));
    return 0;
}
