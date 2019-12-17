#include <iostream>
#include <algorithm>
#include <string>
#include <queue>
#include <sstream>
using namespace std;

struct Student{
    string name;
    string num;
    int score;
    void show(){
        std::cout << this->name<<" "<<this->num << std::endl;
    }
};
bool cmp(Student s1,Student s2){
    return s1.score>s2.score;
}
Student translate(string s){
    // 字符串分割
    vector<string> st;
    string para;
    Student stu;
    istringstream iss(s);
    while (getline(iss,para,' '))
    {
        st.push_back(para);
    }
    stu.name=st[0];
    stu.num=st[1];

    stu.score=atoi(st[2].c_str());
    return stu;
}

int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    cin.ignore();
    // 考虑使用优先队列
    Student s[n];
    string info[n];
    queue<Student> q;
    // cin.get(info,n);
    for (int i = 1; i < n; i++)
    {
        getline(cin,info[i]);
    }
    std::cout << "---------" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cout <<"Input:" <<info[i] << std::endl;
        // s[i]=translate(info[i]);
    }
    
    sort(s,s+n,cmp);
    for (int i = 0; i < n; i++)
    {
        q.push(s[i]);
    }
    q.back().show();
    q.front().show(); 
    return 0;
}
