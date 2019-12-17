#include <iostream>
#include <algorithm>
#include <math.h>
#include <string>
using namespace std;

void checkPwd(string s){
    if(s.length()<6){
        std::cout << "Your password is tai duan le." << std::endl;
        return;
    }
    int nums=0;
    int chars=0;
    for (int i = 0; i < s.length(); i++)
    {
        if(!((s[i]<='9' && s[i]>='0') || ('a'<=s[i] && s[i]<='z') || ('A'<=s[i] && s[i]<='Z') || s[i]=='.')){
            std::cout << "Your password is tai luan le." << std::endl;
            return;
        }
        if(s[i]<='9' && s[i]>='0'){
            nums++;
        }
        if(('a'<=s[i] && s[i]<='z') || ('A'<=s[i] && s[i]<='Z')){
            chars++;
        }
    }
    std::cout << "nums= "<<nums<<"\tchars= "<<chars << std::endl;
    if(nums==0){
        std::cout << "Your password needs shu zi." << std::endl;
        return;
    }
    if(chars==0){
        std::cout << "Your password needs zi mu." << std::endl;
        return;
    } 
    std::cout << "Your password is wan mei." << std::endl;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    cin.ignore();
    string s[n];
    for (int i = 0; i < n; i++)
    {
        getline(cin,s[i]);
    }
    for (int i = 0; i < n; i++)
    {
        checkPwd(s[i]);
    }
    
    return 0;
}
