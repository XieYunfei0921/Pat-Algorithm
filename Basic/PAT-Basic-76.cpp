#include <iostream>
#include <algorithm>
using namespace std;
int translate(string s){
    int num=0;
    for (int i = 0; i < s.length(); i++)
        num=num*10+s[i]-'0';
    return num;
}
string toString(int num){
    string s="";
    s+=num/1000+'0';
    s+=num%1000/100+'0';
    s+=num%100/10+'0';
    s+=num%10+'0';
    return s;
}
char maxn[4];
void sack(string s){
    string sa="",sb="";
    string ans;
    for (int i = 0; i < 4; i++)
        maxn[i]=s[i];
    sort(maxn,maxn+4);
    for (int i = 0; i < 4; i++)
    {   
        sa+=maxn[i];
        sb+=maxn[3-i];
    }
    int a=translate(sa);
    int b=translate(sb);
    ans= toString(b-a);
    std::cout << sb<<" - "<<sa<<" = "<<ans << std::endl;
    if(ans=="6174") return;
    sack(ans);
}
int main(int argc, char const *argv[])
{
    string start;
    cin>>start;
    if(start[0]==start[1] && start[1]==start[2] && start[2]==start[3] && start[3]==start[0]){
            std::cout << start<<" - "<<start<<" = "<<"0000" << std::endl;
            return 0;
    }
    string s=toString(translate(start));
    sack(s);
    return 0;
}
