#include <iostream>
//  引入动态数组
#include <vector>
using namespace std;
// C++ STL库的使用
// 常用: 用于对数组增添元素，时间复杂度低
// 实现邻接矩阵

int main(int argc, const char** argv) {

    // vector定义
    vector<int> ids;
    vector<string> names;
    // < < 间要加空格,与移动位置操作区分
    vector<vector<string> > paras;
    
    // 定义vector数组
    vector<int> vi[20];

    for (int i = 0; i < 5; i++)
    {   
        // push_back 末尾添加元素 O(1)
        ids.push_back(i);
    }

    // vector元素的访问
    // 1. 使用数组下标访问 范围 0-ids.size()-1
    cout<<"使用数组下标访问\t"<<ids[0]<<"\t"<<ids[ids.size()-1]<<"\n";

    cout<<"删除之前的长度:"<<ids.size()<<"\n";
    // pop_back 末尾删除元素 O(1)
    ids.pop_back();
    cout<<"删除之后的长度:"<<ids.size()<<"\n";
    // 2. 使用迭代器访问
    vector<int>::iterator it=ids.begin();
    cout<<"使用迭代器访问数据:\n";
    // 测试发现: vector的删除是把容器的范围重新划定了，而vector的被删除位置的值还是没变
    for (int i = 0; i < ids.size(); i++)
    {
        cout<<*(it+i)<<"\t";
    }

    // 每个位置都清，取决于数组的长度 复杂度O（n）
    // ids.clear();
    // cout<<"\n清除之后的长度:"<<ids.size()<<"\n";
    
    // insert插入 将目标值，插入到目标索引位置上，后面的数据向后移动一位
    ids.insert(ids.begin()+2,-5);
    cout<<"\ninsert后的结果:\n";
    for (int i = 0; i < ids.size(); i++)
    {
        cout<<*(it+i)<<"\t";
    }
    // erase 擦除功能
    ids.erase(ids.begin()+2);
    cout<<"\nerase单个后的结果:\n";
    for (int i = 0; i < ids.size(); i++)
    {
        cout<<*(it+i)<<"\t";
    }
    ids.erase(ids.begin(),ids.begin()+2);
    cout<<"\nerase多个后的结果:\n";// 删前不删后
    for (int i = 0; i < ids.size(); i++)
    {
        cout<<*(it+i)<<"\t";
    }

    return 0;
}