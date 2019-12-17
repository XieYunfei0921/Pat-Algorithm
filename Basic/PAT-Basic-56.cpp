#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    string org;int n,cnt=0;
    cin>>org;
    cin>>n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string s;
        getline(cin,s);
        if(org==s){std::cout << "Welcome in" << std::endl;return 0;}
        if(s=="#"){return 0;}
        else{std::cout << "Wrong password: "<<s << std::endl;continue;}
    }
    std::cout << "Account locked" << std::endl;
    return 0;
}
