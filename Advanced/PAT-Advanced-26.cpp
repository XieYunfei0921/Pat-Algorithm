#include <iostream>
#include <algorithm>
using namespace std;
string sub(string s1,string s2){
    int num1=0,num2=0,num;
    string s="";
    for (int i = 0; i < s1.length(); i++)
        num1=num1*10+s1[i]-'0';
    for (int i = 0; i < s2.length(); i++)
        num2=num2*10+s2[i]-'0';
    num=num1-num2;
    s+=num/1000+'0';
    s+=num%1000/100+'0';
    s+=num%100/10+'0';
    s+=num%10+'0';
    return s;
}

int main(int argc, char const *argv[])
{
    int n;string s="",temp1,temp2;
    cin>>n;
    if(n%1111==0){
        cout<<n<<" - "<<n<<" = "<<"0000";
        return 0;
    }
    if(n==6174){
        std::cout << "7641 - 1467 = 6147" << std::endl;
        return 0;
    }
    s+=n/1000+'0';
    s+=n%1000/100+'0';
    s+=n%100/10+'0';
    s+=n%10+'0';
    while (s!="6174")
    {
        sort(s.begin(),s.end());
        temp1=s;
        reverse(s.begin(),s.end());
        temp2=s;
        cout<<temp2<<" - "<<temp1<<" = "<<sub(temp2,temp1)<<"\n";
        s=sub(temp2,temp1);
    }
    return 0;
}
