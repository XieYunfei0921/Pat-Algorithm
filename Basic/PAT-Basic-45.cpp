#include <iostream>
#include <string>
using namespace std;
int main(int argc, char const *argv[])
{
    int n,index=-1,cnt=0;string s,low,up;
    string lower[13]={"tret","jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
    string higher[12]={"tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};
    cin>>n;
    cin.ignore();
    for (int i = 0; i < n; i++)
    {
        getline(cin,s);
        cnt=0;
        if(s[0]<='9' && s[0]>='0'){
            for (int i = 0; i <s.length(); i++)
                cnt=cnt*10+s[i]-'0';
            if(cnt==0) {cout<<"tret"<<"\n";continue;}
            string kai=cnt/13-1<0?"":higher[cnt/13-1];
            if(cnt%13!=0 && cnt>13) kai.append(" ").append(lower[cnt%13]);
            if(cnt<13) kai.append(lower[cnt%13]);
            cout<<kai;
        }else
        {   
            if(s.find(" ")!=string::npos){
                up=s.substr(0,3);
                low=s.substr(4,s.length());
                for (int i = 0; i < 13; i++)
                    if(low==lower[i]) {index=i;break;}
                for (int i = 0; i < 12; i++)
                    if(up==higher[i]) {index=(i+1)*13+index;break;}
                cout<<index;
            }else{
                for (int i = 0; i < 13; i++)
                    if(s==lower[i]) {cout<<i;continue;}
                for (int i = 0; i < 12; i++)
                    if(s==higher[i]) {cout<<(i+1)*13;continue;}   
            }
        }
        cout<<"\n";
    }
    return 0;
}
