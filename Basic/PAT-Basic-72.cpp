#include <iostream>
#include <cmath>
using namespace std;
int m,x,y;
void show(double cmp){
    if(m==cmp) cout<<" Ping";
    else if(m>cmp) cout<<" Gai";
    else cout<<" Cong";
}
/*
    第一个输出的是甲
*/
int main(int argc, char const *argv[])
{   
    cin>>m>>x>>y;
    for (int jia = 99; jia > 10; jia--){
        int yi=(jia%10)*10+jia/10;
        double bin=abs(jia-yi)*1.0/x;
        if(yi==bin*y){
            cout<<jia;
            show(jia);show(yi);show(bin);
            return 0;
        }
    }
    cout<<"No Solution";
    return 0;
}
