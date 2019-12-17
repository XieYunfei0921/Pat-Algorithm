#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int tab[6];
void put(char c){
    switch (c)
    {
        case 'P':tab[0]+=1;break;
        case 'A':tab[1]+=1;break;
        case 'T':tab[2]+=1;break;
        case 'e':tab[3]+=1;break;
        case 's':tab[4]+=1;break;
        case 't':tab[5]+=1;break;
    }
}
char getWord(int index){
    char c;
    switch (index)
    {
        case 0:c='P';break;
        case 1:c='A';break;
        case 2:c='T';break;
        case 3:c='e';break;
        case 4:c='s';break;
        case 5:c='t';break;
    }
    return c;
}
int main(int argc, char const *argv[])
{
    string s;
    cin>>s;
    for (int i = 0; i < s.length(); i++)
        put(s[i]);
    int index=0;
    bool size=0;
    do
    {
        size=0;
        for (int i = 0; i < 6; i++)
        {
            if(tab[i]!=0) {cout<<getWord(i);tab[i]-=1;size++;}
        }
    } while (size!=0);
    return 0;
}
