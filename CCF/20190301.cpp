#include <iostream>
using namespace std;
int main(){
	int n,maxn=0,minu=0,middle=0;
	scanf("%d",&n);
	int arr[n];
	for(int i=0;i<n;i++) scanf("%d",&arr[i]);
	maxn=arr[n-1]>arr[0]?arr[n-1]:arr[0];
	minu=arr[n-1]>arr[0]?arr[0]:arr[n-1];
	if(n%2!=0)
		printf("%d %d %d",maxn,arr[(n-1)/2],minu);
	else if((arr[(n-1)/2]+arr[n/2])%2==0)
		printf("%d %d %d",maxn,(arr[(n-1)/2]+arr[n/2])/2,minu);
	else
		printf("%d %.1f %d",maxn,(float)(arr[(n-1)/2]+arr[n/2])/2,minu);
} 
