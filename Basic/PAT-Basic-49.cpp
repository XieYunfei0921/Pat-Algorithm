#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    string s;
    vector<vector<string> > v;
    for (int i = 0; i < 3; i++)
    {
        getline(cin,s);
        int start=0,end=0;
        for (int j = 0; j < s.length(); j++)
        {   
            if(s[j]='[') {start=j;continue;}
            if(s[j]=']'){
                end=j;
                v[i].push_back(s.substr(start,end-start+1));
                start=end+1;end++;
            }
        }
    }
    for (int i = 0; i < 3; i++)
    {   
        cout<<v[i].size()<<"\t";
        for (int k = 0; k < v[i].size(); k++)
        {
            cout<<v[i][k]<<"\t";
        }
        
    }
        

    return 0;
}
