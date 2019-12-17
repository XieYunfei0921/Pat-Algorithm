#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    int minu=10001,maxn=0;
    string maxName,minName;
    for (int i = 0; i < n; i++)
    {
        string id;int x,y;
        cin>>id>>x>>y;
        if(x*x+y*y>maxn){
            maxName=id;
            maxn=x*x+y*y;
        }
        if(x*x+y*y<minu){
            minName=id;
            minu=x*x+y*y;
        }
    }
    std::cout << minName<<" "<<maxName << std::endl;
    return 0;
}
