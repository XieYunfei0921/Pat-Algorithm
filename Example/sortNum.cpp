#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
const int maxn=10010;
using namespace std;

/*
    归并排序:
    1. 将序列两两组(n/2)
    2. 组内单独排序
    3. 合并相邻的两组(n/4)
    4. 迭代

    实现思路:
    设置步长为2,对每组元素排序
    步长翻倍,对每组元素排序
    ...
    迭代到步长除以2>n截至
    排序之后合并这两个数组(两个数组分别是有序数组)
*/
// L1<R1,L2<R2且[L1,R1],[L2,R2]递增且L2=R1+1
/*
    使用双指针的思想,左指针指向L1,右指针指向L2

    比较左右指针所在处值的大小,放到新数组,直到把某个数组的元素取完毕
    将另一个数组剩下元素取过来
    返回新数组
*/
// 合并两个有序的数组
void merge(int* arr,int L1,int R1,int L2,int R2){
    int res[maxn];
    int i=L1,j=L2,k=0;
    while (i<=R1 && j<=R2)
    {
        // std::cout << "putting numbers...: "<< *(arr+i)<<"\t"<<*(arr+j)<< std::endl;
        if (*(arr+i)<*(arr+j))
        {
            res[k]=*(arr+i);
            i++;
        }else
        {
            res[k]=*(arr+j);
            j++;
        }
        k++;
    }
    // std::cout << "Merge Para: "<<"L1= "<<L1<<"  R1= "<<R1<<"  L2= "<<L2<<"  R2="<<R2<<" i= "<<i<<" j= "<<j<<" k= "<<k << std::endl;
    while (i<=R1)
    {
        res[k]=*(arr+i);
        i++;
        k++;
    }

    while (j<=R2)
    {
        res[k]=*(arr+j);
        j++;
        k++;
    }
    
    for (int i = 0; i < k; i++)
    {
        // std::cout << "res[i]= "<<res[i] << std::endl;
        *(arr+L1+i)=*(res+i);
    }
    
}

// 设定步长,数组排序
void mergeSort(int* arr,int len){

    for (int step = 2; step/2 < len; step*=2)
    {
        //  std::cout << "step= "<<step << std::endl;
        for (int i = 0; i <= len; i+=step)
        {
            // 合并子数组
            int mid=i+step/2-1;
            if (mid+1<=len)
            {
                merge(arr,i,mid,mid+1,min(i+step-1,len));
            }
        }
    }
}

/*
    快速排序原理:
        特例: 三个数排列 ,左边的数<中间的数<右边的数
        现在扩展到普遍场景
        左边的区间<中间的数<右边的区间
        TODO 如何将小于中间数的元素移到
        也可以想成如何将一个数移到所谓的中间
        方法:   Two Point
        左指针指向0,有指针指向len
        中间数的index=temp<=a[right] && temp >= a[left]
        当左右指针相交时取index
*/
int searchIndex(int* arr, int len){
    int index=0,temp=0;
    int left=0,right=len;
    temp=*(arr+left);
    while (left<right)
    {
        // 右指针左移动条件a[right]>temp
        while (*(arr+right)>temp && left<right)
        {
            right--;
        }
        *(arr+left)=*(arr+right);
        while (*(arr+left)<=temp && left<right)
        {
            left++;
        }
        *(arr+right)=*(arr+left);
    }
    *(arr+left)=temp;
    // 考虑到区间长度为零，返回0
    return left;
}
void quickSort(int* arr,int len){

    // 对输入数组的三个部分进行排序
    // 求中间数的索引
    if (len<1)
        return;
    int pos=searchIndex(arr,len);
    // std::cout << "Parameters:\tlen= "<<len<<"\tpos= "<<pos << std::endl;
    // 终止条件 : 左右区间都排序完成
    // 左区间排序 条件左区间长度大于1
    if (pos>1){
        std::cout << "left side sort:\tlen= "<<pos<<"\n";
        for (int i = 0; i <= pos-1; i++)
        {
            cout<<*(arr+i)<<" ";
        }
        std::cout << "\n-----------" << std::endl;
        quickSort(arr,pos-1);
    }
    // 右区间排序
    // len-pos-1
    if(len-pos>1){
        std::cout << "right side sort:\tlen= "<<len-pos-1<<"\n";
        for (int i = pos+1; i <len; i++)
        {
            cout<<*(arr+i)<<" ";
        }
        std::cout << "\n-----------" << std::endl;
        
        quickSort(arr+pos+1,len-pos-1);
    }
}

int main(int argc, char const *argv[]){
    
    int a[10]={1,4,5,6,2,7,-4,6,-2,11};
    // mergeSort(a,10);
    // std::cout <<"" << std::endl;
    // for (int i = 0; i < 10; i++)
    // {
    //     cout<<a[i]<<" ";
    // }
    quickSort(a,10);
    for (int i = 0; i < 10; i++)
    {
        cout<<a[i]<<" ";
    }
    
}