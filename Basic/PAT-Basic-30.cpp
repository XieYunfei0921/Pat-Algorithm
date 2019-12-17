#include <iostream>
#include <algorithm>
using namespace std;
void show(int n,char c){
    int k1,k2,other,temp,lines;
    for (int i = 1;; i+=2)
    {
        k1=2*(i+1)/2*(i+1)/2-1;
        k2=2*(i+3)/2*(i+3)/2-1;
        if(k1<=n && n<k2) {other=n-k1;temp=i;break;}
    }
    lines=2*(temp+1)/2-1;
    int deta=0;
    for (int i = 0; i < lines; i++)
    {
        for (int j = 0; j < temp; j++)
        {
            if(j>=deta && j<temp-deta) cout<<c;
            else cout<<" ";
        }
        std::cout <<"" << std::endl;
        if(i<lines/2) deta++;
        else deta--;
    }
    std::cout << other << std::endl;
    
}
int main(int argc, char const *argv[])
{
    int n;char c;
    cin>>n>>c;
    show(n,c);
    //  int N, row = 0;
    // char c;
    // cin >> N >> c;
    // for (int i = 0; i < N; i++) {
    //     if ((2 * i * (i + 2) + 1) > N) {
    //         row = i - 1;
    //         break;
    //     }
    // }
    // for (int i = row; i >= 1; i--) {
    //     for (int k = row - i; k >= 1; k--) cout << " ";
    //     for (int j = i * 2 + 1; j >= 1; j--) cout << c;
    //     cout << endl;
    // }
    // for (int i = 0; i < row; i++) cout << " ";
    // cout << c << endl;
    // for (int i = 1; i <= row; i++) {
    //     for (int k = row - i; k >= 1; k--) cout << " ";
    //     for (int j = i * 2 + 1; j >= 1; j--) cout << c;
    //     cout << endl;1
    // }
    // cout << (N - (2 * row * (row + 2) + 1));
    return 0;
}
