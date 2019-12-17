#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int getReverse(int x,int radix){
    int val=0;
    string s="";
    while (x>0)
    {
        s+=x%radix+'0';
        x/=radix;
    }
    for (int i = 0; i < s.length(); i++)
        val=val*radix+s[i]-'0';
    return val;
}
bool isLegal(int n){
    if(n <= 1) return false;
    int sqr = int(sqrt(n * 1.0));
    for(int i = 2; i <= sqr; i++) {
        if(n % i == 0)
            return false;
    }
    return true;
}
int main(int argc, char const *argv[])
{
    int num,radix;
    while (true)
    {
        cin>>num;
        if(num>=0){
            cin>>radix;
            if(!isLegal(num)) {
                std::cout << "No" << std::endl;
                continue;
            }else
            {
                int t=getReverse(num,radix);
                if(isLegal(t))
                    std::cout << "Yes" << std::endl;
                else
                    std::cout << "No" << std::endl;
            }
            
        }
        else
            break;
    }
    return 0;
}
