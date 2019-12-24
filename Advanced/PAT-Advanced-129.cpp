#include <iostream>
#include <algorithm>
using namespace std;
struct Node{
    string name;
    int high;
};
bool cmp(Node n1,Node n2){
    if(n1.high==n2.high) return n1.name<n2.name;
    return n1.high>n2.high;
}
void deal(Node arr[],int start,int len){
    string ids[len];
    int pl=len/2,pr=len/2;
    ids[len/2]=arr[start].name;
    int p=start+1;
    while (true){
        pl--;
        if(pl<0) break;
        ids[pl]=arr[p].name;
        p++;
        pr++;
        if(pr>=len) break;
        ids[pr]=arr[p].name;
        p++;
    }
    for (int i = 0; i < len; i++){
        if(i!=0) cout<<' ';
        cout<<ids[i];
    }
    cout<<"\n";
}
int main(int argc, char const *argv[]){
    int n,k,first,high,avg;
    string name;
    cin>>n>>k;
    Node arr[n];
    for (int i = 0; i < n; i++){
        cin>>name>>high;
        arr[i]={name,high};
    }
    sort(arr,arr+n,cmp);
    first=n/k+n%k;
    avg=n/k;
    deal(arr,0,first);
    int p=first;
    while (p<n){
        deal(arr,p,avg);
        p+=avg;
    }
    return 0;
}
