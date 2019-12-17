#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
using namespace std;

const int maxn=10010;
// 计数器
int cnt=0;
// 去重hash数组
bool hashTable[maxn]={false};
// 初始列号
int init_row=1;
// 游动列号
int row=1;

/*
    n皇后问题:
    回溯法
    皇后们不在一行一列,或者是一条对角线
    在一行中寻找:
        满足与之前n-1行满足n皇后关系的列
        方法:
            一个一个试,是否满足关系
*/
void nPrincess(int scale){

    
    // 输出的是第一行的一个结果
    bool flag=true;
    // 列数组 最大长度为正方形边长scale 存储的是列号>1
    int princess[scale]={0};
    if (init_row>scale)
        return;
    
    // 寻找一个方案 需要去重否则可能一直统计这一个方案
    // 不要写0 ,否则列数组不容易初始化(需要memset)
    for (int i = 1; i <= scale; i++)
    {   
        // 递归终止条件
        // 查找不重复的解
        // hash表可以用来做去重，加锁的工作
        if (i==1)
        {
            princess[1]=init_row;
            continue;
        }
        
        if (hashTable[i]==false)
        {   
            // 与前j行比较
            for (int j = 1; j < i; j++)
            {
                // TODO 尝试列号=row是否合适
                // 行 i j
                // 列 princess row
                if (abs(i-j)==abs(row-princess[j]) || princess[j]==row || princess[j]==0)
                {
                    flag=false;
                    if ((row+1)>scale)
                        row=1;
                    else
                        row++;
                    break;
                }
                // else
                // {
                //      std::cout << "Enter Flag\t"<< "i="<<i<<"\t"<<"j="<<j<<"\t"<<"row(i)="<<row<<"\t"<<"row(j)="<<princess[j]<< std::endl;
                // }
                
            }
            if (flag)
            {
                // 记录到列表中 进行下一次递归
                // 位置 第i行 值为row
                princess[i]=row;
                cnt++;
                if (i==scale)
                    break;
                // 进行下一个数
                continue;
            }
        }

    }
    init_row++;
    nPrincess(scale);
}

int main(int argc, char const *argv[])
{

    nPrincess(35);
    std::cout << "Princess= "<<cnt << std::endl;
    
    return 0;
}
