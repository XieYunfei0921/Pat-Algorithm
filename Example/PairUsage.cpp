#include <utility>
#include <iostream>
#include <string>
using namespace std;

// 作用 -- 代替只有两个属性的结构体

int main(int argc, char const *argv[])
{
    pair<int,string> stu;
    stu.first=2;
    stu.second="sandee";
    std::cout << "学号:"<<stu.first<<"\t姓名: "<<stu.second << std::endl;
    
    return 0;
}
