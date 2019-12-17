#include <iostream>
#include <algorithm>
using namespace std;
char getBit(int n){
    char c;
    switch (n)
    {
        case 0:c='0';break;
        case 1:c='1';break;
        case 2:c='2';break;
        case 3:c='3';break;
        case 4:c='4';break;
        case 5:c='5';break;
        case 6:c='6';break;
        case 7:c='7';break;
        case 8:c='8';break;
        case 9:c='9';break;
        case 10:c='A';break;
        case 11:c='B';break;
        case 12:c='C';break;
    }
    return c;
}
string translate(int x){
    string s="";
    s+=getBit(x/13);
    s+=getBit(x%13);
    return s;
}
int main(int argc, char const *argv[])
{
    int r,g,b;
    cin>>r>>g>>b;
    cout<<"#";
    cout<<translate(r)<<translate(g)<<translate(b);
    return 0;
}
