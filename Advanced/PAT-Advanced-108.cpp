#include <algorithm>
#include <cstdio>
using namespace std;
/*
    特殊情况非中间块，出现比中间块元素还要多的连续解
    10 8
    1 2 3 67 68 69 700 701 702 3200
    需要重新考虑，不使用暴力破解的情况下，既能够解决这个边界条件，又可以降低暴力破解时间复杂度的问题
*/
int main(int argc, char const *argv[])
{
    long long n,p;
    scanf("%lld %lld",&n,&p);
    long long arr[n];
    for (int i = 0; i < n; i++)
        scanf("%lld",&arr[i]);
    sort(arr,arr+n);
    int cnt=0,left=(n-1)/2,right=(n-1)/2;
    // 贪心，向右或是向左扩展都会使得条件不满足
    while (left<=right){
        // 不能左扩展
        if((left==0 || (left!=0 && arr[left-1]*p<arr[right])) &&
         (right==n-1 || (right!=n-1 && arr[left]*p<arr[right+1]))){
             cnt=right-left+1;
             break;
        }else {
            // 同时扩展
            if(left!=0) 
                left--;
            if(right!=n-1) 
                right++;
        }
    }
    if(arr[left]*p<arr[right]) cnt--;
    printf("%d",cnt);
    return 0;
}
