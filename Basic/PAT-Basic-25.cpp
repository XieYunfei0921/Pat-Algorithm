#include <iostream>
using namespace std;
int ta[3]={0};
int tb[3]={0};
int main(int argc, char const *argv[])
{
    int n,cntA=0,cntB=0;
    char a,b;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>a>>b;
        if(a=='C' && b=='J') {ta[1]++;cntA++;}
        if(a=='J' && b=='B') {ta[2]++;cntA++;}
        if(a=='B' && b=='C') {ta[0]++;cntA++;}
        if(b=='C' && a=='J') {tb[1]++;cntB++;}
        if(b=='J' && a=='B') {tb[2]++;cntB++;}
        if(b=='B' && a=='C') {tb[0]++;cntB++;}
    }
    int temp=0;
    temp=ta[0]>=ta[1]?0:1;
    int index1=ta[temp]>=ta[2]?temp:2;
    temp=tb[0]>=tb[1]?0:1;
    int index2=tb[temp]>=tb[2]?temp:2;
    char s[4]={"BCJ"};
    char ax=s[index1];
    char bx=s[index2];
    std::cout << cntA<<" "<<n-cntB-cntA<<" "<<cntB << std::endl;
    std::cout << cntB<<" "<<n-cntB-cntA<<" "<<cntA << std::endl;
    std::cout << ax<<" "<<bx << std::endl;
    return 0;
}
