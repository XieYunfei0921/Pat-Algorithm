#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int tab[10001]={0};
int main(int argc, char const *argv[])
{
    int n,num;bool flag=true;
    vector<int> v1;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>num;
        v1.push_back(num);
        tab[num]++;
    }
    for (int i = 0; i < v1.size(); i++)
        if(tab[v1[i]]==1) {cout<<v1[i];flag=false;break;}
    if(flag) std::cout << "None" << std::endl;
    return 0;
}
