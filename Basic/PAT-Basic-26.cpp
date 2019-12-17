#include <iostream>
using namespace std;
const int MAXN=1000;
int table[MAXN]={0};
void translate(int a,int b,int d){
    long long c=a+b;
    if(c==0) {std::cout << "0";return;}
    int index=0;
    while (c>0)
    {   
        table[index]=c%d;
        c/=d;
        index++;
    }
    for (int i = index-1; i >=0; i--)
        cout<<table[i];
}
int main(int argc, char const *argv[])
{   
    int a,b,d;
    cin>>a>>b>>d;
    translate(a,b,d);
    return 0;
}
