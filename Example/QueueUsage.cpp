#include <iostream>
#include <queue>
#include <string>
using namespace std;

// front 和 pop之前,需要确保队列非空,否则报错

// 双端队列 deque 
// 优先队列 priority_queue(本质是堆)  用途: 贪心问题,Dijkstra算法
struct fruit
{
    string name;
    int price;
    // 结构体要使用优先级,则必须要定义比较器
    friend bool operator <  (fruit f1,fruit f2){
        return f1.price<f2.price;
    }
}f1,f2,f3;



int main(int argc, char const *argv[])
{   
    // 队列的定义
    queue<string> names;
    names.push("sandee");
    names.push("cindy");
    names.push("trick");
    names.push("game");
    names.push("rose");
    names.push("charge");
    names.push("debug");

    // front 访问首元素,back访问尾元素
    std::cout << "队首: " <<names.front()<<"\t队尾: "<<names.back()<< std::endl;
    // 队列的访问
    // pop 队首出列
    names.pop();
    std::cout << "队首:"<<names.front() << std::endl;

    // 队列的常用方法
    std::cout << "队列受否为空:"<<names.empty() << std::endl;
    std::cout << "队列长度: "<<names.size() << std::endl;
    
    // 优先队列的使用
    priority_queue<int> scores;

    scores.push(62);
    scores.push(44);
    scores.push(21);
    scores.push(110);
    scores.push(91);

    // 优先队列 堆顶原则: 优先级越高高靠堆顶越近
    // top访问堆顶
    // 最大则优先级越高
    std::cout << "优先队列堆顶: "<<scores.top() << std::endl;
    scores.pop();
    std::cout << "优先队列堆顶: "<<scores.top() << std::endl;
    
    // 优先队列 + 结构体
    priority_queue<fruit> fq;
    f1.price=21;
    f1.name="apple";
    f2.price=36;
    f2.name="banana";
    f3.price=17;
    f3.name="orange";

    fq.push(f1);
    fq.push(f2);
    fq.push(f3);

    std::cout << "优先级最高的水果信息: " <<fq.top().name<< std::endl;
    // 优先队列的访问
    
    return 0;
}
