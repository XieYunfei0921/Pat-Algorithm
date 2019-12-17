#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
struct Info{
    string id;
    int examId;
    void show(){
        std::cout << this->id<<" "<<this->examId << std::endl;
    }
};
const int MAXN=1000;
Info tab[MAXN];
int main(int argc, char const *argv[])
{
    int total,searchNum;
    cin>>total;
    string s[total];
    int a[total],b[total];
    for (int i = 0; i < total; i++)
    {
        cin>>s[i]>>a[i]>>b[i];
    }
    cin>>searchNum;
    int sr[searchNum];
    for (int i = 0; i < searchNum; i++)
    {
        cin>>sr[i];
    }
    for (int i = 0; i < total; i++)
    {
        tab[a[i]]={s[i],b[i]};
    }
    for (int i = 0; i < searchNum; i++)
    {
        tab[sr[i]].show();
    }
    return 0;
}
