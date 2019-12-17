#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
// P<<MOD否则0-MOD内重复元素过多
const int MOD=1000000007;
const int P=1000019;

struct Substr{
    long long hash;
    int len;
};
const int MAXN=1000;
vector<Substr> vs1,vs2;
long long powP[MAXN];
long long H1[MAXN];
long long H2[MAXN];
long long hashFunc(string s){
    long long h=0;
    for (int i = 0; i < s.length(); i++)
    {   
        // H(x)=[H(x-1)*26+value(s[i])]%MOD
        h=(h*P+s[i]-'a')%MOD;
    }
    return h;
}

void powerCaculate(int n){
    powP[0]=1;
    for (int i = 1; i < n; i++)
    {
        powP[i]=powP[i-1]*P%MOD;
    }
}

long long caculateStringHash(string &s,long long H[]){
    H[0]=s[0];
    for (int i = 1; i < s.length(); i++)
    {
        H[i]=(H[i-1]*P+s[i])%MOD;
    }
    return 1;
}

long long calulateSubstring(long long H[],int j,int i){
    if(i==0) return H[j];
    return ((H[j]-H[i-1]*powP[j-i+1])%MOD+MOD)%MOD;
}

void caculateSubHash(long long H[],int len,vector<Substr> &vs){
    for (int i = 0; i < len; i++)
    {
        for (int j = i; j < len; j++)
        {   
            long long hashNum=calulateSubstring(H,j,i);
            Substr s={hashNum,j-i+1};
            vs.push_back(s);
        }
    }
}

int getMaxLength(vector<Substr> vs1,vector<Substr> vs2){
    int ans=0;
    for (int i = 0; i < vs1.size(); i++)
    {
        for (int j = 0; j < vs2.size(); j++)
        {
            if(vs1[i].hash==vs2[j].hash){
                ans=max(ans,vs1[i].len);
            }
        }
    }
    return ans;
}


int main(int argc, char const *argv[])
{   
    string s1="Sandee";
    string s2="sisandesa";
    powerCaculate(max(s1.length(),s2.length()));
    caculateStringHash(s1,H1);
    caculateStringHash(s2,H2);
    caculateSubHash(H1,s1.length(),vs1);
    caculateSubHash(H2,s2.length(),vs2);
    std::cout << "Max = "<<getMaxLength(vs1,vs2) << std::endl;
    return 0;
}
