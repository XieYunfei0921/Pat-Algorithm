#include <iostream>
#include <algorithm>
#include <map>
#include <vector>
using namespace std;
int main(int argc, char const *argv[])
{   
    int m,n,s,cnt=0;
    cin>>m>>n>>s;
    string tab[m];
    map<string,bool> sta;
    vector<string> v;
    for (int i = 0; i < m; i++){
        cin>>tab[i];
        sta[tab[i]]=false;
    }
    for (int i = s-1; i < m; i+=n)
    {
        while (sta.find(tab[i])->second==true)
            i++;
        v.push_back(tab[i]);
        sta[tab[i]]=true;
        cnt++;
    }
    if(cnt==0){std::cout << "Keep going..." << std::endl;return 0;}
    for (int i = 0; i < v.size(); i++)
        std::cout << v[i] << std::endl;
    return 0;
}
