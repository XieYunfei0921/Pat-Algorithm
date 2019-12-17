#include <iostream>
#include <math.h>
#include <string>
using namespace std;

void drawSquare(int num,char c){
    // 列为Num个,行为num/2 (四舍五入)
    int line;
    if (!num%2)
    {
        line=(num+1)/2;
    }else
    {
        line=num/2;
    }


    for (int i = 0; i < line; i++)
    {
        // 打印边缘
        if (i==0 || i==(line-1))
        {
            for (int i = 0; i < num; i++)
            {
                std::cout << c;
            }
            
        }else
        {
            for (int i = 0; i < num; i++)
            {
                if (i==0 || i==(num-1))
                {
                    std::cout << c ;
                }else
                {
                    std::cout << " ";
                }
                
                
            }
            
        }

        std::cout << std::endl;
        
        
        
    }
    
}

int main(int argc, char const *argv[])
{
    drawSquare(10,'x');

    return 0;
}
