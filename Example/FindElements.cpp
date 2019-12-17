#include <iostream>
#include <string>
#include <math.h>
using namespace std;

// 小范围查找 --> 遍历
// 大范围查找 --> 二分查找

int main(int argc, char const *argv[]){
    
    // n<200 属于小范围
    int n;
    std::cout << "输入数组长度n= ";
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }

    std::cout << "插入元素为 :" << std::endl;
    int num;
    cin>>num;
    for (int i = 0; i < n; i++)
    {
        if (arr[i]==num)
        {
            std::cout << "x的索引为\t"<<i << std::endl;
            break;
        }
        if (i==(n-1) && arr[i]!=num)
        {
            std::cout << "x的索引为\t"<<-1 << std::endl;
        }
        
        
    }
    


    

    
    return 0;
}