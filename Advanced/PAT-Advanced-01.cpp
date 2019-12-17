#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int a,b,cnt=0;string s="";
    cin>>a>>b;
    bool flag=false;
    int sum=a+b;
    if(sum==0) {std::cout << 0 << std::endl;return 0;}
    if(sum<0) flag=true;
    while (sum!=0){
        if(cnt==3) {s+=",";cnt=0;}
        s+=abs(sum%10)+'0';
        cnt++;
        sum/=10;
    }
    if(flag) s+="-";
    reverse(s.begin(),s.end());
    std::cout << s << std::endl;
    return 0;
}
