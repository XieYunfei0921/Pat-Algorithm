#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;double len=0.0;
    cin>>n;
    int info[n];
    for (int i = 0; i < n; i++)
        cin>>info[i];
    sort(info,info+n);
    len=(double)info[0];
    for (int i = 1; i < n; i++)
        len=len/2+(double)info[i]/2;
    std::cout << (int)len << std::endl;
    return 0;
}
