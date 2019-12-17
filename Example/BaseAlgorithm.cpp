#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    std::cout << "1,5最大值: "<<max(1,5) << std::endl;
    std::cout << "1,5最小值: "<<min(1,5) << std::endl;
    std::cout << "-3的绝对值是: "<<abs(-3) << std::endl;

    int x=1,y=3;
    std::cout << "交换前: x="<<x <<"  y="<<y << std::endl;
    swap(x,y);
    std::cout << "交换后: x="<<x <<"  y="<<y << std::endl;
    
    int a[5]={1,7,2,3,4};
    reverse(a,a+3);

    std::cout << "反转后:" << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << a[i] << std::endl;
    }
    
    // int b[3]={1,2,4};
    // while (next_permulation(b,b+3))
    // {
    //     std::cout << "b[0]: "<<b[0]<<" b[1]: "<<b[1]<<" b[2]: "<<b[2]<< std::endl;
    // }

    // fill 的使用
    fill(a,a+3,888);
    std::cout << "Fill过后..." << std::endl;
    for (int i = 0; i < 5; i++)
    {
        std::cout << a[i] << std::endl;
    }
    
    std::cout << "-------------------------" << std::endl;

    int cp[8]={6,2,1,4,3,9,-2,4};
    sort(cp,cp+4);

    for (int i = 0; i < 8; i++)
    {
         std::cout << cp[i] << std::endl;
    }
    
    std::cout << "-------------------------" << std::endl;

    // lower_bound 和 upper_bound 用于数组/容器中
    // 数组返回指针,容器返回迭代器
    // 返回范围内第一个小于/大于指定值的指针  
    std::cout << "low_bound value= "<<*lower_bound(cp,cp+5,1) << std::endl;
    std::cout << "upper_bound value= "<<*upper_bound(cp,cp+5,8) << std::endl;
    return 0;
}
