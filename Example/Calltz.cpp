#include <iostream>
#include <vector>
#include <set>
using namespace std;
vector<int> v;
void callatz(int n){
    if(n==1)
        return;
    if(n%2!=0) {
        n=(3*n+1)/2;
    }
    else{
        n/=2;
    }
    v.push_back(n);
    callatz(n);
}

int maxn=10010;
void keyNumber(int* arr,int len){
    bool hash[maxn]={false};
    for (int i = 0; i < len; i++)
    {
        if (hash[*(arr+i)]==false)
        {
            callatz(*(arr+i));
            for (int i = 0; i < v.size(); i++)
            {
                hash[v[i]]=true;
            }
        }
    }

    set<int> s;
    for (int i = 0; i < len; i++)
    {
        if (hash[*(arr+i)]==false)
            s.insert(*(arr+i));
    }

    for (set<int>::iterator i = s.begin(); i != s.end(); i++)
    {   
        std::cout << *i << " ";
    }
}
int main(int argc, char const *argv[])
{
    int arr[6]={3,5,6,7,8,11};
    keyNumber(arr,6);
    return 0;
}
