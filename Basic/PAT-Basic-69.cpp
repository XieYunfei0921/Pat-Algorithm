#include <iostream>
#include <algorithm>
#include <math.h>
using namespace std;
int tab[30001]={0};
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    for (int i = 1; i <= n; i++)
    {
        int res=floor(i/2)+floor(i/3)+floor(i/5);
        tab[res]++;
    }
    int cnt=0;
    for (int i = 0; i < 30001; i++)
        if(tab[i]>0) cnt++;
    std::cout << cnt << std::endl;
    return 0;
}
