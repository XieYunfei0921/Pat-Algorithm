#include <iostream>
#include <math.h>
#include <string>
using namespace std;

struct BigNumber
{
    // 数组低位对应数字地位
    int digi[100];
    int len;

    BigNumber add(BigNumber b1,BigNumber b2){

        BigNumber b;
        int advan=0;
        int ml=max(b1.len,b2.len);
        //等位相加
        if(b1.len==b2.len && (b1[len]+b2[len])>10)
            b.len=b1.len+1;
        else
            b.len=ml;

        for (int i = 0; i < b.len; i++)
        {
            b.digi[i]=advan+b1.digi[i]+b2.digi[i];
            advan=(b1.digi[i]+b2.digi[i])/10;
        }

        return b;   
    }

    BigNumber subscribe(BigNumber b1,BigNumber b2){
        // 假设 b1>b2
        BigNumber b;
        int borrow=0;
        int ml=max(b1.len,b2.len);
        for(int i=0;i<ml;i++)
        {   
            // 计算借位符
            borrow=b1.digi[i]>b2.digi[i]?0:1;
            // 定位到最近高位非0
            for (int j = i+1; j < ml; j++)
            {
                if (b1.digi[j]==0)
                {
                    b1.digi[j]=9;
                    continue;
                }else
                {
                    b1.digi[i+1]-=borrow;
                    break;
                }
            }
            b.digi[i]=10*borrow+b1.digi[i]-b2.digi[i];
        }

        if (b1.digi[ml]==0)
            b.len=b1.len-1;
        b.len=b1.len;
        return b;   
    }

    BigNumber multiply(BigNumber b1,BigNumber b2){
        BigNumber b,res;
        int up=0;
        int offset=0;
        for (int i = 0; i < b2.len; i++)
        {
            // 单值乘法
            for (int j = 0; j < b1.len; j++)
            {
                b.digi[i]=up+b1.digi[j]*b2.digi[i]%10;
                up=b1.digi[j]*b2.digi[i]/10;
            }

            res.add()
            
        }
        
        return b;   
    }

    BigNumber devide(BigNumber b1,BigNumber b2){
        BigNumber b;
        return b;   
    }

}b1,b2,b;


int main(int argc, char const *argv[])
{

    return 0;
}
