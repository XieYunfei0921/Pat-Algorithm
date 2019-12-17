#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;

const int maxn=10010;
const int prime=31;

// 数组元素hash
/*
    TODO 形成数组a的散列表
    直接将输入的元素作为数组的下标,但是此方法需要注意输入元素不要过大,否则超出限制
    即: input<maxn
    return hash去重的数组
    由此可知hash表的相邻元素地址上是不连续的,因为是以值做key查询的
*/
int* hashDirectTable(int a[],int len){
    // 如何形成单链表使得使用迭代器能够寻找到下一个元素
    bool hashtable[maxn]={false};
    for (int i = 0; i < len; i++)
    {
        // hashcode=false表示这个位置上没有数
        if (hashtable[a[i]]==false)
        {
            // hash位置没有插入数值,插入时更改
            hashtable[a[i]]=true;
        }
    }
    return a;
}

// 除余hash法 Hash(key)=key%prime   O(n)
bool* hashTable(int* a,int len){
    bool codes[maxn]={false};

    for (int i = 0; i < len; i++)
    {
        if (codes[*(a+i)]==false)
        {
            codes[*(a+i)]==true;
        }
    }
    return codes;
}

// 使用hash表查询重复元素
int* numCount(int a[],int len){
    // cnt 与a数组同一个维度
    int cnt[maxn]={0};
    for (int i = 0; i < len; i++)
    {
        cnt[a[i]]++;
    }
    return cnt;
}

int getNum(int a[],int search){
    return a[search];
}

// string -> long long
long long getStringHashcode(string s){
    long long id=0;
    int deta=0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i]>'A' && s[i]<'Z')
        {
            deta=s[i]-'A';
        }else if(s[i]>'a' && s[i]<'z')
        {
            deta=26+s[i]-'a';
        }else if(s[i]>'0' && s[i]<'9')
        {
            deta=52+s[i]-'0';
        }
        id+=id*62+(s[i]-'A');
    }
    return id;
}

int main(int argc, char const *argv[])
{
    int a[12]={3,4,1,4,6,7,8,3,4,5,-1,5};

    // for (int i = 0; i < 12; i++)
    // {
    //     std::cout << "Num= "<<getNum(numCount(a,12),5) << std::endl;

    // }
    
    string s="sandeE";
    std::cout << getStringHashcode(s) << std::endl;


    return 0;
}
