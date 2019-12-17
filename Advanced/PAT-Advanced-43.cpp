#include <iostream>
#include <vector>
#include <set>
using namespace std;
int main(int argc, char const *argv[])
{
    int m,n,s;
    string w;
    cin>>m>>n>>s;
    vector<string> v;
    set<string> st;
    for (int i = 0; i < m; i++){
        cin>>w;
        v.push_back(w);
    }
    if(s>m){std::cout << "Keep going..." << std::endl;return 0;}
    int index=s-1;
    while (index<v.size())
    {   
        if(st.count(v[index])==0){
            std::cout << v[index] << std::endl;
            st.insert(v[index]);
            index+=n;
        }else{
            index++;
        }
    }
    return 0;
}
