#include <iostream>
#include <string>
using namespace std;

// PAT 乙级

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int hun=n/100;
    int ten=n%100/10;
    int sig=n%10;
    for (int i = 0; i < hun; i++)
    {
        cout<<"B";
    }
    for (int i = 0; i < ten; i++)
    {
        cout<<"S";
    }
    if(sig!=0){
        for (int i = 1; i <= sig; i++)  
        {
            std::cout << i;
        }
    }
    return 0;
}
