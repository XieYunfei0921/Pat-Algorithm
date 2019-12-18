#include <cstdio>
int mp[10100];
int m,n;
bool isPrime(int x){
    if(x==1) return false;
    for (int i = 2; i*i <= x; i++)
        if(x%i==0) return false;
    return true;
}
void insert(int key) {
    for(int step = 0; step < m; step++) {
        int index = (key + step * step) % m;
        if(mp[index] == 0) {
            mp[index] = 1;
            printf("%d",index % m);
            return ;
        }
    }
    printf("-");
}
int main(int argc, char const *argv[]){
    scanf("%d %d",&m,&n);
    while (!isPrime(m)){
        m++;
    }
    for (int i = 0; i < n; i++){
        int num;
        scanf("%d",&num);
        if(i!=0) printf(" ");
        insert(num);
    }
    return 0;
}
