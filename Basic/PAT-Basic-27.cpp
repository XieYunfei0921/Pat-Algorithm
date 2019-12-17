#include <iostream>
#include <queue>
using namespace std;
int main(int argc, char const *argv[])
{
    int a;
    queue<int> zer;
    priority_queue<int,vector<int>,greater<int> > pos;
    for (int i = 0; i < 10; i++)
    {
        cin>>a;
        if(i==0){
            for (int j = 0; j < a; j++)
                zer.push(0);
        }
        else
        {
            for (int j = 0; j < a; j++)
            {
                pos.push(i);
            }
        }
    }
    cout<<pos.top();
    pos.pop();
    while (!zer.empty())
    {
        cout<<zer.front();
        zer.pop();
    }
    while (!pos.empty())
    {
        cout<<pos.top();
        pos.pop();
    }
    return 0;
}
