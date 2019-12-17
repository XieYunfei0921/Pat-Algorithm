#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;

void moveStep(int data[],int n){
    int temp=data[n-1];
    for (int i = n-1; i >0; i--)
        data[i]=data[i-1];
    data[0]=temp;
}
void move(int data[],int n,int m){
    int num=m%n;
    for (int i = 0; i < num; i++)
        moveStep(data,n);

    for (int i = 0; i < n; i++)
    {
        if(i==n-1) cout<<data[i];
        else cout<<data[i]<<" ";
    }
}

int main(int argc, char const *argv[])
{   
    int n,m;
    cin>>n>>m;
    int arr[n];
    for (int i = 0; i < n; i++)
        cin>>arr[i];
    move(arr,n,m);
    return 0;
}
