#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
struct Node{
    int val;
    int opts;
    int corrects;
    string ans;
    bool equal(string s){
        if(this->ans==s) return true;
        return false;
    }
};
string getStr(int num){
    string s="";
    while (num>0)
    {
        s+=num%10+'0';
        num/=10;
    }
    string s2="";
    reverse(s.begin(),s.end());
    s2+=s;
    s2+=" ";
    return s2;
}
int main(int argc, char const *argv[])
{
    int n,m,score,num,num2,correct;
    string ans="";
    string rep;
    cin>>n>>m;
    Node tab[m];
    int error[m]={0};
    int total[n]={0};
    for (int i = 0; i < m; i++)
    {   
        cin>>score>>num>>correct;
        for (int k = 0; k < correct; k++)
        {
            string temp;
            cin>>temp;
            ans+=temp;
            if(k!=correct-1)
                ans+=" ";
        }
        tab[i]={score,num,correct,ans};
        ans.clear();
    }
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        string info;
        getline(cin,info);
        for (int j = 0; j < m; j++)
        {
            int start=info.find('(')+3;
            int end=info.find(')')-1;
            string rep=info.substr(start,end-start+1);
            if(tab[j].equal(rep)) 
                total[i]+=tab[j].val;
            else
                error[j]++;
            info=info.substr(end+2,info.length()-end-1);
        }
    }
    for (int i = 0; i < n; i++)
        std::cout << total[i] << std::endl;
    
    int maxn=0;string output="";string tem;
    for (int i = 0; i < m; i++)
        if(error[i]>maxn) maxn=error[i];
    if(maxn==0) {std::cout << "Too simple" << std::endl;return 0;}
    std::cout <<maxn <<" " ;
    for (int i = 0; i < m; i++)
        if(maxn==error[i]) {tem=getStr(i+1);output.append(tem);}
    std::cout << output.substr(0,output.length()-1) << std::endl;
    return 0;
}
