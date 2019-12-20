    #include <iostream>
    using namespace std;
    int main(int argc, char const *argv[]){
        string s;
        cin>>s;
        int len=s.length();
        int cnt=0;
        int totalT=0;
        int sumP[len],sumT[len];
        sumP[0]=sumT[0]=0;
        if(s[0]=='P') sumP[0]++;
        if(s[0]=='T') {sumT[0]++;totalT++;}
        for (int i = 1; i < len; i++){
            if(s[i]=='P') sumP[i]=sumP[i-1]+1;
            else sumP[i]=sumP[i-1];
            if(s[i]=='T'){sumT[i]=sumT[i-1]+1;totalT++;}
            else sumT[i]=sumT[i-1];
        }
        for (int i = 0; i < len; i++)
            if(s[i]=='A') cnt=(cnt+sumP[i]*(totalT-sumT[i])%1000000007)%1000000007;
        cout<<cnt;
        return 0;
    }
