#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

// 一步插入 前k+1个元素有序
void insertByStep(int data[],int k,int n){
    int temp=data[k+1];
    int index=-1;
    if(temp>=data[k]) return;
    for (int i = k; i >= 0; i--)
    {   
        if(temp>=data[i]){
            data[i+1]=temp;
            break;
        }
        if(temp<data[i]){
           data[i+1]=data[i];
           if(i==0) data[0]=temp;
        }
    }
}

void mergeByStep(int data[],int step,int n){
    int len=pow(2,step);
    int compactLength=2*len;
    int start=0;
    while (start<=n && start+compactLength<=n)
    {   
        sort(data+start,data+start+compactLength); 
        start+=compactLength;
    }
    if(n>start)
        sort(data+start,data+n);
}

int main(int argc, char const *argv[])
{   
    int n;
    cin>>n;
    int init[n],mid[n],next[n],ano[n];
    for (int i = 0; i < n; i++)
        cin>>init[i];
    for (int i = 0; i < n; i++)
        cin>>mid[i];
    for (int i = 0; i < n; i++)
        ano[i]=init[i];
    bool flag1=true,flag2=true;
    int cnt1=0,cnt2=0;
    while (cnt1<=n)
    {   
        insertByStep(init,cnt1++,n);
        for (int i = 0; i < n; i++)
            if(init[i]!=mid[i]) {flag1=false;continue;}
        if(flag1){
            std::cout << "Insertion Sort" << std::endl;
            insertByStep(init,cnt1,n);
            for (int i = 0; i < n; i++)
            {
                if(i!=n-1) cout<<init[i]<<" ";
                else cout<<init[i];
            }
            return 0;
        }else
        {
            flag1=true;
        }
    }
    while (cnt2<=n)
    {   
        mergeByStep(ano,cnt2++,n);
        for (int i = 0; i < n; i++)
            if(ano[i]!=mid[i]) {flag2=false;continue;}
        if(flag2){
            std::cout << "Merge Sort" << std::endl;
            mergeByStep(ano,cnt2,n);
            for (int i = 0; i < n; i++)
            {
                if(i!=n-1) cout<<ano[i]<<" ";
                else cout<<ano[i];
            }
            return 0;
        }else
        {
            flag2=true;
        }
    }
 
    return 0;
}
