#include <cstdio>
#include <iostream>
#include <set>
using namespace std;
int main(int argc, char const *argv[])
{
    string s="sandee";
    if(s.find(" ")==string::npos)
        std::cout << "True" << std::endl;
    else
        std::cout << "False" << std::endl;
    return 0;
}
