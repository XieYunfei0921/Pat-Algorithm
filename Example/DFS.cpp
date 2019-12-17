#include <iostream>
#include <math.h>
#include <string>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;
// 深度优先搜索
/*
    有n件物品,重量w[i],价值c[i]现在放在容量为V的包中,如何使得包里的价值最大 n=1-20
    1. 使用DFS
        分叉点: 放入/不放入
        死胡同: 总重量超过
        枚举所有路径的方法
        特点: 遇到死胡同时,退到最近的岔道口,选择另一条岔路
    2. 使用贪心思想

    方案1,方案2结果一样,但是方案2的时间复杂度低
    3. 树的遍历
*/
int value=0,weight=0;
void DFS(int* w,int* c,int V,int n){

    // 递归边界 所有的物品都决策完了 
    if (n==0)
    {
        return;
    }
    if (weight<=V) // 没有遇到死胡同,继续向下搜索
    {
        value+=*c;
        weight+=*w;
    }else
    {
        // 遇到死胡同,返回上一层,选择另一条路径
        value-=*c;
        weight-=*w;
    }
    // 继续向下搜索
    DFS(w+1,c+1,V,n-1);
}

/*
    贪心法:
*/
struct Items{
    int weight;
    int price;
    double rate;
};

bool cmp(Items it1,Items it2){
    return it1.rate>it2.rate;
}

/*在序列A中找到k个数的和为Num,在其中获取平方和最大的元素
    死路: 和等于Num
    节点: 数组中某个元素的选择与否
    共计len个节点,其中选择的节点共计k个
    先要收集所有和为num的集合
    递归边界: k个节点选取完毕
*/
void findSubArray(int* arr,int k,int len,int num){
    // 创建一个数组用于记录原数组选出来数据的下标
    int sum=0;
    // 在0到len-1的区间内枚举所有
    if(k==0)
        return;


    

}

/*
    使用DFS穷举数组的所有集合元素个数为k子集合
    转成
    死路: 获取的元素到达了k个
        返回上一层操作第k-1个元素向后移动一位
    岔路: 选择/不选择索引为k的数
    递归边界: 
*/
vector<int> ans;
queue<vector<int> > res;
bool flags[100]={false};
int index=0;
void listArea(int* arr,int len,int k){
    if(k==0){
        for (int i = 0; i < ans.size(); i++)
        {
            cout<<ans[i]<<" ";
        }
        res.push(ans);
        return;
    }
    // 选择标记
    /* 遇到死路: 选的数不够
        跳到上一个没有选择的点,将它改为已经选择,接着枚举
        如何去跳跃:
        index--
    */
    if (len<k)
    {   
        // 跳过true的元素
        int temp=0;
        while (flags[--index]!=0)
        {
            temp++;
        }
        //修改最近为false的访问状态
        flags[index]=1;
        // 修改计算范围
        listArea(arr-temp,len+temp,k);
        std::cout << "temp= "<<temp<<"\tk= "<<k<<"\tflags= "<<flags[index]<<"\tindex= "<<index << std::endl;
    }

    if(!flags[index]){
        index++;
        listArea(arr+1,len-1,k);
    }
    else
    {   
        index++;
        listArea(arr+1,len-1,k-1);
        ans.push_back(*arr);
    }
    
}

int main(int argc, char const *argv[])
{
    // int w[5]={2,3,1,5,4};
    // int c[5]={3,2,4,13,8};
    // int V=12;
    // int n=5;
    // DFS(w,c,V,n);
    // std::cout << "First Value= "<<value << std::endl;
    // 贪心测试
    // Items its[5];
    // for(int i=0;i<5;i++){
    //     its[i].price=c[i];
    //     its[i].weight=w[i];
    //     its[i].rate=(double)its[i].price/its[i].weight;
    // }
    // sort(its,its+5,cmp);
    // int tw=0;
    // int tc=0;
    // for (int i = 0; i < 5; i++)
    // {
    //     if (tw<=V)
    //     {
    //         tw+=its[i].weight;
    //         tc+=its[i].price;
    //     }else
    //     {
    //         break;
    //     }
    // }
    // cout<<"Second Value= "<<tc; 

    
    int arr[4]={1,2,3,4};
    listArea(arr,4,3);
    while (!res.empty())
    {
        std::cout << "size= "<<res.front().size() << std::endl;
        
        // for (int i = 0; i < res.front().size(); i++)
        // {
        //     cout<<res.front()[i]<<" ";
        // }
        res.pop();
        std::cout << std::endl;
    }
    

    return 0;
}
