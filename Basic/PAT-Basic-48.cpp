#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
// 截取的是任意连续位置的数 采用双指针法求和
/*
    左指针指向求和起始项,右指针指向求和结束项
    那么有
    sum(left,right)=sum(left,right-1)+a[right]
    可以推出
    sum(left,end)=(end-left+1)*a[left]+(end-(left+1)+1)*a[left+1]+...+a[end]
    继续降低复杂度

*/
int main(int argc, char const *argv[])
{
    int n;double sum=0.0;
    cin>>n;
    double arr[n];int end=n-1;
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    for (int left = 0; left < n; left++)
        sum+=arr[left]*(end-left+1)*(left+1);
    printf("%.2f",sum);
    return 0;
}
