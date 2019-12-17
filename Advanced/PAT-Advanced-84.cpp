#include <iostream>
#include <algorithm>
using namespace std;
int main(int argc, char const *argv[]){
    int n;
    cin>>n;
    int info[n];
    for (int i = 0; i < n; i++)
        cin>>info[i];
    sort(info,info+n);
    float len=(float)info[0]/2+(float)info[1]/2;
    for (int i = 2; i < n; i++){
        len=len/2+(float)info[i]/2;
    }
    std::cout << (int)len;
    return 0;
}
