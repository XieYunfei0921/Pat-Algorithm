#include <iostream>
#include <map>
#include <vector>
using namespace std;

// 内部由红黑树实现,所以装进去的元素按key升序
// 常见用途:
// 1. 字符与整数的映射问题
// 2. 判断大整数与其他数据类型是否存在的问题
// 3. 字符串间的映射问题

// 1对多 : multimap
// 散列表 : 去重
// 红黑树 : 排序

int main(int argc, char const *argv[])
{
    
    // map的定义
    map<int,string> student;
    map<int,vector<int> > grade;

    student[1]="sandee";
    student[14]="mxd";
    student[2]="cindy";
    student[8]="tridy";
    student[8]="tricy";
    student[28]="duck";

    // map元素的访问
    // 1. 通过下标来访问
    std::cout << "key=8\tvalue=\t" <<student[8]<< std::endl;
    // 2. 使用迭代器访问
    for (map<int,string>::iterator i = student.begin(); i != student.end(); i++)
    {
        std::cout << "学生ID="<<i->first<<"\t学生姓名="<<i->second<< std::endl;
    }
    

    // map的常用方法
    // 查找 find()
    std::cout << "查找ID=2的学生姓名:\t"<< student.find(2)->second << std::endl;

    // erase 去除id=8的学生信息
    student.erase(8);
    std::cout << "-------------\n去除后的学生信息表:" << std::endl;

    for (map<int,string>::iterator i = student.begin(); i != student.end(); i++)
    {
        std::cout << "学生ID="<<i->first<<"\t学生姓名="<<i->second<< std::endl;
    }
    
    student.erase(student.begin(),student.find(14));
    std::cout << "-------------\n去除多个后的学生信息表:" << std::endl;

    
    for (map<int,string>::iterator i = student.begin(); i != student.end(); i++)
    {
        std::cout << "学生ID="<<i->first<<"\t学生姓名="<<i->second<< std::endl;
    }
    

    return 0;
}
