#include <iostream>
#include <algorithm>
#include <math.h>
#include <stdio.h>
using namespace std;

int main(int argc, char const *argv[])
{
    int t,k,n1,n2,b,x;
    cin>>t>>k;
    for (int i = 0; i < k; i++)
    {
        cin>>n1>>b>>x>>n2;
        if(x>t){
            printf("Not enough tokens.  Total = %d.\n", t);
            continue;
        }

        if((n1>n2 && b==0) || (n1<n2 && b==1)){
            t+=x;
            printf("Win %d!  Total = %d.\n", x, t);
        }else
        {
            t-=x;
            printf("Lose %d.  Total = %d.\n", x, t);
            if(t==0){
                printf("Game Over.\n");
                break;
            }
        }
    }

}