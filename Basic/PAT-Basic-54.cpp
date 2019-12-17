#include <iostream>
#include <math.h>
#include <algorithm>
using namespace std;
int rank[10001]={0};
bool flags[10001]={false};
void translate(string s,int num){
    int id=0;
    for (int i = s.length()-1; i >= 0; i--)
        id=id*10+s[i]-'0';
    rank[id]=num;
}
int search(string s){
    int id=0;
    for (int i = s.length()-1; i >= 0; i--)
        id=id*10+s[i]-'0';
    if(flags[id]==false && rank[id]!=0) {flags[id]=true;return rank[id];}
    if(rank[id]==0) return rank[id];
    else return -1;
}
bool isPrime(int num){
    for (int i = 2; i <= sqrt(num); i++)
        if(num%i==0) return false;
    return true;
}0
void show(string id,int rank){
    if(rank==-1) {std::cout << id<<": Checked"<< std::endl;return;}
    if(rank==0) {std::cout << id<<": Are you kidding?"<< std::endl;return;}
    if(rank==1) {std::cout << id<<": Mystery Award"<< std::endl;return;}
    if(isPrime(rank)) {std::cout << id<<": Minion" << std::endl;return;}
    std::cout << id<<": Chocolate" << std::endl;
}
int main(int argc, char const *argv[])
{
    int n,k;
    cin>>n;
    bool flags[n];
    for (int i = 0; i < n; i++){
        string s;
        cin>>s;
        translate(s,i+1);
    }
    cin>>k;
    for (int i = 0; i < k; i++)
    {
        string name;
        cin>>name;
        int ids=search(name);
        show(name,ids);
    }
    return 0;
}
