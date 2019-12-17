#include <iostream>
#include <algorithm>
using namespace std;
// 转字符串
string getComplete(string s){
    string temp="#000000";
    if(s.length()==7) return s;
    if(s.length()==2){
        for (int i = 1; i < temp.length(); i++)
            temp[i]=s[1];
        return temp;
    }
    if(s.length()==4){
        temp[0]=s[0];
        temp[2]=temp[1]=s[1];
        temp[4]=temp[3]=s[2];
        temp[6]=temp[5]=s[3];
        return temp;
    }
}
int main(int argc, char const *argv[]){
    int m,n,p,q;// 宽,高 小单元的宽,高
    cin>>m>>n>>p>>q;
    
    return 0;
}
