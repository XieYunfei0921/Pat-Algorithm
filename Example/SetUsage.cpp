#include <iostream>
#include <set>
using namespace std;

/* set集合的使用
    特征：内部自动有序(经过排序的)，去重
    只去重: multiset  
    升序去重: set
*/


int main(int argc, char const *argv[])
{   
    //set 的定义
    set<int> ids;
    set<float> scores[20]; // 20个set容器

    //set 元素的访问 --< 迭代器访问
    // insert 插入 排序去重 O（log N）
    ids.insert(5);
    ids.insert(3);
    ids.insert(1);
    ids.insert(4);
    ids.insert(8);
    ids.insert(-1);
    ids.insert(4);
    
    for (set<int>::iterator it = ids.begin(); it != ids.end(); it++)
    {
        cout<<*it<<'\t';
    }
    
    // find(value) 返回迭代器 复杂度 O（log N）
    set<int>::iterator ite=ids.find(4);
    cout<<"\n"<<*ite;

    // erase 删除单个元素
    ids.erase(ids.find(3));
    cout<<"\n删除单个元素之后:\n";

    for (set<int>::iterator it = ids.begin(); it != ids.end(); it++)
    {
        cout<<*it<<'\t';
    }

    // erase 删除两个迭代器之间的元素 O（log N）
    ids.erase(ids.find(1),ids.find(5));
    cout<<"\n删除多个个元素之后:\n";
    for (set<int>::iterator it = ids.begin(); it != ids.end(); it++)
    {
        cout<<*it<<'\t';
    }

    // set常用函数
    cout<<"\n清除前集合大小:"<<ids.size()<<"\n";
    // clear的使用
    ids.clear();
    cout<<"清除前集合大小:"<<ids.size()<<"\n";


    return 0;
}
