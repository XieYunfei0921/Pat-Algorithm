#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,cur,last=0,time=0;
    cin>>n;
    for (int i = 0; i < n; i++)
    {
        cin>>cur;
        time+=cur>last?6*(cur-last):4*(last-cur);
        time+=5;
        last=cur;
    }
    std::cout << time << std::endl;
    return 0;
}
