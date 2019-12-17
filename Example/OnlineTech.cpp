#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;
const int MAXN=100001;
const int block_num=ceil(MAXN);
const int ele_num=floor(MAXN);
int hash[MAXN];
int block[block_num];
void init(){
    fill(hash,hash+MAXN,0);
    fill(block,block+block_num,0);
}
void findTopK(int k){
    int sum=0;
    int box=0;
    // 计算前面的个数
    while (sum+block[box]<k)
    {
        sum+=block[box++];
    }
    // 本块第一个索引
    int num=box*ele_num;
    while (sum+hash[num]<k)
    {
        sum+=hash[num++];
    }
    std::cout << "Top K= "<<num << std::endl;
}
int c[MAXN];
int a[MAXN];
int lowbit(int x){
    return x&(-x);
}

// 计算c数组
void translate(int n){
    fill(c,c+n,0);
    c[1]=a[1];
    for (int i = 2; i <= n; i++)
    {
        for (int j = i-lowbit(i)+1; j <= i; j++)
        {
            c[i]+=a[j];
        }
    }
}

int getSum(int x){
    int sum=0;
    for (int i = x; i > 0; i-=lowbit(x))
    {
        sum+=c[i];
    }
    return sum;
}

int update(int x,int v,int n){
    for (int i = x; i <= n; i+=lowbit(x))
    {
        c[i]+=v;
    }
}


int main(int argc, char const *argv[])
{
    a[1]=2;
    a[2]=5;
    a[3]=1;
    a[4]=3;
    a[5]=4;
    translate(5);
    for (int i = 1; i <= 5; i++)
    {
        cout<<c[i]<<" ";
    }
    
    
    return 0;
}
