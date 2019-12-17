#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int tab[n]={0};
    for (int i = 0; i < n; i++)
    {
        int num;
        cin>>num;
        tab[abs(num-i-1)]++;
    }
    for (int i = n-1; i >=0; i--)
        if(tab[i]>1) std::cout << i<<" "<<tab[i] << std::endl;
    return 0;
}
