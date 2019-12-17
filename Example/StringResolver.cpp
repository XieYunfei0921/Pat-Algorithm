#include <iostream>
#include <math.h>
#include <string>
using namespace std;

// 字符串处理
// 需要注意一些细节以及边界情况

// 注意自己控制台输入的字符串一般情况下后面有\n
// 程序中的也有EOF结尾标志符
bool backString(string str){

    bool flag=1;
    string::iterator i = str.begin();
    string::iterator j=str.end()-1;
    for (; i !=str.end() && j !=str.begin(); i++,j--)
    {
        if (*i != *j)
        {
            flag=0;
            break;
        }
        
    }
    return flag;
}

// 反转字符串
/*
    ,,hb 
*/
string reverseWord(string str){
    return "";
}

int main(int argc, char const *argv[])
{   
    string str;
    cin>>str;
    std::cout <<backString(str)<< std::endl;

    return 0;
}
