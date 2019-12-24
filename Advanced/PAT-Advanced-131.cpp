#include <iostream>
#include <stdio.h>
using namespace std;
bool isPrime(int x){
    if(x==1) return false;
    for (int i = 2; i*i <= x; i++)
        if(x%i==0) return false;
    return true;
}
const int MAXN=10010;
int input[MAXN];
void insert(int x,int size){
    bool flag=false;
    for (int i = 0; i < size; i++){
        int pos=(x%size+i*i)%size;
        if(input[pos]==-1){
            input[pos]=x;
            flag=true;
            break;
        }
    }
    if(!flag) printf("%d cannot be inserted.\n", x);
}
int get(int x,int size){
    int temp=x%size;
    int cnt=1;
    int p=0;
    for (int i = 0; i < size; i++){
        if(input[(temp+p*p)%size]==x || input[(temp+p*p)%size]==-1) break;
        cnt++;
        p++;
    }
    return cnt;
}
int main(int argc, char const *argv[]){
    int size,n,m,pu,ge;
    cin>>size>>n>>m;
    fill(input,input+MAXN,-1);
    while (!isPrime(size)){
        size++;
    }
    for (int i = 0; i < n; i++){
        cin>>pu;
        insert(pu,size);
    }
    int sum=0;
    for (int i = 0; i < m; i++){
        cin>>ge;
        sum+=get(ge,size);
    }
    printf("%.1f",(float)sum/m);
    return 0;
}
