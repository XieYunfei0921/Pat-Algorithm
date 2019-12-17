#include <iostream>
#include <string>
using namespace std;

void draw(int len,char c){
    // 一行一行打印
    int line=2*(len%2==0?len/2:len/2+1)-1;
    std::cout << "Line= "<<line << std::endl;
    for (int i = 0; i < line; i++)
    {
        if(i==0 || i==line-1){
            for (int j = 0; j < len; j++)
            {
                cout<<c;
            }
            continue;
        } 
        
        if(i%2==0 || line<4){
            for (int j = 0; j <= line; j++)
            {   
                if(j==0 || j==len-1)
                    cout<<c;
                else 
                    cout<<" ";
            }
            continue;
        }
        std::cout  << std::endl;
    }
}

int main(int argc, char const *argv[])
{   
    draw(8,'a');
    return 0;
}
