#include <iostream>
#include <math.h>
#include <string>
using namespace std;

struct Fraction
{
    int down,up;
    // 四则运算
    Fraction add(Fraction f1,Fraction f2){
        Fraction f;
        f.up=f1.up*f2.down+f2.up*f1.down;
        f.down=f1.down*f2.down;
        return f;
    }

    Fraction sub(Fraction f1,Fraction f2){
        Fraction f;
        f.up=f1.up*f2.down-f2.up*f1.down;
        f.down=f1.down*f2.down;
        return f;
    }

    Fraction multi(Fraction f1,Fraction f2){
        Fraction f;
        f.up=f1.up*f2.up;
        f.down=f1.down*f2.down;
        return f;
    }
    
    Fraction devide(Fraction f1,Fraction f2){
        Fraction f;
        f.up=f1.up*f2.down;
        f.down=f1.down*f2.up;
        return f;
    }
    // 简化
    Fraction simplize(Fraction f){
        // 分子分母除以最大公约数
        /* 规则: 
            1. 分子为0 这设置分母为1
            2. 分母非负,若为负符号转移给分子
            3. 同除以最大公约数
        */
       if(f.up==0)
            f.down=1;
       else if(f.down<0){
           f.down=-f.down;
           f.up=-f.up;
       }
       else
       {
           f.down=f.down/gcd(f.down,f.up);
           f.up=f.up/gcd(f.down,f.up);
       }
    }
    // 输出
    void showFraction(Fraction f){
        if(f.up%f.down==0)
            std::cout <<f.up/f.down  << std::endl;
        else if(f.down>f.up)
            std::cout << f.up<<"/"<<f.down << std::endl;
        else
        {
            std::cout << f.up/f.down<<" "<<(f.up-f.up/f.down*f.down)<<"/"<<f.down << std::endl;
        }
    }
    // 辅助
    int gcd(int a,int b){
        // 求最大公约数
        if(b==0){
            return a;
        } else
        {
            return gcd(b,a%b);
        }
    }

}f1,f2,f;

int main(int argc, char const *argv[])
{

    f1.up=3,f1.down=5;
    f2.up=4,f2.down=7;
    f=f1.sub(f1,f2);

    f1.showFraction(f);

    return 0;
}
