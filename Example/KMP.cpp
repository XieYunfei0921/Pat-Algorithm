#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
using namespace std;
const int MAXN=10010;
int next[MAXN];
void getNext(string s){
    int len=s.length();
    next[0]=-1;
    int j=-1;
    /*
        计算扩展递推式
        next[j+1]=s[next[j]+1]
        失配处理
        j=next[i]
    */
   for (int i = 1; i < len; i++)
   {    
       while (j != -1 && s[i] != s[j+1])
       {
           j=next[j];
       }
       if (s[i] == s[j+1])
       {
           j++;
       }
           next[i]=j;
   }
}

int KMP(string text,string pattern){
    // 之前pattern的next数组已经生成完毕 next在这里仅供查询
    int tlen=text.length();
    int plen=pattern.length();
    int j=-1;
    next[0]=-1;
    int ans=0;
    for (int i = 0; i < tlen; i++)
    {   
        while (j!=-1 && text[i]!=pattern[j+1])
        {
            j=next[j];
        }
        if (text[i]==pattern[j+1])
        {
            j++;
        }
        if (j==plen-1)
        {
            ans+=1;
            j=next[j];
        }
    }
    return ans;   
}

int main(int argc, char const *argv[])
{

    getNext("ab");
    int ans=KMP("abbababaab","av");
    std::cout << "ans= "<<ans << std::endl;
    for (int i = 0; i < 3; i++)
    {
        cout<<next[i]<<" ";
    }
    
    return 0;
}

