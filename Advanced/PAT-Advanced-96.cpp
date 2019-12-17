#include <cstdio>
using namespace std;
// 需要进一步的降低时间复杂度
int containOne(int n){
    int num=0;
    while (n>0){
        if(n%10==1) num++;
        n/=10;
    }
    return num;
}
int main(int argc, char const *argv[]){
    int n;
    scanf("%d",&n);
    int cnt=0;
    for (int i = 1; i <=n; i++)
        cnt+=containOne(i);
    printf("%d",cnt);
    return 0;
}

