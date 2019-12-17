#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[]){
    int n,m;
    cin>>n;
    // 设置统计数组
    bool drop[n+2]={false};
    int sum=0;
    for (int i = 0; i < n; i++){
        cin>>m;
        int num[m];
        cin>>num[0];
        int rest=num[0];
        // m是数的编号
        for (int j = 1; j < m; j++){
            cin>>num[j];
            if(num[j]>0){
                if(num[j]<rest){
                    drop[i+1]=true;
                    rest=num[j];
                } 
            }else if(num[j]<=0){
                rest+=num[j];
            }
        }
        sum+=rest;
    }
    drop[n+1]=drop[1];
    drop[0]=drop[n];
    int con=0,drops=0;
    for (int i = 1; i <= n; i++){
        if(drop[i]==true)
            drops++;
        if(drop[i]==true && drop[i-1]==true && drop[i+1]==true)
            con++;
    }
    cout<<sum<<" "<<drops<<" "<<con;
    return 0;
}
