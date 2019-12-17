#include <iostream>
using namespace std;
int main(int argc, char const *argv[])
{
    int n;
    cin>>n;
    string name,birth,youngName,oldName;
    int cnt=0;;
    string oldbirth="2014/09/06";string youngbirth="1814/09/06";
    for (int i = 0; i < n; i++)
    {
        cin>>name>>birth;
        if(birth<="2014/09/06" && birth>="1814/09/06"){
            cnt++;
            if(oldbirth>birth) {oldbirth=birth;oldName=name;}
            if(youngbirth<birth) {youngbirth=birth;youngName=name;}
        }
    }
    if(cnt==0) cout<<cnt;
    else std::cout << cnt<<" "<<oldName<<" "<<youngName << std::endl;
    return 0;
}
