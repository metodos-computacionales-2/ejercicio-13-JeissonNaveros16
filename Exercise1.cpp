#include <iostream>
int subtraction(int a, int b)
{
    int r;
    r=a-b;
    return r;
}

int main(void)
{
    int x=5,y=3,z;
    z=subtraction(7,2);
    std::cout<< "The first result is " <<z<<"\n";
    std::cout<< "The second result is " <<subtraction(7,2)<<"\n";
    std::cout<< "The third result is " <<subtraction(x,y)<<"\n";
    z=4+subtraction(x,y);
    std::cout<< "The fourth result is " <<z<<"\n";
    
    std::cout<< "The memory address to variable x is " <<&x<<"\n";
    std::cout<< "The memory address to variable y is " <<&y<<"\n";
    std::cout<< "The memory address to variable z is " <<&z<<"\n";
    return 0;
}