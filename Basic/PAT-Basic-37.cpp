#include <iostream>
#include <algorithm>
using namespace std;

/*
    注意n=1的边界条件
*/
int main(int argc, char const *argv[])
{
    int n,id,score;
    cin>>n;
    int table[n+1]={0};
    for (int i = 0; i < n; i++)
    {
        cin>>id>>score;
        if(n==1) {std::cout << 1<<score << std::endl;return;}
        table[id]+=score;
    }
    int maxn=0,index=-1;
    for (int i = 0; i < n; i++)
    {   
        if(table[i]>maxn){
            maxn=table[i];
            index=i;
        }
    }
    std::cout << index<<" "<<maxn << std::endl;
    return 0;
}
