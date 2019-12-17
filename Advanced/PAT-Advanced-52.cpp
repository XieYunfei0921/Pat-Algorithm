#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,m;long long x;
    vector<long long> v;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>x;
        v.push_back(x);
    }
    cin>>m;
    for (int i = 0; i < m; i++)
    {
        cin>>x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    std::cout << v[(v.size()-1)/2] << std::endl;
    return 0;
}
