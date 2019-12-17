#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
int hash[10];
const int CLK_TCK=100;
/*
    注意:
        1. 输入位数最大有1000位,long long 类型不能容纳,所以采用字符串
        2. 测评系统上,最好不要使用hash之类的关键词
*/

void caculate(string s){
    for (int i = s.length()-1; i >=0; i--)
    {   
        int temp=s[i]-'0';
        hash[temp]+=1;
    }
    
}
void show(){
    for (int i = 0; i < 10; i++)
    {
        if(hash[i]!=0)
            std::cout << i<<":"<<hash[i] << std::endl;
    }
}

/*
    注意当c1-c2相差最多只有不到28h
    进行运算时最后不要带入浮点数运算,要不然会引起精度误差造成的错误,难以排查
*/

void caculateTime(int c1,int c2){
    int ctime=(c2-c1+50)/100;
    int hour=ctime/3600;
    int minu=ctime%3600/60;
    int sec=ctime%60;
    if(hour<10)
        cout<<0<<hour<<":";
    else
        cout<<hour<<":";

    if(minu<10)
        cout<<0<<minu<<":";
    else
        cout<<minu<<":";

    if(sec<10)
        cout<<0<<sec<<"\n";
    else
        cout<<sec<<"\n";
}
int rate[17]={7,9,10,5,8,4,2,1,6,3,7,9,10,5,8,4,2};
char zsearch[11]={'1','0','X','9','8','7','6','5','4','3','2'};

vector<string> vs;

bool idCheckNum(string s){
    int sum=0;
    for (int i = 0; i < 17; i++)
    {   
        if(s[i]-'0'>9 ||s[i]-'0'<0){
            vs.push_back(s);
            return false;
        }
        sum+=(s[i]-'0')*rate[i];
    }
    if(zsearch[sum%11]!=s[17]){
        vs.push_back(s);
        return false;
    }
    return true;
}

int main(int argc, char const *argv[])
{   
    // int c1,c2;
    // cin>>c1>>c2;
    // caculateTime(c1,c2);

    // 省份证检测测试
    int n;
    bool flag=true;
    cin>>n;
    string s[100];
    for (int i = 0; i < n; i++)
    {
        cin>>s[i];
    }

    for (int i = 0; i < n; i++)
    {
        flag&=idCheckNum(s[i]);
    }
    if(flag){
        std::cout << "All passed" << std::endl;
    }else{
        for (int i = 0; i < vs.size(); i++)
        {
            std::cout << vs[i] << std::endl;
        }
    }

    
    return 0;
}
