#include <iostream>
//int getMaxInt(int a, int b)
//{
//    if(a < b)
//        return b;
//    else
//        return a;
//}

//double getMaxDouble(double a, double b)
//{
//    if(a < b)
//        return b;
//    else
//        return a;
//}

int getMax(int a, int b)
{
    if(a < b)
        return b;
    else
        return a;
}

double getMax(double a, double b)
{
    if(a < b)
        return b;
    else
        return a;
}

int main(void)
{
    int x=5,y=2;
    double n=5.0,m=2.0;
    //std::cout<< getMaxInt(x,y)<<"\n";
    //std::cout<< getMaxDouble(n,m)<<"\n";
    
    std::cout<< getMax(x,y)<<"\n";
    std::cout<< getMax(n,m)<<"\n";
    return 0;
}