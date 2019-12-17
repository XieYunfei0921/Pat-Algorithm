#include <iostream>
#include <algorithm>
using namespace std;
int getResult(string s){
    return 0;
}
int main(int argc, char const *argv[])
{
    int n,m,k;
    cin>>n>>m;
    string pos[m];
    int score[m];
    double totalScore[n];
    // 录入题目信息
    for (int i = 0; i < m; i++)
    {
        int val,total,correct;
        cin>>val>>total>>correct;
        string temp="";
        for (int i = 0; i < correct; i++)
        {
            string opt;
            cin>>opt;
            temp+=opt;
            temp+=" ";
        }
        score[i]=val;
        pos[i]=temp.substr(0,temp.length()-1);
        temp.clear();
    }
    cin.ignore();
    // 录入学生信息并计分
    for (int i = 0; i < n; i++)
    {
        string input;
        getline(cin,input);
        int start=input.find("(")+3;
        int end=input.find(")")-1;
        int value=0;
        for (int j = 0; j < m; j++)
        {
            if(input.substr(start,end-start+1)==pos[i])
                value+=score[j];
            input=input.substr(end+1,input.length()-end);
            start=input.find("(")+3;
            end=input.find(")")-1;
        }
        totalScore[i]+=value;
    }
    return 0;
}
