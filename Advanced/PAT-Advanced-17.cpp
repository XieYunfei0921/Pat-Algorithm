#include <iostream>
#include <algorithm>
using namespace std;

int main(int argc, char const *argv[])
{
    string s;int n1,n2,n3,minu=0;
    cin>>s;
    int n=s.length();
    n1=1;
    n2=n+2-2*n1;
    while (n1<=n2)
    {
        n1++;
        n2=n+2-2*n1;
    }
    n1--;
    n2=n+2-2*n1;
    for (int i = 0; i < n1-1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if(j==0) {cout<<s[i];continue;}
            if(j==n2-1) {cout<<s[s.length()-1-i];continue;}
            cout<<" ";
        }
        std::cout << "" << std::endl;
    }
    for (int i = 0; i < n2; i++)
        cout<<s[n1-1+i];
    return 0;
}
