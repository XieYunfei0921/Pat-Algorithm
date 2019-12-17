#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <vector>
using namespace std;
const int MAXN=2000;
const int INF=1001;
int paras[MAXN];

/*
    总结: 将大问题拆解成小问题，通常节省时间空间
*/
void stand(){
    int a, b, flag = 0;
    while (cin >> a >> b) {
        if (b != 0) {
            if (flag == 1) cout << " ";
            cout << a * b << " " << b - 1;
            flag = 1;
        }
    }
    if (flag == 0) cout << "0 0";
}

int main(int argc, char const *argv[])
{
    fill(paras,paras+MAXN,INF);
    int temp;
    int cnt=0;
    vector<int> v;
    while (cin>>temp)
    {   
        paras[cnt]=temp;
        if(getchar()=='\n') break;
        cnt++;
    }
    if(cnt==0){
        std::cout << "0 0" << std::endl;
        return 0;
    }
    for (int i = 1; i <= cnt; i+=2)
    {   
        if(paras[i]!=0){
            v.push_back(paras[i]*paras[i-1]);
            v.push_back(paras[i]-1);
        }
    }
    for (int i = 0; i < v.size(); i++)
    {
        if(i==v.size()-1) cout<<v[i];
        else cout<<v[i]<<" ";
    }
    // stand();
    return 0;
}
