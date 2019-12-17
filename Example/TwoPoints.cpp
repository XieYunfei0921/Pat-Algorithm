#include <iostream>
#include <math.h>
#include <algorithm>

using namespace std;

/*双指针法
    基于递增/减的序列
*/
void doublePoint(int* arr,int len,int m){
    
    int i=0,j=len;
    while (i<j)
    {
        if (*(arr+i)+*(arr+j)==m)
        {
            std::cout << "m= "<<*(arr+i)<<" + "<<*(arr+j) << std::endl;
            i++;
            j--;
        }else if (*(arr+i)+*(arr+j)>m)
        {
            j--;
        }else{
            i++;
        }
        
    }
}

int main(int argc, char const *argv[])
{
    int a[10]={1,3,4,6,7,3,-2,9,4,5};
    doublePoint(a,10,7);
    return 0;
}
