#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    float W,T,L,sum=1,maxm;
    string s;
    for (int i = 0; i < 3; i++)
    {
        cin>>W>>T>>L;
        maxm=max(max(W,T),L);
        sum*=maxm;
        s=maxm==W?"W":maxm==T?"T":"L";
        std::cout <<s <<" ";
    }
    printf("%.2f",(sum*0.65-1)*2);
    return 0;
}
