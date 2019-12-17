#include <iostream>
#include <stack>
#include <string>
using namespace std;

// 栈的使用
// 使用栈模拟递归

int main(int argc, char const *argv[])
{
    // 定义
    stack<int> s;
    s.push(2);
    s.push(5);
    s.push(1);
    // 访问 top访问栈顶元素
    std::cout << "栈顶元素: "<<s.top() << std::endl;
    std::cout << "栈长度: "<<s.size() << std::endl;
     std::cout << "栈是否为空: "<<s.empty() << std::endl;
    return 0;
}
