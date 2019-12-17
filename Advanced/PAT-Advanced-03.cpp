#include <iostream>
#include <algorithm>
using namespace std;
string selector(int x){
    string s;
    switch (x)
    {
        case 0: s="zero";break;
        case 1: s="one";break; 
        case 2: s="two";break;
        case 3: s="three";break;
        case 4: s="four";break;
        case 5: s="five";break;
        case 6: s="six";break;
        case 7: s="seven";break;
        case 8: s="eight";break;
        case 9: s="nine";break;
    }
    return s;
}
int main(int argc, char const *argv[])
{
    string n;
    cin>>n;
    int sum=0;bool flag=false;
    for (int i = 0; i < n.length(); i++)
        sum+=n[i]-'0';
    
    if(sum/100!=0){
        cout<<selector(sum/100)<<" ";
        cout<<selector(sum%100/10)<<" ";
        std::cout << selector(sum%10) << std::endl;
    }else
    {
        if(sum%100/10!=0){
            cout<<selector(sum%100/10)<<" ";
            std::cout << selector(sum%10) << std::endl;
        }else{
            std::cout << selector(sum%10) << std::endl;
        } 
    }
    return 0;
}
