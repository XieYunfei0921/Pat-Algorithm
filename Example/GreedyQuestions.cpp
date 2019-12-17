#include <iostream>
#include <iomanip>
#include <math.h>
#include <algorithm>
#include <string>

using namespace std;

/*------------------Question------------------------*/
/*
    输入测试用例:
    输入:
        N<=1000 月饼种类数
        D<=500 市场最大需求量
        getLine() N个正数->表示库存
        getLine() N个整数->表示总量
    输出:
        最大利益
*/
/*-----------------Global Parameters---------------------*/
const int maxn=10010;

struct MoonCake{
    double price;
    int total;
    int storage;
    // sort 函数要搭配外部比较器
};

struct Intervals{
    int begin;
    int end;

    void showArea(){
        std::cout << "( "<<this->begin<<" , "<<this->end<<" )" << std::endl;
    }
};

bool cmp_intervals(Intervals a,Intervals b){
    // 排序成左端点升序 
    // 考虑到选取区间的区间包含问题,区间尽量小为优选,所以右端点降序
    // 实际意义是: 去选择Interval较大的元素,这样可以容纳更多的区间
    if(a.begin!=b.begin) return a.begin>b.begin;
    else return a.end>b.end;
}
// 外部比较器要放在外边
bool cmp_desc(MoonCake m1,MoonCake m2){
    return m1.price>m2.price;
}
/*----------------------Method---------------------------*/
double getMaxProfits(int* storage,int* total,int d,int n){
    
    double profit=0.0;
    double* price;
    MoonCake* m;
    
    for (int i = 0; i < n; i++) //On
    {   
        // 指针使用 ->
        (m+i)->price=(double)*(total+i) / *(storage+i);
        // (m+i)->price=( (double)( (int)( ((m+i)->price+0.005)*100 ) ) )/100;
        (m+i)->storage=*(storage+i);
        (m+i)->total=*(total+i);
    }
    sort(m,m+n,cmp_desc);

    // std::cout << m->price << std::endl;

    for (int i = 0; i < n ;i++)
    {   
        // 浮点数最好不要相乘
        if((m+i)->storage<=d){
            profit+=(m+i)->total;
        }else
        {
            profit+=(m+i)->price*d;
            break;
        }
         d=d-(m+i)->storage;
    }

    return profit;
} 
int getMinNumber(int* arr){
    int* num;
    int res=0;
    for (int i = 1; i < 10; i++)
    {   
        // 求首位 index!=0 且值不为0
        if (*(arr+i)!=0)
        {
            *num=i;
            *(arr+i)-=1;
            break;
        }
    }

    // 后边N位的求法z,最多49
    int j=0;
    for (int i = 0; i < 10;i++)
    {
        //每次循环找到arr中非0的最小数,将他的index放到数组中,总共需要放置arr[index]个
        if (*(arr+i)!=0)
        {
            for (; *(arr+i)!=0; j++)
            {
                *(num+1+j)=i;
                *(arr+i)=*(arr+i)-1;
            }
        }
    }
    int multi=1;
    // 不要使用提供的平方
    while (j>=0)
    {   
        res+=*(num+j)*multi;
        multi=10*multi;
        j--;
    }
    return res;
}

int greedyAreas(Intervals* arr,int num){
    int res=1;
    int lastX;

    sort(arr,arr+num,cmp_intervals);
    // 去除包含问题, 被包含的元素 比较值大
    lastX=arr->begin;
    for (int i = 0; i < num; i++)
    {
        if ((arr+i)->end<=lastX)
        {
            lastX=(arr+i)->begin;
            res++;
        }
        
    }
    return res;
}

int greedyFindPoints(Intervals* arr,int num){
    int res=1;
    return res;
}

/*------------------------Main---------------------------*/
int main(int argc, char const *argv[])
{
    int n=3,d=20;
    int storage[3]={18,15,10};
    int total[3]={75,72,45};
    int arr[10]={2,2,0,0,0,3,0,0,1,0};
    // std::cout <<getMinNumber(arr) << std::endl;
    Intervals intval[4]={{1,3},{2,4},{3,5},{6,7}};
    std::cout << "-------" << std::endl;
    std::cout << "GreedyAreasNum= "<<greedyAreas(intval,4) << std::endl;
    return 0;
}
