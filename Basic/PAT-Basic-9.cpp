#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
bool table[100]={false};
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        cin>>arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        for (int j = i+1; j < n; j++)
        {
            int num1=arr[i]*10+arr[j];
            int num2=arr[j]*10+arr[i];
            if(table[num1]==false)
                table[num1]=true;
            if(table[num2]==false)
                table[num2]=true;
        }
    }
    int sum=0;
    for (int i = 0; i < 100; i++)
    {   
        if(table[i]==true){
            sum+=i;
        }
    }
    std::cout << sum << std::endl;
    
    return 0;
}
