#include <cstdio>
#include <map>
#include <vector>
#include <cmath>
using namespace std;
struct Node{
    int factor;
    int num;
    void show(){
        if(this->num>1) printf("%d^%d",this->factor,this->num);
        else printf("%d",this->factor);
    }
};
map<int,int> mp;
vector<Node> list;
bool isPrime(long long n){
    if(n<=1) return false;
    for (int i = 2; i <=sqrt(n); i++){
        if(n%i==0) return false;
    }
    return true;
}
void prime_list(long long x){
    for (int i = 1; i <= x; i++)
        if(isPrime(i)) list.push_back(Node{i,0});
}
int main(int argc, char const *argv[]){
    long long n,temp;
    scanf("%lld",&n);
    if(n==1){
        printf("1=1");
        return 0;
    }
    if(isPrime(n)){printf("%d=",n);printf("%d",n);return 0;}
    temp=n;
    long long x=sqrt(n);
    prime_list(x);
    int p=0,index=-1;
    while (p<list.size()){
        if(n%list[p].factor==0){
            list[p].num++;
            index=p;
            n/=list[p].factor;
        }
        else
            p++;
    }
    printf("%d=",temp);
    for (int i = 0; i < list.size(); i++){
        if(list[i].num!=0) {
            list[i].show();
            if(i!=index)
                printf("*");
        }
    }
    return 0;
}
