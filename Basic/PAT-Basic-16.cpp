#include <iostream>
#include <algorithm>
using namespace std;

void judge(int x){
    bool flag=false;
    for (int i = 1; i < 10; i++)
    {
        int num=i*x*x;
        int tempX=x;
        int tempNum=num;
        while (tempX>0)
        {
            if(tempX%10!=tempNum%10)
                break;
            tempX/=10;
            tempNum/=10;
            if(tempX==0){
                flag=true;
                std::cout << i<<" "<<num << std::endl;
                return;
            }
        }
    }
    if(!flag) std::cout << "No" << std::endl;
    
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int x,sc;
    for (int i = 0; i < n; i++)
    {
        cin>>x;
        sc=x;
        judge(x);
    }
    return 0;
}
