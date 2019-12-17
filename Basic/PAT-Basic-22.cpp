#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <math.h>
using namespace std;

void dealArray(int data[],int n){
    int A1=0,A2=0,A3=0,A5=0;
    int A4=0;
    int sign=1,num1=0,num2=0,num3=0,num4=0,num5=0;
    for (int i = 0; i < n; i++)
    {
        if(data[i]%10==0) {A1+=data[i];num1++;}
        if(data[i]%5==1) {A2+=sign*data[i];sign=-sign;num2++;}
        if(data[i]%5==2) {A3+=1;num3++;};
        if(data[i]%5==3) {A4+=data[i];num4++;}
        if(data[i]%5==4 && A5<data[i]) {A5=data[i],num5++;}  
    }
    num1==0?printf("N "):printf("%d ",A1);
    num2==0?printf("N "):printf("%d ",A2);
    num3==0?printf("N "):printf("%d ",A3);
    num4<2?printf("N "):printf("%.1f ",(double)A4/num4);
    num5<2?printf("N"):printf("%d",A5);
}

int main(int argc, char const *argv[])
{   
    // int n;
    // cin>>n;
    // int arr[n];
    // for (int i = 0; i < n; i++)
    //     cin>>arr[i];
    // int arr[9]={8,1,2,4,5,6,7,9,16};   
    int arr[14]={13,1,2,3,4,5,6,7,8,9,10,20,16,18};
    dealArray(arr,14);
    return 0;
}
