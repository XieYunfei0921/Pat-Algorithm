#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

void multiply(int x,int y){
    int res=x*y;
    vector<int> q;
    while (res>0)
    {
        q.push_back(res%10);
        res/=10;
    }
    int sum=0;
    for (int i =0; i <q.size(); i++)
    {
        sum=sum*10+q[i];
    }
    std::cout << sum << std::endl;
}

int main(int argc, char const *argv[])
{   
    int x,y;
    cin>>x>>y;
    multiply(x,y);
    return 0;
}
