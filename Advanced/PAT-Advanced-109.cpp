#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
using namespace std;
bool insertByStep(int arr[],int p,int pos[],int n){
    int temp=arr[p];
    int index=-1;
    for (int i = p-1; i >=0; i--){
        if(arr[i]>temp){
            arr[i+1]=arr[i];
            if(i==0)
                arr[0]=temp;
        }
        else{
            arr[i+1]=temp;
            break;
        }
    }
    for (int i = 0; i < n; i++)
        if(pos[i]!=arr[i]) return false;
    return true;
}
void merge(int arr[],int x1,int x2,int end1,int end2,int n){
    int p1=x1,p2=x2;
    int start=x1;
    int tab[n];
    while (p1<=end1 && p2<=end2){
        if(arr[p1]<arr[p2]){
            tab[start]=arr[p1];
            p1++;
        }else{
            tab[start]=arr[p2];
            p2++;
        }
        start++;
    }
    while(p1<=end1){tab[start]=arr[p1];p1++;start++;}
    while(p2<=end2){tab[start]=arr[p2];p2++;start++;}
    for (int i = x1; i <= end2; i++)
        arr[i]=tab[i];
}
bool mergeByStep(int arr[],int step,int pos[],int n){
    vector<int> v;
    int start=0;
    int intval=pow(2,step-1);
    while (start<n){
        v.push_back(start);
        start+=intval;
    }
    for (int i = 0; i < v.size(); i+=2){
        // 存在下一组 则需要参与重排
        if(i+1<v.size()){
            int end2=0;
            if(v[i+1]+intval>=n) end2=n-1;
            else end2=v[i+2]-1; 
            // cout<<"x1= "<<v[i]<<"\tx2= "<<v[i+1]<<"\tend1= "<<v[i+1]-1<<"\tend2= "<<end2<<"\n";
            merge(arr,v[i],v[i+1],v[i+1]-1,end2,n);
        }
    }
    v.clear();
    for (int i = 0; i < n; i++)
        if(arr[i]!=pos[i]) return false;
    return true;
}
int main(int argc, char const *argv[]){
    int n;
    scanf("%d",&n);
    int arr[n],pos[n],arr2[n];
    for (int i = 0; i < n; i++){
        scanf("%d",&arr[i]);
        arr2[i]=arr[i];
    }
    for (int i = 0; i < n; i++)
        scanf("%d",&pos[i]);
    int step=1;
    while (step<n){
        if(insertByStep(arr,step,pos,n)){
            printf("Insertion Sort\n");
            insertByStep(arr,step+1,pos,n);
            printf("%d",arr[0]);
            for (int i = 1; i < n; i++)
                printf(" %d",arr[i]);
            printf("\n");
            return 0;
        }
        if(mergeByStep(arr2,step,pos,n)){
            printf("Merge Sort\n");
            mergeByStep(arr2,step+1,pos,n);
            printf("%d",arr2[0]);
            for (int i = 1; i < n; i++)
                printf(" %d",arr2[i]);
            printf("\n");
            return 0;
        }
        step++;
    }
    
    return 0;
}
