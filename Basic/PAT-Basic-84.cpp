#include <iostream>
#include <algorithm>
#include <set>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,m;bool flag;
    cin>>n>>m;
    set<string> s;string temp="";
    for (int i = 0; i < n; i++)
    {
        string sa,sb;
        cin>>sa>>sb;
        if(sa>sb) {temp+=sb;temp+=sa;}
        else {temp+=sa;temp+=sb;}
        s.insert(temp);
        temp.clear();
    }
    for (int i = 0; i < m; i++)
    {
        int total;
        cin>>total;
        string arr[total];
        string sn="";
        for (int i = 0; i < total; i++)
            cin>>arr[i];
        flag=true;
        int left=0,right=1;
        if(total==1) {std::cout << "Yes" << std::endl;return 0;}
        while (!(right>=(total-1) &&left>=(total-1)))
        {
            if(arr[left]>arr[right]) {sn+=arr[right];sn+=arr[left];}
            else {sn+=arr[left];sn+=arr[right];}
            if(s.count(sn)==1) {flag=false;break;}
            if(right!=(total-1)) right++;
            else {left++;right=left+1;}
            sn.clear();
        }
        if(flag) std::cout << "Yes" << std::endl;
        else std::cout << "No" << std::endl;
    }
    return 0;
}
