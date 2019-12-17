#include <iostream>
#include <math.h>
#include <string>
using namespace std;

// 求日期差值
int cnt=0;

// 闰年366, 平年365
int getDaysofTwoDate(int from,int to){

    int days;
    int swap;
    if (from > to )
    {
        swap=from;
        from=to;
        to=swap;
    }
    
    // 从from加到to
    // 日向上加
    switch (from%10000/100)
    {
        case 1: case 3 : case 5: case 7: case 8 : case 10 : case 12:
            days=31;
        break;
        case 4: case 6: case 9: case 11:
            days=30;
        break;
        
        default:
            if (from/10000%4==0 && !(from/1000000==0 && from/4000000!=0))
            {
                days=29;
            }else
            {
                days=28;
            }
        break;
    }

    while (from<to)
    {
        if (from%100==days)
        {   
            // 到下个月需要重新调用函数
            if (from%10000/100==12)
            {
                from=from/10000*10000+100;
            }
            from=(from/100+1)*100;
        }
        from++;
        cnt++;
        std::cout << "cnt= "<<cnt << std::endl;
        
    }

    if (!(cnt-1))
    {
        cnt=2;
    }
    
    
    return cnt;
}

int main(int argc, char const *argv[])
{
    // int a=20130701 & 0xff;
    // std::cout << 33506/100*100 << std::endl;
    std::cout << "日期差: "<<getDaysofTwoDate(20130104,20130205) << std::endl;
    return 0;
}
