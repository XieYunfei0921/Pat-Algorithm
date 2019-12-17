#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
int tab[10]={0};
string stoi(int n){
    string s="";
    while (n>0)
    {
        s+=n%10+'0';
        n/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}
struct Node{
    int val;
    int num;
    string getResult(){
        string s="";
        s+=this->val+'0';
        s+=stoi(this->num);
        return s;
    }
};
int getNewNumber(int last){
    vector<Node> v;
    int mid=last;
    while (mid>0)
    {
        tab[mid%10]++;
        mid/=10;
    }
    while (last>0)
    {
        Node node={last%10,tab[last%10]};
        v.push_back(node);
        last/=10;
    }
    string s="";
    for (int i = v.size()-1; i >=0; i--)
    {
        s+=v[i].getResult();
    }
    int res=0;
    for (int i = 0; i < s.length(); i++)
        res=res*10+s[i]-'0';
    return res;
}
int getDescription(int first,int n){
    if(n==1) return first;
    else{
       int last=getDescription(first,n-1); 
       for (int i = 0; i < 10; i++)
            tab[i]=0;
       int res=getNewNumber(last);
       std::cout << "res= "<<res << std::endl; 
       return res;
    }
}
int main(int argc, char const *argv[])
{
    int d,n;
    cin>>d>>n;
    int res=getDescription(d,n);
    std::cout << res << std::endl;
    return 0;
}
