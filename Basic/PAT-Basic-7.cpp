#include <iostream>
using namespace std;
/*
    注意:
     同时输赢进入下一轮,不需要喝酒
*/
int main(int argc, char const *argv[])
{
    int times,wona=0,wonb=0,fa,fb,da,db,sum=0;
    cin>>times;
    for (int i = 0; i < times; i++)
    {
        cin>>fa>>da>>fb>>db;
        sum=fa+fb;
        if(sum==da && sum!=db)
            wonb++;
        if(sum==db && sum!=da)
            wona++;
    }
    std::cout << wona<<" "<<wonb << std::endl;
    return 0;
}
