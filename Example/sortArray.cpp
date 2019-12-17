#include <iostream>
#include <string> // compare
// #include <cstring> //strcmp
#include <math.h>
#include <vector>
#include <algorithm>
using namespace std;


int maxn=100;

struct Stundent
{
    // 实现自定义排序
    int id;
    string name;
    float score;

    // 大于 1 小于0
    bool cmp(Stundent s1){
        if (this->score!=s1.score)
            return this->score>s1.score;
        else 
            return this->name.compare(s1.name);
    };
};


vector<int> insertSort(vector<int> a){
    int temp,j;
    for (int i = 1; i < a.size(); i++)
    {   
        // i元素暂时存储,枚举从i开始向前枚举找到插入数据的索引j
        j=i;
        temp=a[i];
        // 向前枚举 条件: temp<a[j-1]
        while (j>0 && temp<a[j-1])
        {
            // 大的元素向右移动
            a[j]=a[j-1];
            j--;
        }

        // temp>a[j-1] 说明temp就在j的位置
        a[j]=temp;
    }
    
    return a;
}

// 泛型定义要紧邻方法
// template <typename T>
Stundent* selectSort(Stundent a[],int len){
    Stundent swap;
    for (int i = 0; i < len-1; i++)
    {
        for (int j = i+1; j < len; j++)
        {
            if (!a[j].cmp(a[i]))
            {
                swap=a[i];
                a[i]=a[j];
                a[j]=swap;
            }
        }
        // std::cout << a[i].name<<"\t"<<a[i].score<< std::endl;
    }
    return a;
    
}

int main(int argc, char const *argv[])
{
    /*
        思路: 
        将前n-1 序列转化成 n个有序的序列
    */
//    vector<int> v,v1;
//    v.push_back(4);
//    v.push_back(3);
//    v.push_back(-1);
//    v.push_back(0);
//    v.push_back(3);
//    v.push_back(2);
//    v.push_back(9);
//    v.push_back(7);
//    v1=insertSort(v);
//    for (vector<int>::iterator i = v1.begin(); i != v1.end(); i++)
//    {
//        cout<<*i<<" ";
//    }
   
   Stundent s[5]={{3,"sandee",85.5},{1,"cindy",78.9},{4,"saber",85.5},{6,"godness",81.2},{2,"pendy",73.3}};
   
   selectSort(s,5);
   for (int i = 0; i < 5; i++)
   {
       cout<<s[i].name<<"\t"<<s[i].score<<"\n";

   }
   
   

    return 0;
}
