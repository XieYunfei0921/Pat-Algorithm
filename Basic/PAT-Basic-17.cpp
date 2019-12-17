#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

void show(string s,int start,int end){
    for (int i = start; i <= end; i++)
    {
        cout<<s[i];
    }
    
}

void inverse(string s){
    int end=s.length()-1;
    int start=s.length()-1;
    while (start>=0)
    {
        if(s[start]==' '){
            show(s,start+1,end);
            end=start-1;
            start=end;
            cout<<" ";
        }
        start--;
    }
    show(s,beginIndex+1,end);
}
int main(int argc, char const *argv[])
{   
    string s;
    getline(cin,s);
    inverse(s);
    return 0;
}
