#include <iostream>
#include <stdio.h>
using namespace std;
int main(int argc, char const *argv[])
{   
    int n;
    cin>>n;
    float temp,sum=0.0;
    for (int i = 0; i < n; i++){
        cin>>temp;
        sum+=(i+1)*(n-i)*temp;
    }
    printf("%.2f",sum);
    return 0;
}
