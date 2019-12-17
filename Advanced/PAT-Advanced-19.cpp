#include <iostream>
#include <algorithm>
using namespace std;
int order[55];
int cards[55];
int mid[55];
string toString(int n){
    string s="";
    while (n>0)
    {
        s+=n%10+'0';
        n/=10;
    }
    reverse(s.begin(),s.end());
    return s;
}
string getCard(int n){
    if(n==53) return "J1";
    if(n==54) return "J2";
    if(n<=13 && n>=1)
        return "S"+toString(n);
    if(n<=26 && n>=14)
        return "H"+toString(n-13);
    if(n<=39 && n>=27)
        return "C"+toString(n-26);
    if(n<=52 && n>=40)
        return "D"+toString(n-39);
}
void init(){
    for (int i = 1; i < 55; i++)
        cards[i]=i;
}
void exchange(){
    for (int i = 1; i < 55; i++)
        mid[order[i]]=cards[i];
    for (int i = 1; i < 55; i++)
        cards[i]=mid[i];
}
int main(int argc, char const *argv[])
{
    int k,index=1,id;
    init();
    cin>>k;
    while (cin>>id || index==54)
    {
        order[index]=id;
        index++;
    }
    while (k>0)
    {
        exchange();
        k--;
    }
    
    for (int i = 1; i < 55; i++)
    {
        if(i==54) cout<<getCard(cards[i]);
        else cout<<getCard(cards[i])<<" ";
    }
    
    return 0;
}
