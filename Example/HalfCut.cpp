#include <iostream>
#include <math.h>
#include <string>
#include <algorithm>
using namespace std;
typedef long long LL;

const int maxn=10010;
/*
    二分法:
    注意的细节:
        当left<=right时,点在右区域=[mid+1,right],左区域=[left,mid-1]
            假设 left=right=1
            mid=1
            但是1这个索引不存在,取0,则需要mid-1
        当left<right时,点在右区域=[mid+1,right],左区域=[left,mid]
             假设 left=1,right=2
             mid=1 存在这个索引,所以能够使用mid
*/

int halfSearch(int* arr,int len,int s){
    int mid,left=0,right=len;
    int index=-1;
    while (left<right)
    {
        mid=(left+right)/2;
        if(*(arr+mid)==s){
            index=mid;
            break;
        }
        else if(*(arr+mid)<s){
            left=mid+1;
        }
        else
        {
            right=mid;
        }
    }
    return index;
}

// 快速幂 
/*
    当b为奇数,a=a* a^(b-1)
    当b为偶数,a=a^b
*/
LL binaryPow(LL a,LL b,LL m){
    if (b==0)
        return 1;

    if (b%2==0){
        LL mul=binaryPow(a,b/2,m)%m;
        return mul*binaryPow(a,b/2,m)%m;
    }
    else
        return a*binaryPow(a,b-1,m)%m;
}

int main(int argc, char const *argv[])
{
    int arr[10]={1,3,5,6,7,8,9,12,15,21};
    // std::cout << "index= "<<halfSearch(arr,10,20) << std::endl;
    
    return 0;
}
