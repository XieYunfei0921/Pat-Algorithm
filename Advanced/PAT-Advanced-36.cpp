#include <iostream>
#include <set>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,x,cnt=0;
    set<int> s;
    cin>>n;
    for (int i = 0; i < n; i++){
        cin>>x;
        if(x>0) s.insert(x);
    }
    while (true)
    {
        cnt++;
        if(s.count(cnt)==0) {std::cout << cnt << std::endl;break;}
    }
    return 0;
}
