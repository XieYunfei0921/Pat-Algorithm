#include <iostream>
#include <string>
using namespace std;
/*
    String 库的使用:
*/

int main(int argc, char const *argv[])
{
    // 定义
    string str="sandee";
    string str2="cindy";
    string s="mxd";
    // 访问
    // 下标访问
    std::cout << "字符串的下标访问:" << std::endl;
    for (int i = 0; i < str.length(); i++)
    {
        std::cout <<str[i] <<"\t" ;
    }
    std::cout << "\n迭代器访问:" << std::endl;
    // 迭代器访问
    for (string::iterator i = str.begin(); i != str.end(); i++)
    {
        std::cout << *i << "\t";
    }

    // 常用函数
    // 字符串拼接
    std::cout << "\n字符串拼接:"<<str+" "+str2 << std::endl;

    // 字符串比较
    if (str>str2)
    {
        std::cout << "Big" << std::endl;
    }else
    {
        std::cout << "Small" << std::endl;
    }

    // 字符串长度
    std::cout << "字符串长度: "<<str.length() << std::endl;
    
    // 字符串插入
    str.insert(3,str2);
    std::cout << "插入后的字符串:"<<str << std::endl;

    // erase 单个
    str.erase(str.begin()+3);
    std::cout << "删除单个元素:"<<str << std::endl;

    // erase 多个
    str.erase(str.begin()+3,str.begin()+7);
    std::cout << "删除多个元素:" <<str<< std::endl;

    std::cout << "清空前:"<<s << std::endl;
    s.clear();
    std::cout << "清空后:"<<s << std::endl;

    std::cout << "截取1-3位: " <<str.substr(0,3)<< std::endl;

    std::cout << "寻找第一次出现索引:" <<str.find('e')<< std::endl;
    
    // 没有找到索引string:npos的使用
    if (str.find('k')==string::npos)
    {
        std::cout << "没有匹配的位置:" << std::endl;
    }else
    {
        std::cout << "匹配位置为:"<<str.find('k') << std::endl;
    }
    
    // replace
    str.replace(4,2,"y");
    std::cout << "替换后的字符串为:"<<str << std::endl;

    std::cout << "再次替换后的结果为:"<<str.replace(str.begin()+4,str.end(),"ee") << std::endl;

    return 0;
}
