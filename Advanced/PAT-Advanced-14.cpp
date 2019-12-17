#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
/*
    扩展型的进制转换
*/
void translate(int x,int radix){
    vector<int> v;
    bool flag=true;
    while (x>0)
    {   
        v.push_back(x%radix);
        x/=radix;
    }
    reverse(v.begin(),v.end());
    int left=0,right=v.size()-1;
    while (left<=right)
    {
        if(v[left]!=v[right]){
            flag=false;
        } 
        left++;right--;
    }
    if(flag)
        std::cout << "Yes" << std::endl;
    else 
        std::cout << "No" << std::endl;
    for (int i = 0; i < v.size(); i++)
    {
        if(i==v.size()-1) cout<<v[i];
        else cout<<v[i]<<" ";
    }
}
int main(int argc, char const *argv[])
{
    int n,d;
    cin>>n>>d;
    translate(n,d);
    
    return 0;
}
